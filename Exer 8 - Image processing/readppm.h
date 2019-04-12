/*
	readppm.h
	KBPPelaez

	A C Header file for reading and saving PPM files.
	Saving PPM function mainly from link specified above the function.

	Created as library for CMSC 21 Exercise 08, 2nd Sem, AY 18-19.
*/

#include<stdlib.h>
#include "tumpalan_E2L_exer8.h" //replace this with your file named surname_08.h

//reads the header of the image for information about the image
FILE * readHeader(FILE *fp, int *width, int *height){
	char temp[128];

	fgets(temp,128,fp);
	fscanf(fp, "%d %d", width, height);
	fgets(temp,128,fp);
	return fp;
}

//reads the red channel of the PPM image
unsigned char ** readRedPPM(int *width, int *height){
	FILE *fp = fopen("./imgs/sample5.ppm", "rb");
	unsigned char **img, temp;
	int i,j;

	fp = readHeader(fp, width, height);

/*******THIS IS A FUNCTION YOU SHOULD CREATE******/
	img = allocateArray(*height, *width);
/*************************************************/

	for(i=0; i< *height; i+=1){
		for(j=0; j<*width; j+=1){
			temp = fgetc(fp);
			img[i][j] = fgetc(fp);
			temp = fgetc(fp);
		}
	}

	return img;
}

//reads the green channel of the PPM image
unsigned char ** readGreenPPM(int *width, int *height){
	FILE *fp = fopen("./imgs/sample5.ppm", "rb");
	unsigned char **img, temp;
	int i,j;

	fp = readHeader(fp, width, height);

/*******THIS IS A FUNCTION YOU SHOULD CREATE******/
	img = allocateArray(*height, *width);
/*************************************************/

	for(i=0; i< *height; i+=1){
		for(j=0; j<*width; j+=1){
			temp = fgetc(fp);
			temp = fgetc(fp);
			img[i][j] = fgetc(fp);
		}
	}

	return img;
}

//reads the blue channel of the PPM image
unsigned char ** readBluePPM(int *width, int *height){
	FILE *fp = fopen("./imgs/sample5.ppm", "rb");
	unsigned char **img, temp;
	int i,j;

	fp = readHeader(fp, width, height);

/*******THIS IS A FUNCTION YOU SHOULD CREATE******/
	img = allocateArray(*height, *width);
/*************************************************/

	for(i=0; i< *height; i+=1){
		for(j=0; j<*width; j+=1){
			img[i][j] = fgetc(fp);
			temp = fgetc(fp);
			temp = fgetc(fp);
		}
	}

	return img;
}

//Saves the array into a PPM file
//This function is mainly from the solution in this post:
//https://stackoverflow.com/questions/4346831/saving-numerical-2d-array-to-image
void savePPM(unsigned char **red, unsigned char **green, unsigned char **blue, int height, int width){
	int i,j;

	FILE *fp = fopen("result5.ppm","wb");
	fprintf(fp,"P6\n%i %i\n255\n",width,height);
	
	for(i=0;i<height;i++){
		for(j=0;j<width;j+=1){
			fputc(red[i][j],fp);	//red
			fputc(green[i][j],fp);	//green
			fputc(blue[i][j],fp);	//blue
		}	
	}
	fclose(fp);	
}
