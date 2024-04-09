#include <stdio.h>
#include "stackL.h"

int main(void) {
    element item;
    top = NULL;
    printf("\n ** 순차 리스트 기반의 스택 연산 ** \n");
    printStack();

    push(1);
    printStack();
    push(2);
    printStack();   
    push(3);
    printStack();

    item = peek();
    printf("peek -> %d\n", item);
    printStack();

    item = pop();
    printf("pop -> %d\n", item);
    printStack();

    item = pop();
    printf("pop -> %d\n", item);
    printStack();

    item = pop();
    printf("pop -> %d\n", item);
    printStack();

    getchar();
    return 0;

}