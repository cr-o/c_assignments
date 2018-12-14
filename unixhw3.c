#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long long octConvert(long long octal);
long decConvert(long num);
#define S_IFMT      0170000
#define S_ISVTX     0001000
#define S_ISUID    0004000   
#define S_ISGID    0002000
int main(int argc, char* argv[]){
	struct stat buf;
	char buffer[100];
	stat("file.txt", &buf);
	printf("-\n");
	printf("st_mode in octal= %o\n", buf.st_mode);
	long number = buf.st_mode;
	long remainder;
	long base = 1;
	long bin = 0;
	long num_ones = 0;
	//convert to binary
	while (number >0){
		remainder = number %2;
		if (remainder ==1){
			num_ones ++;
		}
		bin = bin + remainder * base;
		number = number /2;
		base = base * 10;	
	}
	printf("converted binary is %ld\n", bin);
	printf("st_ino = %llo\n", buf.st_ino);
	printf("st_dev = %o\n", buf.st_dev);
	printf("st_rdev = %o\n", buf.st_rdev);
	printf("st_nlink = %o\n", buf.st_nlink);
	printf("st_uid = %o\n", buf.st_uid);
	printf("st_gid = %o\n", buf.st_gid);
	printf("st_size = %llo\n", buf.st_size);
	printf("st_atime = %lo\n", buf.st_atime);
	printf("st_mtime = %lo\n", buf.st_mtime);
	printf("st_ctime = %lo\n", buf.st_ctime);
	printf("st_blksize = %o\n", buf.st_blksize);
	printf("st_blocks = %llo\n", buf.st_blocks);
	
	printf("\n");

	printf("buf.st_mode & S_IRWXU=%o\n", buf.st_mode & S_IRWXU);
	// printf("all 9 permission bits=%o\n", (buf.st_mode & S_IRWXU) | (buf.st_mode & S_IRWXG) | (buf.st_mode & S_IRWXO));
	int bits = (buf.st_mode & S_IRWXU) | (buf.st_mode & S_IRWXG) | (buf.st_mode & S_IRWXO);
	bits = decConvert(bits);
	printf("buf.st_mode & S_IRWXG=%o\n", buf.st_mode & S_IRWXG);
	printf("buf.st_mode & S_IRWXO=%o\n", buf.st_mode & S_IRWXO);
	printf("buf.st_mode | & all=%o\n", (buf.st_mode & S_IFMT) | (buf.st_mode & S_ISVTX) | (buf.st_mode & S_ISUID) | (buf.st_mode & S_ISGID) | (buf.st_mode & S_IRWXU) | (buf.st_mode & S_IRWXG) | (buf.st_mode & S_IRWXO));
	printf("\n");
	if ((buf.st_mode & S_IFMT) == 24576){ // 60000
		printf ("IFBLK: block revice\n");
	}else if ((buf.st_mode & S_IFMT) == 8192){ //20000
		printf ("IFCHR: character device\n");
	}else if ((buf.st_mode & S_IFMT) == 16384){ //40000
		printf ("IFDIR: directory\n");
	}else if ((buf.st_mode & S_IFMT) == 4096){ //10000
		printf ("IFIFO: FIFO\n");
	}
	else if ((buf.st_mode & S_IFMT) == 32768){ //100000
		printf ("IFREG: regular file type\n");
	}
	else if ((buf.st_mode & S_IFMT) == 40960){ //120000
		printf ("IFLINK: symbolic link\n");
	}
	else if ((buf.st_mode & S_IFMT) == 49152){ //140000
		printf ("IFSOCK: socket\n");
	}
	printf("buf.st_mode & S_ISVTX=%o\n", buf.st_mode & S_ISVTX);
	if ((buf.st_mode & S_ISVTX) == 0){
		printf("sticky bit not set.\n");
	}else{
		printf("sticky bit set\n");
	}
	printf("buf.st_mode & S_ISUID=%o\n", buf.st_mode & S_ISUID);
	if ((buf.st_mode & S_ISUID) == 0){
		printf("user ID bit not set.\n");
	}else{
		printf("user ID bit set\n");
	}
	printf("buf.st_mode & S_ISGID=%o\n", buf.st_mode & S_ISGID);
	if ((buf.st_mode & S_ISGID) == 0){
		printf("group ID bit not set.\n");
	}else{
		printf("group ID bit set\n");
	}
    char permbits[10];
	sprintf(permbits, "%d", bits);
	char finperm[10];
	
	for (int i = 0; i < 9; i++){
		if ((i %3 == 0) && (permbits[i] == '1')){
			finperm[i] = 'r';
		}if ((i %3 ==1) && (permbits[i] == '1')){
			finperm[i] = 'w';
		}if ((i %3 ==2) && (permbits[i] == '1')){
			finperm[i] = 'x';
		}else if (permbits[i] == '0'){
			finperm[i] = '-';
		}
	 }
	printf("\n");
	printf("permissions: %s \n", finperm);

}

long long octConvert(long long octal){
	long long dec = 0;
	long long bin = 0;
	long long iter = 0;
	while(octal != 0){
		dec = dec + (octal%10) * pow(8, iter);
		++iter;
		octal = octal/10;
	}
	iter = 1;
	while(dec !=0){
		bin += (dec % 2) * iter;
		dec/=2;
		iter*= 10;
	}
	return bin;
}
long decConvert(long number){
	long remainder;
	long base = 1;
	long bin = 0;
	long num_ones = 0;
	//convert to binary
	while (number >0){
		remainder = number %2;
		if (remainder ==1){
			num_ones ++;
		}
		bin = bin + remainder * base;
		number = number /2;
		base = base * 10;	
	}
	return bin;
}