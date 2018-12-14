#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <malloc/malloc.h>
#include <unistd.h>
#define COLS 2
char **MakeList(void);
void MakeTable(char **m);
int rows;
int main(void){
	printf("Enter how many rows: ");
	scanf("%d", &rows);
    char **list=MakeList();
    MakeTable(list);
	return 0;
}
char **MakeList(void){
    char **names;
	char buf[50] = {0};
	int numEntries = rows*COLS;
	names = (char **)malloc(rows*sizeof(char* ));
    char *book=malloc(BUFSIZ);
	for (int i = 0; i < rows ; i++){
		printf("Enter book title and author, separated by space: ");
		scanf(" %[^\n]%*c", buf);
		names[i] = strdup(buf);
	}
	 return names;
}
void MakeTable(char **m){
	FILE *fp;
	fp=fopen("outfile.txt", "w+");
	int i, j;
    for (i = 0; i < rows; i++){
			printf("%s\t", m[i]);
			printf("\n");
			fprintf(fp, "%s", m[i]);
			fprintf(fp, "%s", "\n");
	}
	fclose(fp);
}