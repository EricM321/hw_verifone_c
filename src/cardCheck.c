#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <stdio.h>
#include "cardCheck.h"
#include "common.h"

void movePointer(char ** start){
	++(*start);
	while(**start != ';'){
		++(*start);
	}
}

int compareCardNumber(char ** beginPtr, char ** endPtr, char ** cardNumPtr, char  cardNum[]){

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


int getCardType(char * cardValidator, char * endOfCardValidator, char * cardNumber, char * type){
    char * cardNumPtr = cardNumber;
    char * rangeBegin = cardValidator;
    char * rangeEnd = cardValidator;
    char * lastSemiColonInFile = endOfCardValidator;

    while(*lastSemiColonInFile != ';'){
        --lastSemiColonInFile;
    }

    while(rangeEnd != lastSemiColonInFile+1){
        movePointer(&rangeEnd);

        if(compareCardNumber(&rangeBegin, &rangeEnd, &cardNumPtr, cardNumber)){
            
            char * start = ++rangeEnd;
            movePointer(&rangeEnd);
            int i = 0;

            while(start != rangeEnd){
                type[i] = *start;
                ++i;
                ++start;
            }

            printf("\nCard is vaild of type: %s\n", type);
            return 1;
        } else {
            cardNumPtr = cardNumber;
            while(*rangeEnd != ';'){
                ++rangeEnd;
            }
            rangeBegin = ++rangeEnd;
        }
    }
    
    printf("Card does not match any type\n");
    #ifdef _WIN32
    Sleep(2000);
    #else
    sleep(2);
    #endif
    return 0;
}