// 정렬되어 있지 않은 자료에서 순차 검색
#include <stdio.h>
typedef int element;

void sequentialSearch2(element a[], int n, element key) {
    int i = 0;
    printf("\n%3d를 검색하라! ->> ", key);
    while(i < n && a[i] < key) i++;
    if(a[i] == key) printf("%d번째에 검색 성공!\n", i + 1);
    else printf("%3d번째에서 검색 실패! \n", i + 1);
}
