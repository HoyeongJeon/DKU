#include <stdio.h>

#define STACK_SIZE 100

int top = -1;

int stack[STACK_SIZE];

int isStackEmpty(void) {
  if (top == -1) {
    // stack is empty
    return 1;
  } else {
    // stack is not empty
    return 0;
  }
}

int isStackFull(void) {
  if (top == STACK_SIZE - 1) {
    // stack is full
    return 1;
  } else {
    // stack is not full
    return 0;
  }
}

void push(int item) {
  if (isStackFull()) {
    printf("\n\nStack is Full\n");
    return;
  } else {
    stack[++top] = item;
  }
}

int pop(void) {
  if (isStackEmpty()) {
    printf("\n\nStack is Empty\n");
    return 0;
  } else {
    return stack[top--];
  }
}

int peek(void) {
  if (isStackEmpty()) {
    printf("\n\nStack is Empty\n");
    return 0;
  } else {
    return stack[top];
  }
}

void printStack(void) {
  printf("\n STACK [ ");
  for (int i = 0; i <= top; i++) {
    printf("%d ", stack[i]);
  }
  printf("] ");
}

int main(void) {
  int item = 0;
  printf("\n** 순차 스택 연산 **\n");
  printStack();
  push(1);
  printStack();
  push(2);
  printStack();
  push(3);
  printStack();

  item = peek();
  printf("\n peek top => %d", item);

  item = pop();
  printf("\n pop top => %d", item);
  printStack();
  item = pop();
  printf("\n pop top => %d", item);
  printStack();
  item = pop();
  printf("\n pop top => %d", item);
  printStack();

  return 0;
}
