#include <stdio.h>
typedef int element;

void sequentialSearch2(element a[], int n, int key);

int main(void) {
    int i;
      element a[] = {1, 2, 8, 9, 11, 19, 29};
    int size = sizeof(a) / sizeof(a[0]);    // 배열 원소의 개수

    printf("\n\t<< 검색 대상 자료 >>\n");
    
    for(i = 0; i < size; i++) {
        printf("%5d ", a[i]);
    }

    sequentialSearch2(a, size, 9); // 9를 검색
    sequentialSearch2(a, size, 6); // 6을 검색

    getchar(); return 0;
}