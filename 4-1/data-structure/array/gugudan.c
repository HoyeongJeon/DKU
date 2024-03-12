#include <stdio.h>

void main() {
	int num;
	int i ;
	int multiply[9];
	
	printf("\n1~9사이의 정수를 입력하세요: ");
	while(1) {
		scanf("%d", &num);
		if(num < 1 || num > 9)
			printf("\n1~9사이의 정수를 입력해주세요: ");
		else
			break;
	}
	printf("\n");
	for(i = 0; i < 9; i++) {
		multiply[i] = num * (i + 1);
		printf("%d x %d = %d\n", num, i + 1, multiply[i]);

	}
	getchar();

}
