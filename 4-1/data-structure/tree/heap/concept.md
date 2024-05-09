# Heap

## 개념

- 힙은 완전 이진 트리에 있는 노드 중 키값이 가장 큰 노드나 키값이 가장 작은 노드를 찾기 위해 만든 자료구조

<img width="215" alt="image" src="https://github.com/HoyeongJeon/Capstone_Design/assets/78394999/8101b71e-a88f-44d2-9f43-6ba756c51180">

- 최대 힙(Max Heap): 키값이 가장 큰 노드를 찾기 위한 힙

  - 부모 노드의 키값이 자식 노드의 키값보다 항상 크거나 같은 크기의 관계 [부모 노드의 키값 >= 자식 노드의 키값]

- 최소 힙(Min Heap): 키값이 가장 작은 노드를 찾기 위한 힙
  - 부모 노드의 키값이 자식 노드의 키값보다 항상 작거나 같은 크기의 관계 [부모 노드의 키값 <= 자식 노드의 키값]
    <img width="421" alt="image" src="https://github.com/HoyeongJeon/Capstone_Design/assets/78394999/826c96b1-b087-4c26-9d62-291745b22426">

## Heap의 삽입 연산

- 레스토랑에서 테이블에 앉는 과정과 비슷
  - 레스토랑에 들어가면 일단 대기석에 기다리면서 원하는 자리를 주문하고, 주문한 자리가 준비되었을 때 들어가 앉는다.
- 힙에 데이터를 삽입할 때도 마찬가지로 삽입할 데이터를 우선 대기시킨 후, 힙의 특성을 만족하도록 데이터를 이동시킨다.
  - 일단 완전이진트리의 형태 조건을 만족하기 위해 현재의 마지막 노드의 다음 자리를 확장하여 자리를 만들고, 삽입할 원소를 임시로 저장
  - 삽입할 원소와 부모 노드의 원소를 비교하여 힙의 특성을 만족할 때까지 위치를 변경

1단계 : 완전 이진 트리의 형태를 만족하도록 다음 자리 확장
2단계 : 부모 노드와 크기 조건이 만족하도록 삽입 원소의 위치를 찾는다.

## <img width="452" alt="image" src="https://github.com/HoyeongJeon/Capstone_Design/assets/78394999/da68c9b8-1cfd-4f52-b451-894970cbfc6f">

<img width="483" alt="image" src="https://github.com/HoyeongJeon/Capstone_Design/assets/78394999/98b472e1-4ee1-4a91-8c97-9b00821f2c2e">

```c
void insertHeap(heapType* h, int item) {
  int i;
  h->heapSize = h->heapSize + 1;
  i = h->heapSize;
  while((i != 1) && (item > h->heap[i/2])) {
    h->heap[i] = h->heap[i/2];
    i = i/2;
  }
  h->heap[i] = item;
}
```
