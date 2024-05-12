# 스레드 이진 트리

- 이진 트리는 부모 노드와 자식 노드의 이진 트리 기본 구가 각 레벨에서 순환적으로 반복되어 전체 트리가 구성되는 구조.
- 일반적인 이진 트리는 각 노드에서 순회할 때 재귀호출을 사용함
  -> 성능이 떨어질 수 있음
- 스레드 이진 트리는 자식 노드가 없는 경우에 링크 필드를 널 포인터 대신 순회 순서상 다른 노드를 가리키도록 설정 -> 이 링크필드를 **스레드**라고 함

```c
// 스레드 이진 트리 노드 구조체
typedef struct treeNode {
    char data;
    struct treeNode *left;
    struct treeNode *right;
    int isThreadLeft;
    int isThreadRight;
} treeNode;
```

<img width="284" alt="image" src="https://github.com/HoyeongJeon/DKU/assets/78394999/2fefbe7e-6403-457c-ade5-1b4499116867">

순회를 위해 후속자 정보만 필요한 경우 아래처럼 오른쪽 링크 필드만 스레드로 사용할 수 있음
<img width="273" alt="image" src="https://github.com/HoyeongJeon/DKU/assets/78394999/ae3b6a0f-5fef-4407-b9b7-7c0a2d5ef53e">
