#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
int main (void){
	struct passwd * pwd;
	for (long i = 0; i < 1000; i++){ //ignore nobody
		pwd = getpwuid(i);
		if(pwd != NULL){
			printf("UID is: %u\n", pwd->pw_uid);
			printf("User is: %s\n", pwd->pw_name);
		}
	}
}