#include <stdio.h>

void main() {
	char c, c_arr[100];
	int i , i_arr[100];
	short s , s_arr[100];
	float f, f_arr[100];
	long l, l_arr[100];

	printf("\n char c 크기 = %d\t: char c_array 크기 = %4d", sizeof(c), sizeof(c_arr)); 
	printf("\n int i 크기 = %d\t: int i_array 크기 = %4d", sizeof(i), sizeof(i_arr));
	printf("\n short s 크기 = %d\t: short s_array 크기 = %4d", sizeof(s), sizeof(s_arr)); 
	printf("\n float f 크기 = %d\t: float f_array 크기 = %4d", sizeof(f), sizeof(f_arr)); 
	printf("\n long l 크기 = %d\t: long l_array 크기 = %4d", sizeof(l), sizeof(l_arr));
	
	getchar();

}
