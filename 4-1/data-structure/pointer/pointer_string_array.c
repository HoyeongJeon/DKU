#include <stdio.h>

void main() {
	int i;
	char string1[20] = "Dreams come true!", string2[20], *ptr1, *ptr2;

	
	ptr1 = string1; // 배열의 경우 이름 자체가 포인터
	printf("string1의 주소 = %u\t ptr1 = %u\n", string1, ptr1);
	printf("string1 = %s\n ptr1 = %s\n", string1, ptr1);
	printf("\n%s \n", ptr1 + 7);
	ptr2 = &string1[7]; // 배열의 한 요소는 & 붙여야 포인터가 됨 
	printf("%s\n", ptr2);

	for(i = 16; i >= 0; i--) {
		putchar(*(ptr1+i));
	}

	for(i = 0; i < 20; i++) {
		string2[i] = *(ptr1 + i);
	}

	printf("\nstring1 = %s\n", string1);
	printf("string2 = %s\n", string2);

	*ptr1='P'; *(ptr1+1) = 'e'; *(ptr1+2) = 'a'; *(ptr1 + 3) = 'c'; *(ptr1 + 4) = 'e';
	printf("\nstring1 = %s\n", string1);
	getchar();



}
