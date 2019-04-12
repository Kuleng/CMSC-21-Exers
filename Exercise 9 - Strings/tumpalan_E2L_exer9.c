//TUMPALAN, JOHN KARL B.
//MARCH 20, 2019
//EXERCISE 9 - STRINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tumpalan_E2L_exer9.h"

int main(){
	char *inputArray;
	int size;
	int pangramCheck;

	inputArray = (char *) malloc (sizeof(char) * 100);

	printf("Input:  "); //GETS THE INPUT
	scanf("%s", inputArray);

	size = strlen(inputArray);
	if (size < 26) 		//CHECKS THE SIZE
		printf("The string is not a pangram.\n");
	else{
		printf("String size is: %d \n",size);


		removeNonAlpha(inputArray, size); //Remove non-alphabet.
		printf("Removed non-alphabet. \n New string is: %s \n",inputArray);


		pangramCheck = isPangram(inputArray, size); //CHECK IF A PANGRAM


		if (pangramCheck == 1)	 //RETURN PROGRAM RESPONSE IF PANGRAM OR NOT
			printf("The string is a pangram.\n");
		else
			printf("The string is not a pangram.\n");
	}

	free(inputArray);
	
	return 0;
}