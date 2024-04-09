#pragma once
typedef char element; // 스택 원소의 자료형을 int로 정의

typedef struct stackNode { // 스택의 노드를 구조체로 정의
    element data;
    struct stackNode* link;
} stackNode;

stackNode * top; // 스택의 top 노드를 가리키는 포인터

int isStackEmpty(); // 스택이 비어있는지 확인하는 함수
void push(element item); // 스택에 원소를 삽입하는 함수
element pop(); // 스택의 top 노드를 삭제하고 반환하는 함수
element peek(); // 스택의 top 노드를 반환하는 함수
void printStack(); // 스택의 모든 원소를 출력하는 함수