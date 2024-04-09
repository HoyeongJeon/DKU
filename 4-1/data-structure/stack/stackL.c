#include <stdlib.h>
#include <stdio.h>
#include "stackL.h"

// 스택이 비어있는지 확인
int isStackEmpty(void) {
  if(top == NULL) {
    return 1;
  } else {
    return 0;
  }
}

// 스택의 top에 원소를 삽입하는 연산
void push(element item) {
  stackNode *temp = (stackNode *)malloc(sizeof(stackNode));

  temp->data = item;
  temp->link = top;
  top = temp;
}

// 스택의 top에서 원소를 삭제하는 연산
element pop(void) {
  element item;
  stackNode *temp = top;

  if(isStackEmpty()) {
    printf("\n\n 스택이 비어있음! \n");
    return 0;
  } else {
    item = temp->data;
    top = temp->link;
    free(temp);
    return item;
  }
}

element peek(void) {
  stackNode *temp = top;

  if(isStackEmpty()) {
    printf("\n\n 스택이 비어있음! \n");
    return 0;
  } else {
    return top->data;
  }
}

void printStack(void) {
  if(isStackEmpty()) {
    printf("\n\n 스택이 비어있음! \n");
  } else {
    stackNode *temp = top;
    printf("\n 스택의 내용 : [ ");
    while(temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->link;
    }
    printf("] \n");
  }
}