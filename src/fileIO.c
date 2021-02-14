#include <stdlib.h>
#include <stdio.h>
#include "fileIO.h"

void loadValidationFile(char * buffer, char * filePath){
    char c;
	int i = 0;

	// Check file exists
	FILE *in_file  = fopen(filePath, "r");

	if (! in_file){
		printf("Error! Could not open file\n");
		exit(-1);
	}

	// load file
	while (fscanf(in_file, "%c", &c) == 1){
		buffer[i] = c;
		++i;
	}
}