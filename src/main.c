#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "fileIO.h"
#include "userInput.h"
#include "cardCheck.h"
#include "common.h"

void clear (void)
{
	char c;
	while((c = getchar()) != '\n' && c != EOF);
}

int valueInArray(char val, char arr[], int arrSize)
{
    int i;
    for(i = 0; i < arrSize; ++i)
    {
        if(arr[i] == val)
            return 1;
    }
    return 0;
}

int main()
{
	char cardValidation[89] = {0};
	loadValidationFile(cardValidation, "src/file.txt");

	while(1){
		char cardNum[18] = {0};
		char * cardNumEndPtr = (char *)(&cardNum + 1) - 1;
		char type[11] = {0};

		do{
			do{
				for(int i = 0; i < 18; ++i){
					cardNum[i] = '\0';
				}
				printf("\nEnter your card number (16 digits): ");
				fgets(cardNum, 18, stdin);

				if(!valueInArray('\n', cardNum, sizeof(cardNum)/sizeof(cardNum[0]))){
					clear();
				}
			}while(!validateCardNumber(cardNum, cardNumEndPtr));

			printf("Entered card: %s", cardNum);

		}while(!getCardType(cardValidation, (char *)(&cardValidation + 1) - 1, cardNum, type));

		char amount[9] = {0};

		do{
			for(int i = 0; i < 9; ++i){
				amount[i] = '\0';
			}

			printf("\nEnter amount (format nnnn.mm): ");
			fgets(amount, 9, stdin);

			if(!valueInArray('\n', amount, sizeof(amount)/sizeof(amount[0]))){
				clear();
			}
		}while(!validateAmount(amount, (char *)(&amount + 1) - 1));

		char * newl = (indexOf(cardNum, cardNumEndPtr, '\n'));
		*newl = ';';

		newl = indexOf(amount, (char *)(&amount + 1) - 1, '\n');
		*newl = ';';

		newl = indexOf(type, (char *)(&type + 1) - 1, '\0');
		*newl = ';';

		saveFile(cardNum, type, amount, "output/file1.txt");
	}

	return (0);
}