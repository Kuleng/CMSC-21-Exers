//TUMPALAN, JOHN KARL B.
//MARCH 20, 2019
//EXERCISE 9 - STRINGS


void removeNonAlpha(char *sentence, int size){
	for (int i = 0; i < size; i++){
		if (isalpha(sentence[i]) == 0){
			//If not in the alphabet
			sentence[i] = ' '; //Replace with space
		}
	}
}

int isPangram(char *sentence, int size){
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	int numPangram = 0;

	for (int a = 0; a < size; a ++){ //TRANSFORMS ALL LETTERS TO LOWERCASE
		if (isupper(sentence[a]) != 0){ //If uppercase
			sentence[a] = tolower(sentence[a]); //Transform
		}
	}

	for (int i = 0; i < size; i ++){ //For every letter in the alphabet
		for (int j = 0; j < size; j++){ //Loop on every letter of the string.
			if (alphabet[i] == sentence[j]){
				numPangram ++; //Add to numPangram
				break;
			}
		}
	}

	printf("%d \n",numPangram );

	if (numPangram == 26) //if exactly 26, the string is a pangram.
		return 1;
	else
		return 0;
}
