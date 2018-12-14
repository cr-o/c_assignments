#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main(void){
	char cwd[1024]; //create the path with temp.XXXXXX at the end
	char *temp_filename;
	char *suffix = "/temp.XXXXXX";
	char bar = '|';
	char newline = '\n';
	char *print = "---------------------\n";
	time_t t;
	struct tm *tm;
	char str_time[100];
	char str_date[100];
	if(getcwd(cwd, sizeof(cwd)) !=NULL){
		printf("Current working directory: %s\n", cwd);
	}else{
		perror("error");
	}
	strcat(cwd, suffix); 
	temp_filename=mktemp(cwd);
	printf("temp_filename=%s\n", temp_filename);
	int fd=creat(temp_filename, 00700);
	printf("Using mktemp(): fd=%d\n", fd);
	FILE *pFILE = fdopen(fd, "a");
	printf("---------------------------------------------------------\n");
    write(fd, print, strlen(print));
	
	t = time(NULL);
	tm = localtime(&t);
	strftime(str_time, sizeof(str_time), "%H %M %S", tm);
	strftime(str_date, sizeof(str_date), "%m %d %Y", tm);

	while(1){ //keep outputting time and date until user exits.
		sleep(3600); //change to 3600 for hour
		t = time(NULL);
		tm = localtime(&t);
		strftime(str_time, sizeof(str_time), "%H %M %S", tm);
		strftime(str_date, sizeof(str_date), "%m %d %Y", tm);
        write(fd, &bar, 1);
        write(fd, str_time, strlen(str_time));
        write(fd, &bar, 1);
        write(fd, str_date, strlen(str_date));
        write(fd, &bar, 1);
        write(fd, &newline, 1);
		printf("|\t%s\t\t|\t%s\t|\n", str_time, str_date);
	}
	printf("---------------------------------------------------------\n");
    write(fd, print, strlen(print));
	
	return 0;
	
	
}