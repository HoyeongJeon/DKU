#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *top; // Pointer for stack top Node;

int isStackEmpty(void) {
  if (top == NULL) {
    return 1;
  } else {
    return 0;
  }
}

void push(int item) {
  Node *temp = (Node *)malloc(sizeof(Node));

  temp->data = item;
  temp->next = top;
  top = temp;
}

int pop(void) {
  int item;
  Node *temp = top;

  if (isStackEmpty()) {
    printf("\n\n Stack is empty !\n");
    return 0;
  } else {
    item = temp->data;
    top = temp->next;
    free(temp);
    return item;
  }
}

int peek(void) {
  if (isStackEmpty()) {
    printf("\n\n Stack is empty !\n");
    return 0;
  } else {
    return top->data;
  }
}

void printStack(void) {
  Node *p = top;
  printf("\n STACK [ ");
  while (p) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("] ");
}

int main(void) {
  int item;
  top = NULL;

  printf("\n** 연결 스택 연산 **\n");

  printStack();
  push(1);
  printStack();
  push(2);
  printStack();
  push(3);
  printStack();

  item = peek();
  printStack();

  printf("peek => %d", item);
  return 0;
}
