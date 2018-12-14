#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <sys/resource.h>
#include <sys/time.h>

void Input(int);
void PrintStatus(int status);
struct rusage usage;
int main(int argc, char *argv[]){
	int fd=open("file5.txt", O_CREAT|O_RDWR|O_APPEND, S_IRUSR|S_IWUSR);
    int ret, status;
    for (int n=0; n<3; n++){
		if ((ret=fork())==0){
              Input(fd);
              printf("Child process, ret=%d.\n", ret);
			  status = wait3(&status, 0, &usage);			 
              switch(n){
				  case 0:
		              exit(7);
                      break;
              	  case 1:
			   	      abort();
                      break;
              	  case 2:
			   	      status=status/0;
				      break;
			  }
	    }else{
			printf("Parent process, child ret==%d.\n", ret);
			wait3(&status, 0, &usage);								
	        PrintStatus(status);
	    }
	}
	getrusage(RUSAGE_SELF, &usage);
	return 0;
}
void Input(int filedes){
	char **name=calloc(3, 20*sizeof(char));
	char **it;
	name[0]="Adriana Wise\n";
	name[1]="Richard Stevens\n";
	name[2]="Evi Nemeth\n";
    for (it=&name[0]; *it!=NULL; it++){
		ssize_t num_bytes=write(filedes, *it, strlen(*it));
		sleep(2);
	}
}
void PrintStatus(int status){
	const char *s = "Signal description";
	int lower_8_bits;
	if ((lower_8_bits=WIFEXITED(status))==true){ //child process terminated normally with exit
		printf("WIFEXITED(status)=%d\n", WIFEXITED(status));
		psignal(WIFEXITED(status), s);
		printf("Exit status for child=%d\n", WEXITSTATUS(status)); //return exit status from child
		printf("lower_8_bits=%x\n", status);
	}else if (WIFSIGNALED(status)==true){ //received signal that was not handled
		printf("WIFSIGNALED(status)=%d\n", WIFSIGNALED(status));
		printf("Signal that terminated child=%d\n", WTERMSIG(status)); //return signal number of signal that terminated child
		psignal(WTERMSIG(status), s);
		printf("Coredump made= %d\n", WCOREDUMP(status)); //child terminated and produced core dump
	}else if (WIFSTOPPED(status)==true){ //child is stopped
		printf("WIFSTOPPED(status)=%d\n", WIFSTOPPED(status));
		printf("Exit status for child=%d\n", WSTOPSIG(status)); //return signal number of signal that terminated child
		psignal(WSTOPSIG(status), s);
	}
	printf("user time used: %ld.%06ld\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
	printf("system time used: %ld.%06ld\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
	printf("integral max resident set size: %ld\n", usage.ru_maxrss);
	printf("integral shared text memory size: %ld\n", usage.ru_ixrss);
	printf("integral unshared data size : %ld\n", usage.ru_idrss);
	printf("integral unshared stack size: %ld\n",usage.ru_isrss);
	printf("page reclaims: %ld\n", usage.ru_minflt);
	printf("page faults: %ld\n", usage.ru_majflt);
	printf("swaps: %ld", usage.ru_nswap);
	printf("block input operations: %ld\n", usage.ru_inblock);
	printf("block output operations: %ld\n", usage.ru_oublock);
	printf("messages sent: %ld\n", usage.ru_msgsnd);
	printf("messages received: %ld\n", usage.ru_msgrcv);
	printf("signals received: %ld\n", usage.ru_nsignals);
	printf("voluntary context switches: %ld\n", usage.ru_nvcsw);
	printf("involuntary context switches: %ld\n", usage.ru_nivcsw);
	printf("\n");
}