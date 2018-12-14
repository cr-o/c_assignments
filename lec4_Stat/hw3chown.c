#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
	char buff[200];
	struct stat st;
	FILE *fp;
	int fd;
	fp = fopen("file.txt", "r");
	fd = fileno(fp);
	stat("books.txt", &st);
	printf("owner was %d and group was %d\n", st.st_uid, st.st_uid);
	if(chown("file.txt", 4, 0)!=0){
		perror("error");
	}
	else{
		stat("file.txt", &st);
		printf("now owner became %d and group is %d\n", st.st_uid, st.st_gid);
	}
	fclose(fp);
}