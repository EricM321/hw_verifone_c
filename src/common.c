#include <stdio.h>
#include "common.h"

void Print(char * begin, char * end){
	for(; begin != end; ++begin){
		printf("%c", *begin);
	}
}

char * indexOf(char * arrayPtr, char * endOfArrayPtr, char find){
	while(arrayPtr != endOfArrayPtr){
		if(*arrayPtr == find){
			return arrayPtr;
		}
		++arrayPtr;
	}
	return endOfArrayPtr;
}