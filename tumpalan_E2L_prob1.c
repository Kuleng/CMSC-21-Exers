/////TUMPALAN, JOHN KARL B. CMSC 21- E-2L
//PROBLEM SET 1 - GCF RECURSION
#include <stdio.h>
#include "tumpalan_E2L_prob1.h"

int main() {
	int x, y, z, d;

	inputXYZ(&x, &y, &z); //GETS INPUT OF 3 Numbers

	//Checks if one of the inputs is 0 or negative, if yes, proceed. if no, go to input function again.
	while (x <= 0 || y <= 0 || z <= 0){
		printf("0 and negative numbers are not a valid input. Please try again. \n \n");
		inputXYZ(&x, &y, &z);
	}

	//sets the lowest integer as the basis of factor checking.
	d = lowest(x,y,z);

	//prints the GCF
	printf("The GCF of the three numbers is: %d \n", gcf(x,y,z,d));

	return 0;
}