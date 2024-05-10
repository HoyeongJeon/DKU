#pragma once
#define MAX_ELEMENT 100

// 힙에 대한 1차원 배열과 힙의 원소 개수를 구조체로 묶어서 선언
typedef struct {
    int heap[MAX_ELEMENT];
    int heap_size;
} heapType;

heapType* createHeap(void);
void insertHeap(heapType* h, int item);
int deleteHeap(heapType* h);
void printHeap(heapType* h);