#pragma once

typedef struct listNode {
    struct listNode* llink;
    struct listNode* rlink;
    char data[4];
} listNode;


typedef struct linkedList_h {
    struct listNode* head;
}linkedList_h;

linkedList_h* createLinkedList(void);
void printList(linkedList_h* DL);
void insertNode(linkedList_h* DL, listNode* pre, char* x);
void deleteNode(linkedList_h* DL, listNode* old);
listNode* searchNode(linkedList_h* DL, char* x);