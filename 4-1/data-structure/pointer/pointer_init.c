#include <stdio.h>

void main() {
	int i = 0;
	int *ptr = &i;

	// 문자형 포인터에 문자열 시작 주소 지정
	char *ptr = (char *)malloc(100);
	char *ptr = "korea";

	// 배열 이름을 이용해 배열 시작 주소 지정
	char A[100];i
	char *ptr = A;

	// 배열 첫 번째 요소의 주소를 이용해 배열 시작 주소 지정
	char A[100];
	char *ptr = &A[0];
	
}
