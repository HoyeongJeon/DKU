#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

// 공백 힙 생성
heapType* createHeap(void) {
    heapType* h = (heapType*)malloc(sizeof(heapType));
    h->heap_size = 0;
    return h;
}

void insertHeap(heapType* h, int item) {
  int i;
  h->heap_size = h->heap_size + 1; // 힙 크기 증가
  i = h->heap_size; // 임시 삽입 위치
  while((i != 1) && (item > h->heap[i/2])) {  // 삽입할 원소 item과 부모 노드 heap[i/2] 비교해서 부모 노드보다 작거나 같으면 임시 삽입 위치 i를 삽입 원소의 위치로 확장한 뒤 h->heap[i] = item; 실행 
    h->heap[i] = h->heap[i/2]; // 삽입 원소 item이 부모 노드보다 크면, 부모 노드와 자식 노드의 자리를 맞바꿔 최대 힙의 관계를 만들어야 하므로 부모 노드 heap[i/2]를 자식 노드 heap[i]로 이동 
    i = i/2; 
  }
  h->heap[i] = item;
}

// 언제나 루트 노드에 있는 원소를 삭제하여 반환
int deleteHeap(heapType* h) {
  int parent , child;
  int item, temp;
  item = h->heap[1]; // 루트 노드를 변수 item에 저장
  temp = h->heap[h->heap_size]; // 마지막 노드의 원소 heap[n]을 변수 temp에 임시 저장
  h->heap_size = h->heap_size - 1; // 마지막 노드의 원소를 삭제했으므로, heap 배열의 원소 개수 1개 감소
  parent = 1; // root
  child = 2; // root의 left child
  while(child <= h->heap_size) { 
    if((child < h->heap_size) && (h->heap[child] < h->heap[child+1])) // 현재 저장 위치에서 왼쪽 자식 노드와 오른쪽 자식 노드의 크기를 비교해서 값이 큰 자식노드로 child 변경
      child++;
    if(temp >= h->heap[child]) break; // 마지막 노드가 루트의 자식노드보다 큰 경우, 현재의 임시 저장 위치를 temp 자리로 확정
    else {
      h->heap[parent] = h->heap[child]; // temp가 자식 노드보다 작으면 자식 노드와 자리를 바꾸고,temp의 자리를 확정할때까지 while문 반복
      parent = child;
      child = child * 2;
    }
  }
  h->heap[parent] = temp; // 찾은 위치에 temp 저장해 최대 heap 재구성 작업 완성
  return item; // 처음 삭제한 루트 노드 반환
}

void printHeap(heapType* h) {
  int i;
  printf("Heap : ");
  for(i=1; i<=h->heap_size; i++)
    printf("[%d] ", h->heap[i]);
  printf("\n");
}