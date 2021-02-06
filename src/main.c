#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void Print(char * begin, char * end){
	for(; begin != end; ++begin){
		printf("%c", *begin);
	}
}

void movePointer(char ** start){
	++(*start);
	while(**start != ';'){
		++(*start);
	}
}

int validateCardNumber(char ** beginPtr, char ** endPtr, char ** cardNumPtr, char  cardNum[]){

	while(*beginPtr != *endPtr){
		if((int) **cardNumPtr >= (int) **beginPtr){
			++(*beginPtr);
			++(*cardNumPtr);
		}
		else {
			return  0;
			break;
		}
	}

	*beginPtr = *endPtr + 1;
	movePointer(&*endPtr);
	*cardNumPtr = cardNum;

	while(*beginPtr != *endPtr){
		if((int) **cardNumPtr <= (int) **beginPtr){
			++(*beginPtr);
			++(*cardNumPtr);
		}
		else {
			return 0;
			break;
		}
	}

	return 1;
}

int main()
{
	
	char cardValidation[88] = {0};
	char c;
	int i = 0;

	// Check file exists
	FILE *in_file  = fopen("src/file.txt", "r");

	if (! in_file){
		printf("Error! Could not open file\n");
		exit(-1);
	}

	// load file
	while (fscanf(in_file, "%c", &c) == 1){
		cardValidation[i] = c;
		++i;
	}

	while(1){
	
		// Expect N = 16 + 2 as last character will be \0 and 2nd last \n
		char cardNum[18] = {0};
		char * cardNumBeginPtr = cardNum;
		char * cardNumEndPtr = (char *)(&cardNum + 1) - 1;
		int cardNotOK = 1;
		
		

		while(cardNotOK){
			while(cardNotOK){
				// Get card entry
				printf("\nEnter your card number (16 digits): ");
				fgets(cardNum, 18, stdin);

				if(*(cardNumEndPtr-1) == '\n'){
					while(cardNumBeginPtr != cardNumEndPtr-2){
						if(!isdigit(*cardNumBeginPtr)){
							printf("\nEntered card number is invalid: ");
							cardNumBeginPtr = cardNum;
							Print(cardNumBeginPtr, cardNumEndPtr);
							break;
						}
						++cardNumBeginPtr;
					}
					fflush(stdin);

					if(cardNumBeginPtr == cardNumEndPtr-2){
						cardNotOK = 0;
					}
				} else{
					printf("\nEntered card number is too long!");
				}
			}
			
			printf("\nEntered Card Number: %s",cardNum);

			cardNotOK = 1;
			int isValid = 0;
			char * cardNumPtr = cardNum;
			char * beginPtr = cardValidation;
			char * endPtr = beginPtr;

			movePointer(&endPtr);
			
			for(i = 0; i < 3; ++i){

				isValid = validateCardNumber(&beginPtr, &endPtr, &cardNumPtr, cardNum);

				if(isValid){
					printf("\nCard is vaild of type: ");
					char * start = ++endPtr;
					movePointer(&endPtr);
					Print(start, endPtr);
					cardNotOK = 0;
					break;
				} else {
					cardNumPtr = cardNum;
					++endPtr;
					movePointer(&endPtr);
					++endPtr;
					beginPtr = ++endPtr;
					movePointer(&endPtr);
				}
			}

			if(!isValid){
				printf("\nThis card is not a vaild type: %s", cardNum);
			}
		}

		int amountNotOK = 1;
		char enteredAmount[8] = {0};

		while(amountNotOK){
			int ok = 1;
			// Get amount entry
			printf("\nEnter amount (format nnnn.mm): ");
			fgets(enteredAmount, 8, stdin);

			int count = sizeof(enteredAmount) / sizeof(enteredAmount[0]);
			int decimals = 0;

			for (int i = 0; i < count - 1; ++i) {
				if (enteredAmount[i] == '.') {
					++decimals;
				} else if (!isdigit(enteredAmount[i]) && enteredAmount[i] != '\n' && enteredAmount[i] != '\0')
				{
					printf("Incorrect '%c'", enteredAmount[i]);
					ok = 0;
					break;
				}
				
			}

			if(decimals > 1 || decimals < 1){
				printf("\nThis amount has an incorrect amount of decimal points!");
			}
			else if(!ok){
				printf("\nEntered amount does not match the format!");
			}
			else {
				printf("\nEntered amount is: %.2f", atof(enteredAmount));
				amountNotOK = 0;
			}
		}

		FILE * fPtr = fopen("output/file1.txt", "a");

		/* fopen() return NULL if last operation was unsuccessful */
		if(fPtr == NULL)
		{
			/* File not created hence exit */
			printf("\nUnable to create file.");
			exit(EXIT_FAILURE);
		}

		/* Write data to file */
		char space[] = {';'};
		fputs(cardNum, fPtr);
		fputs(space, fPtr);
		fputs(enteredAmount, fPtr);

		fclose(fPtr);

		printf("\nFile saved successfully in output.");
	}
	return (0);
}