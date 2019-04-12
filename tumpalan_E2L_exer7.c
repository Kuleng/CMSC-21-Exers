//TUMPALAN, JOHN KARL B.
//CMSC 21 E-2L
//MARCH 6, 2019
//ARRAYS

#include <stdio.h>
#include <stdlib.h>
#include "tumpalan_E2L_exer7.h"

int main(){
	int array_size, user_choice, vowel_count = 0;
	char *alphabet = NULL, *duplicates = NULL;
	int i,vowel_size,duplicate_size = 0;

	input_size(&array_size);

	while (array_size > 0){

		menu_printer();

		printf("Choose a number:");
		scanf("%d", &user_choice);
		printf("\n \n");

		switch (user_choice){
			case 1:
				alphabet = (char*) malloc(sizeof(char) * array_size); //ALLOCATION

				for (i = 0; i < array_size; i++){
					getchar(); //LOOP TO GET INPUTS
					printf("Enter character[%d]: ", i + 1);
					scanf("%c", &alphabet[i]);
				}
				printf("Your inputs are:  ");
				printer(alphabet,array_size); //PRINTER OF ALL INPUT
				continue;
			case 2:
				vowel_size = vowel_counter(alphabet, array_size, &vowel_count); //CHECKS VOWEL SIZE
				if (vowel_size != 0)
					printf("Count of vowels: %d \n", vowel_size); //SHOWS VOWEL SIZE
				continue;
			case 3:
				duplicates = (char*) malloc(sizeof(char) * array_size);

				for (int j = 0; j < array_size; j++){ //for every element a in the list
					for (int k = j+1; k < array_size; k++){ //loop every element b on the right side of the list
						if (alphabet[j] == alphabet[k]){ //if a == b, check if the element is already in the duplicate array
							if (is_duplicate(alphabet[j],duplicates,array_size) == 1){
								break; //if true, break
							}
							else{
								duplicates[duplicate_size] = alphabet[j];
								duplicate_size ++; //if not, add the element to the duplicate array and increment the duplicate size.
								break;
							}
						}
					}
				}

				printf("Duplicate letters are: ");
				
				if (duplicate_size == 0){ //IF THE DUPLICATE SIZE IS 0, THERE ARE NO DUPLICATES.
					printf("None.\n");
				} else {
				for (i = 0; i < array_size; i++){
					printf("%c ",duplicates[i]); //DISPLAY DUPLICATES
				}
				}
				printf("\n \n"); //SPACES
				
				continue;
			case 4:
				free(alphabet);
				free(duplicates); //exit and free memory allocation.
				printf("Goodbye!\n");
				break;
			default:
				free(alphabet);
				free(duplicates); //exit and free memory allocation.
				printf("Invalid Input!\n");
				break;
		}
		break;
	}
	return 0;
}