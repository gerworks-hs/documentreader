#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

char* getPath() {
	//Error I got the first time in the following line:
	//If you do not assign the char pointer (path) to some space in memory...
	//You will get a segmentation fault when running fgets cause fgets does not know where to save data read from data stream (stdin)
	//To avoid the previous error we need to assign to char pointer a pointer returned by malloc, malloc allocates memory for this pointer
	char* path = malloc((sizeof(char) * 100));
	printf("Enter the file path: ");
	if (fgets(path, 100, stdin) == NULL) {
		printf("\n");
		printf("Error reading from data stream\n");
	} else {
		while (strchr(path, '\n') != NULL) {
			char* i = strchr(path, '\n');
			*i = '\0';
		}
		printf("OK\n");
	}
	return path;
}

int main() {
	//FILE* fptr;
	//fptr = fopen(path, "a");
	printf("File path -> %s\n", getPath());
	return 0;
}
