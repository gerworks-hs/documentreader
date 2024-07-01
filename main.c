#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

char* getPath() {
	
	//Error I got the first time in the following line:
	//If you do not assign the char pointer (path) to some space in memory...
	//You will get a segmentation fault when running fgets cause fgets does not know where to save data read from data stream (stdin)
	//To avoid the previous error we need to assign to char pointer a pointer returned by malloc, malloc allocates memory for this pointer
	
	char* path = malloc((sizeof(char) * 100));
	
	fprintf(stdout, "Enter the file path: ");
	
	if (fgets(path, 100, stdin) == NULL) {
		fprintf(stdout, "\n");
		fprintf(stderr, "Error reading from data stream\n");
		char* aborted = NULL;
		return aborted;
	} else {
		while (strchr(path, '\n') != NULL) {
			auto char* i = strchr(path, '\n');
			*i = '\0';
		}
		fprintf(stdout, "OK!\n");
		return path;
	}

}

int main() {
	
	char* result = getPath();
	
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
		fprintf(stdout, "File was opened succesfully, reading...\n");
	}

}
