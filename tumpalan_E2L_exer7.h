//TUMPALAN, JOHN KARL B.
//CMSC 21 E-2L
//MARCH 6, 2019
//ARRAYS

void input_size(int *size) {

	printf("Enter size of array:  \n");
	scanf("%d", size); //ENTER THE SIZE OF THE ARRAY
}

void menu_printer(){ //MENU PRINTER
	printf("============= MENU ============\n");
	printf("[1] Input characters \n");
	printf("[2] Count vowels \n" );
	printf("[3] Print duplicates \n" );
	printf("[4] Exit \n" );
	printf("===============================\n");
}

int vowel_counter(char alphabet[], int array_size, int *vowel_count){

	if (alphabet == NULL){ //IF THE ALPHABET ARRAY IS EMPTY, PRINT AND RETURN 0.
		printf("Invalid, the array is still empty! :( \n");
		return 0;
	}
	else{ //IF THE ALPHABET ARRAY HAVE ELEMENTS, LOOP THROUGHT THE ELEMENTS AND FIND FOR EVERY POSSIBLE COMBINATIONS OF VOWELS.
		for (int i = 0; i <= array_size; i ++){
			if (alphabet[i] == 'a' || alphabet[i] == 'e' || alphabet[i] == 'i' || alphabet[i] == 'o' || alphabet[i] == 'u'){
				*vowel_count+=1; //IF VOWEL, INCREMENT VOWEL COUNTER
			} else if (alphabet[i] == 'A' || alphabet[i] == 'E' || alphabet[i] == 'I' || alphabet[i] == 'O' || alphabet[i] == 'U'){
				*vowel_count+=1;
			} else
				continue;
		}
	return *vowel_count; //RETURN VOWEL COUNT
	}
}

void printer(char alphabet[], int sizeofarray){
	for (int i = 0; i < sizeofarray; i ++) {
		printf("%c ",alphabet[i]);
	} //PRINTS ALL ELEMENTS OF ALPHABET
	printf("\n");
}

int is_duplicate(char a, char duplicates[],int array_size){
	for (int i = 0; i < array_size; i++){
		if (a==duplicates[i]){ //CHECKS THE CHAR A IF ALREADY IN DUPLICATES ARRAY
			return 1;
		}
	}
	return 0;
}
