#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFSIZE 4096

int main(int argc, char *argv[]){
	char buf[BUFFSIZE];
	if (argc < 2){
		printf("enter a source and target");
	}else{
	char *source = argv[1];
	char *target = argv[2];
	//get fd of source
	int fd1= open(source, O_RDWR);
	
	if (fd1 == -1){
		printf("source file not valid");
		exit(0);
	}
	//get fd of destination
	int fd2= creat(target, 00700);
	int n;
	while ((n=read(fd1, buf, BUFFSIZE))>0){
		if (write(fd2, buf, n)!=n)
			printf("write error\n");
	}
	if (n<0)
		printf("read error\n");
	exit(0);
}
	
}