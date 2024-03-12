#include <stdio.h>

void main() {
	int i = 123;
	int *ptr = &i;

	printf("i = %d\n,i(*ptr) = %d\ni(ptr)의 주소 = %p\ni(&i)의 주소 = %p\n", i, *ptr , ptr, &i);
}
