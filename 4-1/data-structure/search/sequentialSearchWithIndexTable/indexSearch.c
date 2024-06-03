#include <stdio.h>
#include "indexSearch.h"
#include "sequentialSearchWithIndexTable.h"

iTable* makeIndexTable(element a[], int size) {
    int i, n;
    n = size / INDEX_SIZE; // 인덱스 테이블에 들어가는 배열 원소의 간격 계산
    if(size % INDEX_SIZE > 0) n++; // size가 INDEX_SIZE로 나누어 떨어지지 않는 경우 나머지 발생. 이 경우, n을 1 증가시킴으로써 , 인덱스테이블이 배열 'a'의 모든 원소를 포함하도록 함
    // 즉 나머지 원소들을 포함하기 위해 추가적인 인덱스가 필요하므로, n을 1 증가시킨 것
    for(i = 0; i < INDEX_SIZE; i++) {
        indexTable[i].index = i * n;
        indexTable[i].key = a[i * n];
    }
    return indexTable;
}

// 색인 순차 검색
void indexSearch(iTable indexTable[], element a[], int n, element key) {
    int i , begin, end;
    if(key < a[0] || key > a[n-1]) {
        printf("\n찾는 키가 없습니다. 검색 실패! \n");
    }

    // 인덱스 테이블을 검색하여 검색 범위 결정
    for(i = 0; i < INDEX_SIZE; i++) {
        if((indexTable[i].key <= key) && (indexTable[i + 1].key > key)) {
            begin = indexTable[i].index;
            end = indexTable[i + 1].index;
            break;
        }

        if(i == INDEX_SIZE) {
            begin = indexTable[i - 1].index;
            end = n;
        }
    }
    sequentialSearch3(a, begin, end, key); // 검색 범위에 대한 순차 검색 수행
}