#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "userInput.h"
#include "common.h"

int validateCardNumber(char * cardNumber, char * cardNumEndPtr){
    char * cardNumBeginPtr = cardNumber;

    if(*(cardNumEndPtr-1) == '\n'){
        while(cardNumBeginPtr != cardNumEndPtr-1){
            if(!isdigit(*cardNumBeginPtr)){
                printf("Entered card number is invalid: ");
                cardNumBeginPtr = cardNumber;
                Print(cardNumBeginPtr, cardNumEndPtr);
                return 0;
            }
            ++cardNumBeginPtr;
        }
    } else{
        printf("Entered card number is not 16 digits!\n");
        return 0;
    }
    return 1;
}

int validateAmount(char * amount, char * amountEndPtr){
    char * amountBeginPtr = amount;
    int decimals = 0;

    while(amountBeginPtr != amountEndPtr-1){
        if (*amountBeginPtr == '.') {
            ++decimals;
        }
        else if (!isdigit(*amountBeginPtr) && *amountBeginPtr != '\n' && *amountBeginPtr != '\0'){
            printf("Amount contains none digits: ");
            Print(amount, amountEndPtr);
            return 0;
        }
        ++amountBeginPtr;
    }


    char *ptr = indexOf(amount, amountEndPtr, '.')+1;
    amountBeginPtr = amount;
    int m = 0;
    int n = 0;

    while(*amountBeginPtr != '.'){
        ++m;
        ++amountBeginPtr;
    }

    while(*ptr != '\n' && *ptr != '\0'){
        ++n;
        ++ptr;
    }

    if(*(indexOf(amount, amountEndPtr, '\n')) != '\n'){
        printf("Amount entered is too large or too short!\n");
        return 0;
    }
    else if(decimals != 1 ){
        printf("Amount has an incorrect number of decimal points!\n");
        return 0;
    }
    else if(n != 2 || m > 4 || m == 0){
        printf("Entered amount does not match the format!\n");
        return 0;
    }

    return 1;
}