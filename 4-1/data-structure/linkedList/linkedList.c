#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char data[4];
  struct Node *next;
} Node;

typedef struct linkedList_h {
  Node *head;
} linkedList_h;

// create linkedList
linkedList_h *createLinkedList_h(void) {
  linkedList_h *list;
  list = (linkedList_h *)malloc(sizeof(linkedList_h));
  list->head = NULL;
  return list;
}

// free all memories from linkedList
void freeLinkedList_h(linkedList_h *list) {
  Node *p;
  while (list->head != NULL) {
    p = list->head;
    list->head = list->head->next;
    free(p);
    p = NULL;
  }
}

void printList(linkedList_h *list) {
  Node *p;
  printf("L = (");
  p = list->head;
  while (p != NULL) {
    printf("%s", p->data);
    p = p->next;
    if (p != NULL) {
      printf(", ");
    }
  }
  printf(") \n");
}

// 첫 번째 노드로 삽입하는 연산
void insertFirstNode(linkedList_h *list, char *x) {
  Node *newNode;
  newNode = (Node *)malloc(sizeof(Node));
  strcpy(newNode->data, x);
  newNode->next = list->head;
  list->head = newNode;
}

// 노드를 pre 뒤에 삽입하는 연산
void insertMiddleNode(linkedList_h *list, Node *pre, char *x) {
  Node *newNode;
  newNode = (Node *)malloc(sizeof(Node));
  strcpy(newNode->data, x);

  if (list->head == NULL) {
    newNode->next = NULL; // 공백 리스트인 경우
    list->head = newNode; // 새 노드를 첫 번째이자 마지막 노드로 연결
  } else if (pre == NULL) { // 삽입 위치를 지정하는 포인터 pre가 NULL인 경우
    newNode->next = list->head;
    list->head = newNode;
  } else {
    newNode->next = pre->next; //포인터 pre의 노드 뒤에 새 노드 연결
    pre->next = newNode;
  }
}

// 마지막 노드로 삽입하는 연산
void insertLastNode(linkedList_h *list, char *x) {
  Node *newNode;
  Node *temp;
  newNode = (Node *)malloc(sizeof(Node));
  strcpy(newNode->data, x);
  newNode->next = NULL;
  if (list->head == NULL) { // 현재 리스트가 공백인 경우
    list->head = newNode; // 새 노드를 리스트의 시작 노드로 연결
    return;
  }

  // 현재 리스트가 공백이 아닌 경우
  temp = list->head;
  while (temp->next != NULL) {
    temp = temp->next; // 현재 리스트의 마지막 노드를 찾음
  }
  temp->next = newNode; // 새 노드를 마지막 노드(temp)의 다음 노드로 연결
}

// Anika lene

int main(void) {
  linkedList_h *L;
  L = createLinkedList_h();
  printf("(1) 공백 리스트 생성하기! \n");
  printList(L);

  printf("\n(2) 리스트에 [수] 노드 삽입하기!\n");
  insertFirstNode(L, "수");
  printList(L);

  printf("\n(3) 리스트 마지막에 [금] 노드 삽입하기!\n");
  insertLastNode(L, "금");
  printList(L);

  printf("\n(4) 리스트 첫 번째에 [월] 노드 삽입하기!\n");
  insertFirstNode(L, "월");
  printList(L);

  printf("\n(5) 리스트 공간을 해제하여 공백 리스트로 만들기!\n");
  freeLinkedList_h(L);
  printList(L);

  getchar();
  return 0;

}
