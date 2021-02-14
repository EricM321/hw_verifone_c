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
		exit(EXIT_FAILURE);
	}

	// load file
	while ((c = fgetc(in_file)) != EOF){
        if(c == '\n'){
            continue;
        }
        else{
            buffer[i] = c;
        }
		++i;
	}
}

void saveFile(char * cardNumber, char * cardType, char * amount, char * filePath){
    FILE * fPtr = fopen(filePath, "a");

    /* fopen() returns NULL if last operation was unsuccessful */
    if(fPtr == NULL)
    {
        perror("Unable to create file or open file.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fPtr, "%s%s%s\n", cardNumber, cardType, amount);
    fclose(fPtr);

    printf("\nFile saved successfully in output folder.\n");
}