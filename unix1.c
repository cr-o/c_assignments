#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	ssize_t write_bytes;
	if (argc < 2){
		printf("enter a name"); 
	}else{
		char name[128];
		*name = 0;
		strcat(name, argv[1]);
		for (int i = 2; i < argc; i++){ //concatenate input with whitespace in btwn
			strcat(name, " ");
			strcat(name, argv[i]);
		}
		write_bytes = strlen(name);
		int fd = creat(name, 00700);
		if (fd == -1){
			printf("error creating file");
		}else{
			write(fd, name, write_bytes);
			printf("file created for %s", name);
			close(fd);
		}
	}
	return 0;
}