#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int getBytePosition(int row, int filedes);
void putChar(int filedes, char *c, off_t byte);
void copyConverter(int filedes, char ch[]);
char newline = '\n';
char print = ' ';
char copy[800];
int start;
int main(int argc, char *argv[]){ // ./unixhw2.c replace/insert row# bookname authorname
	off_t curr_byte;
	ssize_t num_bytes;
	FILE *fp;
	int fd, diff;
	char buf[400];
	char *r = "replace";
	char *i = "insert";
	int row  = strtol(argv[2], NULL, 10);
	printf("row passed is %d \n", row);
	if (argc != 5){
		printf("Enter replace or insert, row number, any book, and author\n");
		exit(0);
	}
	fp = fopen("books.txt", "r+");
	fd = fileno(fp);
	curr_byte = lseek(fd, 0, SEEK_CUR);
	printf("Cursor is at the %lldth byte. \n", curr_byte);
	num_bytes = lseek(fd, 0, SEEK_END);
	printf("File has %zd bytes. \n", num_bytes);
	curr_byte = lseek(fd, 0, SEEK_SET);
	printf("Cursor set to %lldth byte \n", curr_byte);
	ssize_t read_bytes=read(fd, buf, num_bytes);
    ssize_t written_bytes=write(1, buf, read_bytes);
	printf("\n");
	if (strcasecmp(argv[1], r) == 0){ //entered replace
		off_t b = (off_t)getBytePosition(row, fd);
		printf("getbyteposition result is%lld \n", b);
		putChar(fd, argv[3], b);
		b +=  strlen(argv[3]);
		putChar(fd, &print, b); //whitespace in between
		putChar(fd, argv[4], b+1);
	}else if (strcasecmp(argv[1], i) == 0){ //entered insert--can not insert into existing row, must replace instead
		off_t b = (off_t)getBytePosition(row, fd); 
		printf("getbyteposition result is %lld \n", b);

		if (b > num_bytes){
			diff = b - num_bytes; //use to add newlines
			b = num_bytes;//gets rid of the <NUL>s that otherwide gets created from expanded char arr size
			for (int i = 0; i < diff; i++){ 
				putChar(fd, &newline, b);
				b++;//increase arr size again to place new input at the bottom of newlines
			}
		}
		putChar(fd, argv[3], b);
		b +=  strlen(argv[3]);
		putChar(fd, &print, b); //whitespace in between
		putChar(fd, argv[4], b+1);
		copyConverter(fd, copy);
	}else{
		printf("Second argument should be replace or insert. \n");
		exit(0);
	}
	fclose (fp);
	return 0;	
}
/* Returns the byte # at the beginning of specified row # */
int getBytePosition(int row, int filedes){
	printf("In getBytePosition()...\n");
	char buf[400];
	int i;
	/* Find the total number of bytes in file */
	ssize_t num_bytes=lseek(filedes, 0, SEEK_END);
	printf("num_bytes=%zd\n", num_bytes);
	/* IMPORTANT! Bring cursor back to BOF */
	lseek(filedes, 0, SEEK_SET);
	ssize_t read_bytes=read(filedes, buf, num_bytes);
	printf("read_bytes=%zd\n", read_bytes);
	int num_rows=1;
	/* Loop goes through the number of bytes in the file */
	for (i=0; i<num_bytes; i++){
		printf("buf[%d]=%c\n", i, buf[i]);
	  if (num_rows==row){
		  printf("row within existing rows. byte no. of first char of that row is%d\n", i);

		  ssize_t copybytes = lseek(filedes, i, SEEK_SET);//copy all remaining data that comes after (from i to num_bytes)
	   	  read(filedes, copy, copybytes);
	   	  printf("this is i: %d\n", i);
	   	  printf("this is copybytes: %zd\n", copybytes);
	   	  for (start = 0; start < num_bytes-i; start++){
	                printf("copy[%d]=%c\n", start, copy[start]);
	  	  }
		  
		  return i;
	  }
		/* On EOL character, we increment the row # */
		if (buf[i]=='\n'){
			  printf("***EOL\n");
			  num_rows++;
			  printf("number of rows %d\n", num_rows);
			  /* If row # equals row specified, ret. byte # */

		 }
	}
	if (num_rows < row){//if inserting to a row past the last line of text
  	   printf("new row: new byte number: %d\n", i + (row-num_rows));	   
	   return i + (row-num_rows); //increase buf arr size accordingly
	} 
	return -1;
}
void putChar(int filedes, char *c, off_t byte){
	int status;
	lseek(filedes, byte, SEEK_SET);
	status = write(filedes, c, strlen(c));
	if(status<0){
		printf("Write failed\n");
	}
}
void copyConverter(int filedes, char ch[]){
	for (int i = 0; i < start; i++){
		printf("WRITING letter %c \n", ch[i]);
		write(filedes, &ch[i], 1);
	}
}