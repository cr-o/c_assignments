/*Write a simple program showing the system call sigsuspend(). 
Your program should initialize three sets of signals (oldset, newset, waitset) to the empty set, using sigemptyset(). 

It should then add a few signals to this set, using sigaddset(). 

It should contain a signal handler, which you can design to be shared across the few signals you have added to your set. 

You should then specify a set of blocked signals, using sigprocmask(). 

The signals you want triggered and handled, you should set, and establish handler(s) for, using either signal() or sigaction(). 

Then, you want these signals in the blocked mask to be released after your critical code, using sigsuspend(). 

In addition, you can make your critical code deliver a different signal set, defined as a wait set. 
Have each delivered signal leave a “footprint” in a text file.
*/
#include <stdio.h> /* for printf() */
#include <signal.h> /* for signal() */
#include <string.h> /* for strlen() */
#include <stdlib.h> /* for calloc() */
#include <unistd.h> /* for sleep() */
#include <fcntl.h> /* for open() */
#include<sys/time.h>
sigset_t *oldset, *newset, *waitset;
FILE *fp;
void handler(int signo);
void printSigset(sigset_t *set);
void criticalCode(void);
int main(int argc, char*argv[]){
	oldset = malloc(sizeof(sigset_t));
	newset = malloc(sizeof(sigset_t));
	waitset = malloc(sizeof(sigset_t));
	signal(SIGALRM, handler);
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	sigemptyset(oldset);
	sigemptyset(newset);
	sigemptyset(waitset);
	fp = fopen("filesignals.txt", "w+");
	sigaddset(oldset, SIGINT);
	printf("Printing oldset: \n");
	printSigset(oldset);
	printf("\n");
	
	sigaddset(newset, SIGALRM);
	printf("Printing newset before procmask: \n");
	printSigset(newset);
	printf("\n");
	
	printf("Sigprocmask.\n");
	sigprocmask(SIG_BLOCK, newset, oldset);
	printf("\n");
	
	printf("Printing oldset: \n");
	printSigset(oldset);
	printf("\n");
	
	printf("Printing newset: \n");
	printSigset(newset);
	printf("\n");
	
	// printf("Printing newset after proc and adding another signal: \n");
	// sigaddset(newset, SIGQUIT);
	// printSigset(newset);
	// printf("\n");
	
	printf("Printing waitset: \n");
	printSigset(waitset);
	printf("\n");
	
	criticalCode();  //set off its own unique signals
	printf("Suspending. Ctrl C to exit. \n");
	while(1){
		sigsuspend(oldset);
		break;
	}
	
	printf("Finished critical code.\n");
	printf("\n");
	printf("Printing oldset: \n");
	printSigset(oldset);
	printf("\n");
	
	printf("Unblocking.\n");
	sigprocmask(SIG_UNBLOCK, newset, NULL);
	printf("Printing oldset: \n");
	printSigset(oldset);
	printf("\n");
	
	printf("Printing newset: \n");
	printSigset(newset);
	printf("\n");
	
	printf("Printing waitset: \n");
	printSigset(waitset);
	printf("\n");
	fclose(fp);
	return 0;
}

void printSigset(sigset_t *set){
	int i = 1;
	printf("------------\n");
	for (i=1; i<32; i++){
		if (sigismember(set, i)){
			printf("Signal %d: %s\n", i, strsignal(i));
		}
	}

	printf("------------\n");
}
void handler(int signo){
	//signal(SIGALRM, handler);
	switch(signo){
		case SIGALRM:
			printf("In handler1()...\n");
			printf("ACTION 1: Received SIGALRM.\n");
			fprintf(fp,"ACTION 1: Received SIGALRM.\n");
			break;
		case SIGINT:
			printf("In handler1()...\n");
			printf("ACTION 2: Received SIGINT.\n");
			fprintf(fp,"ACTION 2: Received SIGINT.\n");
			break;
		case SIGHUP:
			printf("In handler1()...\n");
			printf("ACTION 3: Received SIGHUP.\n");
			fprintf(fp, "ACTION 3: Received SIGHUP.\n");
			break;
		case SIGQUIT:
			printf("In handler1()...\n");
			printf("ACTION 4: Received SIGQUIT.\n");
			fprintf(fp, "ACTION 4: Received SIGQUIT.\n");
			break;
	}
}
void criticalCode(void){
	signal(SIGHUP, handler);
	sigaddset(waitset, SIGHUP);
	printf("In critical code.\n");
}		