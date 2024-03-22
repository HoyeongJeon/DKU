#include <stdio.h>

void main() {
	int i , sale[4] = {1,2,3,4};
	for(i = 0; i < 4 ; i++) {
		printf("address: %u sale[%d] = %d\n", &sale[i] , i , sale[i]);
	}
	getchar();
}
