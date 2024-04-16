#pragma once

typedef struct Node {
    char data[4];
    struct Node* link;
} Node;

typedef struct {
    Node* head;
} LinkedList_h;

LinkedList_h* createLinkedList_h(void);
void freeLinkedList(LinkedList_h* L);
void printList(LinkedList_h* L);
void insertFirstNode(LinkedList_h* L, char * x);
void insertMiddleNode(LinkedList_h* L, char * x);
void insertLastNode(LinkedList_h* L, char * x);