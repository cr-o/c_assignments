#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){
	int res;
	char *x = (char*)malloc(8*sizeof(char));
	x = "test run\n";
	char letters [8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	int numbers[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};
	char buffer[20];
	char *printbuf;
	ssize_t bytes;
	long totalbytes;
	FILE *fo = fopen("binfile.bin", "w+b");
	FILE *fxml = fopen("webview.xml", "r+b");
	FILE *fpdf = fopen("FilmMajorHandout.pdf", "r+b");
	if (fo!=NULL){
		fwrite(x, strlen(x), 1, fo);
		fwrite(letters, sizeof(letters), 1, fo);
 		fwrite(numbers, sizeof(numbers), 1, fo);
	}
	fseek(fo, 0, SEEK_END);
	fo = fopen("binfile.bin", "r+b");
	fseek(fo, 0, SEEK_END);
	fxml = fopen("webview.xml", "r+b");
	if(fxml != NULL){
		while (0< (bytes = fread(buffer, 1, sizeof(buffer), fxml))){			
			fwrite(buffer, 1, bytes, fo);
		}	
	}
	fseek(fo, 0, SEEK_END);
	fpdf = fopen("FilmMajorHandout.pdf", "r+b");
	if(fpdf != NULL){
		while (0< (bytes = fread(buffer, 1, sizeof(buffer), fpdf))){			
			fwrite(buffer, 1, bytes, fo);
		}	
	}
	
	fseek(fo, 0, SEEK_END);
	totalbytes = ftell(fo);
	printf("totalbytes is%ld\n", totalbytes);
	printbuf = malloc(totalbytes);
	rewind(fo);
	if(printbuf != NULL){
		fread(printbuf, totalbytes, 1, fo);

			fwrite(printbuf, 1, totalbytes, stdout);
	}

	free(printbuf);
	fflush(stdout);
	fclose(fo);
	fclose(fxml);
	fclose(fpdf);
	
	return 0;
}
