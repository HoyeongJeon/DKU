#pragma once
typedef int element;

typedef struct stackNode { // 스택의 노드를 구조체로 정의
    element data;
    struct stackNode* link;
}stackNode;

stackNode* top; // stack의 top 노드를 저장하기 위한 포인터 top;

int isStackEmpty(void);
void push(element item);
element pop(void);
element peek(void);
void printStack(void);