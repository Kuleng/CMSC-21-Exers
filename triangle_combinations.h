void inputs(int *sum_tri){

	printf("Enter Sum:  ");
	scanf("%d", sum_tri);
	printf("Your sum_tri is: %d \n", *sum_tri);
}

int triangle_num(int n, int count){
	if (n == 0)
		return 0;
	else {
		count += 1;
		return triangle_num(n-1, count) + count;
	}
}

int is_tri_num(int num, int count){
	if (num == 0 || num == 1)
		return 1;
	for (int i = 2; i < num; i++){
		if (triangle_num(i, count) == num)
			return 1;
	}

	return 0;
}