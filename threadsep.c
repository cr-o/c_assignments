/*	Write a program that starts two threads writing into
the same text file. The threads should be each reading book records from the
command line and populating the text file with these records.

Have each thread accumulate the record entries from the command line into an array of strings.
This should be the thread-specific data.
Both threads should independently update this array of strings with their input.
By using thread-specific data, the final array of
strings should be consistent and should contain complete entries from both threads.
For bonus: Have the data entry accept as many command line entries as issued
until an EOF character is encountered. Implement this as a signal.	*/
	
#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <malloc/malloc.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
int signo;
pthread_t t1, t2;
void *tret1, *tret2;
static pthread_key_t *key1;
static pthread_key_t *key2;
static pthread_once_t o1 = PTHREAD_ONCE_INIT;
pthread_mutex_t *lock;
char** lines; 
void *readInput(void *arg);	//start routine
void *readInput2(void *arg);	//start routine
void handler(int sigum);
void destructor(void *);
void thread_init1(void);
void thread_init2(void);
void thread_init3(void);
void thread_init4(void);
void thread_init5(void);

int main(void){
	int err1, err2;
	int len = 200;
	signal(SIGQUIT, handler);
	lock = malloc(sizeof(pthread_mutex_t));
	lines = (char**)malloc(len*sizeof(char*));
	key1 = malloc(sizeof(pthread_key_t));
	pthread_key_create(key1, NULL);
	printf("Entries/threads pairs are same when thread order is same.\n");
	printf("\n");
	printf("Order of thread execution not enforced.\n");
	printf("\n");
	printf("Enter input, Ctrl D to signal finish.\n");
	int err=pthread_mutex_init(lock, NULL);	
    pthread_once(&o1, thread_init1);
	err1 = pthread_create(&t1, NULL, readInput, NULL);	//start thread 1
	if(err1 != 0){
		printf("Error: thread %d could not be created.\n", (int) t1);
	}
	err2 = pthread_create(&t2, NULL, readInput2, NULL);	//start thread 2
	if(err2 != 0){
		printf("Error: thread %d could not be created.\n", (int) t2);
	}
	pthread_join(t1, &tret1);
	pthread_join(t2, &tret2);	pthread_key_delete(*key1);
	pthread_key_delete(*key2);
	pthread_mutex_destroy(lock);
	return 0;
}
void *readInput(void *arg){
	pthread_mutex_lock(lock);
	fprintf(stdout, "In readInput:\n");
	int tempLen = 200;	//size of buffer
	FILE *tempFP;
	volatile int i =0;
	char **temp; //to copy lines over
	char buf[50] = {0};
	void *getvalue;
	char **tempLines;
	tempLines = (char**)malloc(200*sizeof(char*));
	pthread_mutex_unlock(lock);	
		while(fgets(buf, 100, stdin)!= NULL){
			fprintf(stdout, "IN ONE.\n");
			if(i == tempLen){	//lines is full
				temp = tempLines;	//save lines in case realloc fails 
				tempLen *= 2;
			    fprintf(stdout, "Reallocating.\n");
				pthread_mutex_lock(lock);
				tempLines = realloc(tempLines, tempLen * sizeof(*tempLines));
				pthread_mutex_unlock(lock);
				if(tempLines == NULL){	//realloc failed
				    tempLines = temp;	//paste over saved lines
				    break;
				}
			}
			tempLines[i] = strdup(buf);
			i++;
			pthread_setspecific(*key1, tempLines);	// work
		}
		raise(SIGQUIT);
	fprintf(stdout, "In 1, printing lines, writing them to file.\n");
	int n;
	// fflush(stdout);
    for (n = 0; n < i; n++){
		pthread_mutex_lock(lock);
		tempFP=fopen("threadRecords.txt", "a+");
		tempLines = pthread_getspecific(*key1);
		fprintf(stdout,"%s\n", tempLines[n]);		//display lines to terminal
		fprintf(stdout, "value of n:%d\n", n);
		fprintf(stdout, "value of i:%d\n", i);
		fprintf(tempFP, "%s", tempLines[n]);	//write lines to file
		// if(n != i){
		// 	fprintf(tempFP, "%s", "\n"); //			fprintf(tempFP, "%s", "\n");
		// }
		pthread_mutex_unlock(lock);	
	}
	pthread_exit(0);	
}
void *readInput2(void *arg){
	int tempLen2 = 200;
	FILE *tempFP2;
	char **temp2; //to copy lines over
	char buf2[50] = {0};
	volatile int i2 = 0;
	void *getvalue2;
	char **tempLines2;
	fprintf(stdout, "IN readInput2:\n");
	tempLines2 = (char**)malloc(200*sizeof(char*));
		while(fgets(buf2, 100, stdin)!= NULL){
			fprintf(stdout, "IN TWO.\n");
			if(i2 == tempLen2){	//lines is full
				temp2 = tempLines2;	//save lines in case realloc fails
				tempLen2 *= 2;
				pthread_mutex_lock(lock);
			    fprintf(stdout, "Reallocating.\n");
				tempLines2 = realloc(tempLines2, tempLen2 * sizeof(*tempLines2));
				pthread_mutex_unlock(lock);
				if(tempLines2 == NULL){	//realloc failed
				    fprintf(stdout, "Not enough memory to reallocate.\n");
				    tempLines2 = temp2;	//paste over saved lines
				    break;
				}
			}
			tempLines2[i2] = strdup(buf2);
			i2++;
			pthread_setspecific(*key2, tempLines2);	// work
		}
		raise(SIGQUIT);
	fprintf(stdout, "In 2, printing lines, writing them to file.\n");
	// fflush(stdout);
	int n2;
    for (n2 = 0; n2 < i2; n2++){
		pthread_mutex_lock(lock);
		tempFP2=fopen("threadRecords.txt", "a+");
		tempLines2 = pthread_getspecific(*key2);
		fprintf(stdout, "%s\n", tempLines2[n2]);		//display lines to terminal
		fprintf(stdout, "value of n2:%d\n", n2);
		fprintf(stdout, "value of i2:%d\n", i2);
		fprintf(tempFP2, "%s", tempLines2[n2]);	//write lines to file
		// if(n2 != i2){
		// 	fprintf(tempFP2, "%s", "\n");
		// }
		pthread_mutex_unlock(lock);
	}
	pthread_exit(0);
}
void handler(int signum){
	if (signum == SIGQUIT){
		write(1, "\nReceived SIGQUIT\n", 18);
	}
}
void destructor(void *k){
	free(k);
}
void thread_init1(void){
	key2 = malloc(sizeof(pthread_key_t));
	pthread_key_create(key2, NULL);
}