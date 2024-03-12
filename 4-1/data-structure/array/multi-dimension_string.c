#include <stdio.h>

void main() {
	int i , j;
	int array[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

	getchar();
	
	for(i = 0; i < 3; i++) {
		for(j = 0 ; j < 4; j++) {
			printf("array2[%d][%d] = %d\n", i, j, array[i*3][j]);
		}
	}

}
