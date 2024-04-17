#include <stdio.h>
#include <stdlib.h>
#include "stackL.h"

int isStackEmpty(void) {
    if(top == NULL) return 1;
    else return 0;
}

void push(element item) {
    stackNode* temp = (stackNode*)malloc(sizeof(stackNode));

    temp->data = item;
    temp->link = top; // temp의 link에 top에 저장되어 있는 주소를 지정
    top = temp; // top에 temp의 주소를 저장
}

element pop(void) {
    element item;
    stackNode* temp = top;
    if(isStackEmpty()) {
        printf("\n stack is Empty! \t\n");
        return "empty";
    } else {
        item = temp->data;
        top = temp->link;
        free(temp);
        return item;
    }
}

element peek(void) {
    element item;
    stackNode* temp = top;
    if(isStackEmpty()) {
        printf("\n stack is Empty! \t\n");
        return "empty";
    } else {
        item = temp->data;
        return item;
    }
}

void printStack(void) {
    stackNode* p = top;
    printf("\nStack [ ");
    while(p) {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("] ");
}