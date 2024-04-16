#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "InsertLinkedList.h"

// 링크드리스트 생성
LinkedList_h * createLinkedList_h(void) {
    LinkedList_h* L;
    L = (LinkedList_h *)malloc(sizeof(LinkedList_h));
    L->head = NULL;
    return L;
}

void freeLinkedList(LinkedList_h* L) {
    Node* temp;
    while (L->head != NULL) 
    {
        temp = L->head;
        L->head = L->head->link;
        free(temp);
        temp = NULL;
    }
}

void printList(LinkedList_h* L) {
    Node* temp;
    printf("L = (");
    temp = L->head;
    while (temp != NULL)
    {
        printf("%s", temp->data);
        temp = temp->link;
        if(temp !=NULL) {
            printf(", ");
        }
    }
    printf(") \n");
}