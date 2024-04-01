#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char Name[10];
  int phoneNum;
  struct Node *next;
} Node;

typedef struct linkedList_h {
  Node *head;
} linkedList_h;

// 공백 리스트 생성 함수
linkedList_h *CreateEmptyList() {
  linkedList_h *L;
  L = (linkedList_h *)malloc(sizeof(linkedList_h));
  L->head = NULL;
  return L;
}

// 노드 생성 함수
Node *CreateNode(const char *Name, int phoneNum) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  strcpy(newNode->Name, Name);
  newNode->phoneNum = phoneNum;
  newNode->next = NULL;

  return newNode;
}

// 웨이팅 등록 함수
// 리스트의 맨 뒤에 새로운 노드 추가
void AddWaiting(linkedList_h *List, Node *newNode) {
  printf("[웨이팅 등록] 고객명 %s가 대기열에 등록되었습니다.\n", newNode->Name);
  if (List->head == NULL) {
    List->head = newNode;
  } else {
    Node *current = List->head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
  return;
}

// 손님 입장 함수
// 리스트 맨 앞의 노드 삭제
void EnterCustomer(linkedList_h *List) {
  if (List->head == NULL) {
    printf("대기열이 비어있습니다.\n");
  } else {
    printf("[고객 입장] 고객 %s님이 입장하였습니다.\n", List->head->Name);
    Node *temp = List->head;
    List->head = List->head->next;
    free(temp);
  }
}

// 웨이팅 검색 함수
// 전화번호로 해당 노드 검색
// 순서 보여주기
void SearchWaiting(linkedList_h *List, int phoneNum) {
  int count = 1;
  if (List->head == NULL) {
    printf("대기열이 비어있습니다.\n");
  } else {
    Node *current = List->head;
    while (current != NULL) {
      if (current->phoneNum == phoneNum) {
        printf("[순서 출력] 이름: %s, 전화번호: %d, 순서: %d\n\n",
               current->Name, current->phoneNum, count);
        return;
      }
      current = current->next;
      count++;
    }
  }
  printf("전화번호 %d 를 가진 고객을 찾지 못했습니다.\n", phoneNum);
}

// 한칸 뒤로 미루는 함수

void Postpone(linkedList_h *List, const char *name) {
  if (List->head == NULL || List->head->next == NULL) {
    printf("대기열이 비어있거나, 이동할 고객이 없습니다.\n");
    return; // 함수 종료
  }

  Node *prev = NULL;
  Node *current = List->head;

  printf("[예약 한칸 뒤로 미루기] 이름: %s\n\n", name);

  while (current != NULL && current->next != NULL) {
    if (strcmp(current->Name, name) == 0) {
      Node *temp = current->next;
      if (prev != NULL) {
        // 첫 노드 X
        prev->next = temp;
      } else {
        // 첫 노드 O
        List->head = temp;
      }
      current->next = temp->next;
      temp->next = current;
      return;
    }
    prev = current;
    current = current->next;
  }
  printf("해당 이름의 고객을 찾을 수 없습니다.\n");
}

// 리스트 목록 출력
void PrintLinkedList(linkedList_h *List) {
  if (List->head == NULL) {
    printf("대기열이 비어있습니다.\n");
  } else {
    Node *current = List->head;
    while (current != NULL) {
      // 반복해서 출력
      printf("이름: %s, 전화번호: %d\n", current->Name, current->phoneNum);
      current = current->next;
    }
  }
}

void CancleWaiting(linkedList_h *List, int number) {
  if (List->head == NULL) {
    printf("대기열이 비어있습니다.\n");
    return;
  }
  Node *current = List->head;
  Node *prev = NULL;

  // 첫 번째 노드 삭제하는 경우
  if (current->phoneNum == number) {
    printf("[예약 취소] 이름: %s, 전화번호: %d\n\n", current->next->Name,
           current->next->phoneNum);
    List->head = current->next;
    free(current);
    return;
  }

  while (current != NULL && current->next != NULL) {
    if (current->next->phoneNum == number) {
      // 번호가 같은 경우
      printf("[예약 취소] 이름: %s, 전화번호: %d\n\n", current->next->Name,
             current->next->phoneNum);
      Node *temp = current->next;
      current->next = temp->next;
      free(temp);
      break;
    }
    current = current->next;
  }
}

int main() {
  linkedList_h *List = CreateEmptyList();
  Node *Alice = CreateNode("Alice", 2747);
  Node *Bob = CreateNode("Bob", 7821);
  Node *Charlie = CreateNode("Charlie", 4722);
  Node *David = CreateNode("David", 5683);
  Node *Edison = CreateNode("Edison", 9715);
  Node *Fiona = CreateNode("Fiona", 3718);

  PrintLinkedList(List);
  printf("\n");

  AddWaiting(List, Alice);
  PrintLinkedList(List);
  printf("\n");

  AddWaiting(List, Bob);
  PrintLinkedList(List);
  printf("\n");

  AddWaiting(List, Charlie);
  PrintLinkedList(List);
  printf("\n");

  AddWaiting(List, David);
  PrintLinkedList(List);
  printf("\n");

  EnterCustomer(List);
  PrintLinkedList(List);
  printf("\n");

  AddWaiting(List, Edison);
  PrintLinkedList(List);
  printf("\n");

  EnterCustomer(List);
  PrintLinkedList(List);
  printf("\n");

  Postpone(List, "David");
  PrintLinkedList(List);
  printf("\n");

  AddWaiting(List, Fiona);
  PrintLinkedList(List);
  printf("\n");

  SearchWaiting(List, 7821);
  PrintLinkedList(List);
  printf("\n");

  CancleWaiting(List, 4722);
  PrintLinkedList(List);
  printf("\n");

  EnterCustomer(List);
  PrintLinkedList(List);
  printf("\n");
  return 0;
}
