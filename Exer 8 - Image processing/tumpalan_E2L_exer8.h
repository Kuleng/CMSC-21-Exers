// TUMPALAN, JOHN KARL B.
//EXERCISE 8 - MULTI DIMENSIONAL ARRAYS
//MARCH 13, 2019

unsigned char** allocateArray(int height, int width){
	unsigned char **allocationArray = (unsigned char**) malloc (sizeof(unsigned char*) * (height));
	for (int i = 0; i < (width); i++){
		allocationArray[i] = (unsigned char*) malloc (sizeof(unsigned char) * (width)); //ALLOCATES AN EMPTY ARRAY FOR THE IMG
		}

	return allocationArray;
}

void deallocate(unsigned char **func_img, int height){
	for (int i = 0; i < height; i ++){
		free(func_img[i]);	//DEALLOCATION FUNCTION
	}
	free(func_img);
}

unsigned char** meanColor(unsigned char **allocateArray, int height, int width){
	int vertical = 3, side = 2, mid = 4; //DECLARATION OF KERNEL

	unsigned char **duplicateArray = (unsigned char**) malloc (sizeof(unsigned char*) * (height));
	for (int i = 0; i < (height); i++){
		duplicateArray[i] = (unsigned char*) malloc (sizeof(unsigned char) * (width));
		} //ALLOCATION OF A DUPLICATE KERNEL

	for (int i = 0; i < height-1; i++){
		for (int j = 0; j <width -1; j++){
			if ((j-1) < 0){ //IF LEFT SIDE IS OUT OF RANGE
				if((i-1) < 0){ //IF TOP IS OUT OF RANGE
					duplicateArray[i][j] = (allocateArray[i][j]*mid + allocateArray[i][j+1]*side + allocateArray[i+1][j]*vertical)/ (mid+side+vertical);
				} else if((i+1) > height-1){ //IF BOTTOM IS OUT OF RANGE
					duplicateArray[i][j] = (allocateArray[i][j]*mid + allocateArray[i][j+1]*side + allocateArray[i-1][j]*vertical)/ (mid+side+vertical);		
				} else { //IF LEFT SIDE IS THE ONLY ONE OUT OF RANGE
					duplicateArray[i][j] = (allocateArray[i][j]*mid + allocateArray[i][j+1]*side + allocateArray[i+1][j]*vertical + allocateArray[i-1][j]*vertical)/ (mid+side+vertical*2);	
				}
			}

			else if ((j+1) > width -1){ //IF THE RIGHT SIDE IS OUT OF RANGE
				if((i-1) < 0){ //IF TOP IS OUT OF RANGE
					duplicateArray[i][j] = (allocateArray[i][j]*mid + allocateArray[i][j-1]*side + allocateArray[i+1][j]*vertical)/ (mid+side+vertical);		
				} else if((i+1) > height-1){ //IF BOTTOM IS OUT OF RANGE
					duplicateArray[i][j] = (allocateArray[i][j]*mid + allocateArray[i][j-1]*side + allocateArray[i-1][j]*vertical)/ (mid+side+vertical);		
				} else { //IF RIGHT SIDE IS THE ONLY ONE OUT OF RANGE
					duplicateArray[i][j] = (allocateArray[i][j]*mid + allocateArray[i][j-1]*side + allocateArray[i-1][j]*vertical+ allocateArray[i+1][j]*vertical)/ (mid+side+vertical*2);		
				}
			}
			else if (i-1 < 0){ //IF THE TOP SIDE IS OUT OF RANGE
				duplicateArray[i][j] = (allocateArray[i][j]*mid + allocateArray[i][j-1]*side + allocateArray[i+1][j]*vertical+ allocateArray[i][j+1]*side)/ (mid+side*2+vertical);
			}
			else if (i+1 > height-1){ //IF THE BOTTOM IS THE ONLY ONE OUT OF RANGE
				duplicateArray[i][j] = (allocateArray[i][j]*mid + allocateArray[i][j-1]*side + allocateArray[i-1][j]*vertical+ allocateArray[i][j+1]*side)/ (mid+side*2+vertical);
			}
			else{ //INPUT CROSS CODE HERE
				duplicateArray[i][j] = (allocateArray[i][j]*mid + allocateArray[i][j-1]*side + allocateArray[i-1][j]*vertical + allocateArray[i+1][j]*vertical+ allocateArray[i][j+1]*side)/ (mid+side*2+vertical*2);	
			}
		}
	}

	return duplicateArray; //RETURN MODIFIED DUPLICATED ARRAY
}