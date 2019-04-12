// TUMPALAN, JOHN KARL B.
//EXERCISE 8 - MULTI DIMENSIONAL ARRAYS
//MARCH 13, 2019

#include<stdio.h>
#include "readppm.h"

int main(){
	int w, h;

	//read the red,blue,green channels of the PPM image
	//read_PPM functions always read the file named sample.ppm inside the imgs folder
	unsigned char **red = readRedPPM(&w,&h);
	unsigned char **green = readGreenPPM(&w,&h);
	unsigned char **blue = readBluePPM(&w,&h);

	unsigned char **meanRed = meanColor(red, h, w);
	unsigned char **meanGreen = meanColor(green, h, w);
	unsigned char **meanBlue = meanColor(blue, h, w);

	//save the PPM image to see result
	savePPM(meanRed,meanGreen,meanBlue,h,w);


	//free your arrays

	deallocate(meanRed, h);
	deallocate(meanGreen, h);
	deallocate(meanBlue, h);
	
	return 0;	
}
