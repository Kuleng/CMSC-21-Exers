//TUMPALAN, JOHN KARL B. CMSC 21- E-2L
//
#include <stdio.h>
#include "triangle_combinations.h"

int main(){
	int n, x, y, z,sum, count = 0;
	inputs(&sum);

	for (int loop1 = 0; loop1 <= sum; loop1++){
		if (is_tri_num(loop1,count) == 1) {
			x = loop1;
		}
		else
			continue;
		 	for (int loop2 = 0; loop2 <= sum; loop2++){
				if (is_tri_num(loop2,count) == 1) {
					y = loop2;
				}
				else
					continue;
				for (int loop3 = 0; loop3 <= sum; loop3++){
					if (is_tri_num(loop3,count) == 1) {
						z = loop3;
				} 
					else
						continue;
						if (loop1 + loop2 + loop3 == sum){
							printf("%d %d %d \n",loop1, loop2, loop3);
							break;
				}
			}
		}
	}
}