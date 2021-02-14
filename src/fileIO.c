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

void saveFile(char * cardNumber, char * cardType, char * amount, char * filePath){
    FILE * fPtr = fopen(filePath, "a");

    /* fopen() returns NULL if last operation was unsuccessful */
    if(fPtr == NULL)
    {
        perror("\nUnable to create file or open file.");
        exit(EXIT_FAILURE);
    }

    /* Alter \n\0 in cardNum needs to be done before method call
    *(cardNumEndPtr-2) = ' ';
    *(cardNumEndPtr-1) = ';';*/

    /* Write data to file */
    fprintf(fPtr, "%s%s%s\n", cardNumber, cardType, amount);

    fclose(fPtr);

    printf("\nFile saved successfully in output folder.");
}