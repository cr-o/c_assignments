#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
struct arg_struct {
    int arg1;
    int arg2;
};
int firstRowNum, firstColNum, secRowNum, secColNum;
void *calc(void *arguments);
int **first;
int **sec;
int **prod;
int main(void){
	printf("Enter number of rows for the first matrix:\n");
	scanf("%d", &firstRowNum);
	printf("Enter number of cols for the first matrix\n");
	scanf("%d", &firstColNum);
	first = (int**)malloc(firstRowNum * sizeof(int*));
	first[0] = (int*)malloc(firstRowNum * firstColNum *(sizeof(int)));
	for (int i = 0; i < firstRowNum; i++){
		first[i] = (*first + firstColNum * i);
	}
	while(1){
		printf("Enter number of rows for the second matrix:\n");
		scanf("%d", &secRowNum);
		if(secRowNum != firstColNum){
			printf("Number of rows in the second matrix must equal the number of cols in the first matrix.\n");
		}else{
			break;
		}
	}
	printf("Enter number of cols for the second matrix:\n");
	scanf("%d", &secColNum);
	sec = (int**)malloc(secRowNum * sizeof(int*));
	sec[0] = (int*)malloc(secRowNum * secColNum *(sizeof(int)));
	for(int i = 0; i < secRowNum; i++){
		sec[i] = (*sec + secColNum*i);
	}
	printf("Allocating product matrix:\n");
	prod = (int**)malloc(firstRowNum * sizeof(int *));
	prod[0] = (int*)malloc(secColNum *firstRowNum* sizeof(int));
	for(int i = 0; i < firstRowNum; i++){
		prod[i] = (*prod + secColNum*i);
	}
	printf("Enter values for the first matrix, press enter after each number:\n");
	for (int i = 0; i < firstRowNum; i++){
		for (int j = 0; j < firstColNum; j++){
			scanf("%d", &first[i][j]);
		}
	}
	printf("Enter values for the second matrix,press enter after each number:\n");
	for (int i = 0; i < secRowNum; i++){
		for (int j = 0; j < secColNum; j++){
			scanf("%d", &sec[i][j]);
		}
	}
	printf("Creating threads for products:\n");
	struct arg_struct args;
	int t = 0;
	int d = 0;
	int count = 0;
	for (t = 0; t < firstRowNum; t++){	
	 	for(d = 0; d < secColNum; d++){
	        struct arg_struct *args = (struct arg_struct *) malloc(sizeof(struct arg_struct));
	        args->arg1 = t;
	        args->arg2 = d;
			pthread_t tid;
			pthread_attr_t attr;
			pthread_attr_init(&attr);
			pthread_create(&tid, &attr, calc, args);
			//sleep(1);
			pthread_join(tid, NULL);
			//sleep(1);
			count++;
		}
	}
	printf("Printing product matrix:\n");
	for(int g = 0; g < firstRowNum; g++){
		for (int x = 0; x < secColNum; x++){
			printf("%d\n", prod[g][x]);
		}
        printf("\n");
	}
	return 0;
}

void *calc(void *arguments){
	struct arg_struct *toMult = arguments;
	int m = 0;
	int sum = 0;
	for(m = 0; m < firstColNum; m++){
		sum += (first[toMult->arg1][m]) * (sec[m][toMult->arg2]);
	}
	prod[toMult->arg1][toMult->arg2] = sum;
	pthread_exit(0);
}