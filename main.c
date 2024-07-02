//MADE BY @itsgerliz

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Error I got the first time in the following line: buffer char pointer
//If you do not assign the char pointer (buffer) to some space in memory...
//You will get a segmentation fault when running fgets cause fgets does not know where to save data read from data stream (stdin)
//To avoid the previous error we need to assign to char pointer a pointer returned by malloc, malloc allocates memory for this pointer	

char* getPath(char* whereToSave) {
	
	fprintf(stdout, "Enter the file path: ");
	
	if (fgets(whereToSave, 100, stdin) == NULL) {
		fprintf(stdout, "\n");
		fprintf(stderr, "Error reading from data stream\n");
		char* aborted = NULL;
		return aborted;
	} else {
		while (strchr(whereToSave, '\n') != NULL) {
			char* i = strchr(whereToSave, '\n');
			*i = '\0';
		}
		fprintf(stdout, "OK!\n");
		return whereToSave;
	}

}

int getStreamChar(FILE* dataStream, char* dataTarget) {
	*dataTarget = fgetc(dataStream);
	if (*dataTarget != EOF) {
		return 0;
	} else {
		return 1;
	}
}

int main() {

	char* buffer = malloc((sizeof(char) * 100)); //Allocate 100 bytes of memory for path
	
	char* result = getPath(buffer); //Save the resulting path

	if (result == NULL) {
		fprintf(stderr, "Aborting...\n");
		return 1;
	} else {
		fprintf(stdout, "Path is -> %s\n", result);
	}
	
	FILE* fileptr;
	
	if ((fopen(result, "r")) == NULL) {
		fprintf(stderr, "Cannot open the file: insufficient permissions or file does not exist\n");
		fprintf(stderr, "Aborting...\n");
		return 1;
	} else {
		fileptr = fopen(result, "r");
		free(buffer);
		fprintf(stdout, "File was opened succesfully, reading...\n");
		
		char* tempChar = malloc(sizeof(char));		
		
		fprintf(stdout, "--BEGIN OF FILE--\n");
		
		do {
			fprintf(stdout, "%s", tempChar);
		} while (getStreamChar(fileptr, tempChar) == 0);

		fprintf(stdout, "--END OF FILE--\n");
		
		fprintf(stdout, "Exiting...\n");
		free(tempChar);
		return 0;
	}

}

//MADE BY @itsgerliz
