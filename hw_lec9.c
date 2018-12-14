#include <stdio.h>
#include <setjmp.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
void WriteName(char* entry);
char *TestCorrect(char* name);
int main(int argc, char** argv){
	jmp_buf array;
	char *myname; 
	printf("Enter name (Correct entry is Cherin Oh): ");
	char *line=malloc(20*sizeof(char));
	myname=fgets(line, 20, stdin);
	int len=strlen(myname);
	if (myname[len-1]=='\n'){
		myname[len-1]='\0';
	}
	printf("You entered: %s\n", myname);
	int ret = setjmp(array);  //ret or setjump return value is 0 if invoked directly
	printf("This is the value of ret: %d\n", ret); //ret is val of longjmp if longjmp is invoked
	printf("Going to write: %s\n", myname);
	WriteName(myname);
	if (ret == 0){
		myname=TestCorrect(myname);
		printf("IN IF: This is myname now: %s\n", myname); //direct
		longjmp(array, 1);
	}
	else{
		printf("IN ELSE: This is myname now: %s\n", myname); //longjmp
	}
	return 0;
}
void WriteName(char *entry){
	FILE *fp;
	fp=fopen("outfile.txt", "w+");
	fseek(fp, 0, SEEK_SET);
	if (fp != NULL){
		fputs(entry, fp);
	    fclose(fp);
	}
}
char *TestCorrect(char* name){
	char *result = name;
	int ret;
	if (strncmp(result, "Cherin Oh", 20) ==0){
		printf("name is spelled correctly\n");
	}
	else{
		printf("name is spelled incorrectly\n");
		result= "Cherin Oh (replaced)";
	}
	return result;
}