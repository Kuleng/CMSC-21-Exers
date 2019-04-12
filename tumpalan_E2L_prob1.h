void inputXYZ(int *num1, int *num2, int *num3) {

	printf("Enter 1st num:  \n");
	scanf("%d", num1);
	
	printf("Enter 2nd num:  \n");
	scanf("%d", num2);
	
	printf("Enter 3rd num:  \n");
	scanf("%d", num3);

}

int lowest(int num1, int num2, int num3){
	if (num1 < num2 && num1 < num3){
		return num1;
	} else if (num2 < num1 && num2 < num3) {
		return num2;
	} else{
		return num3;
	}
}

int gcf(int int_1, int int_2, int int_3, int lowest_int) {
	if ((int_1 % lowest_int == 0) && (int_2 % lowest_int == 0) && (int_3 % lowest_int == 0)){
		return lowest_int;
	} else{
		return gcf(int_1,int_2,int_3,lowest_int-1);
	}
}
