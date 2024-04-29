#pragma once

typedef struct ListNode
{
    char data[4];
    struct ListNode* link;
}listNode;

typedef struct linkedList_h
{
    listNode* head;
} linkedList_h;


linkedList_h* createLinkedList_h(void);
void printList(linkedList_h* CL);
void insertFirstNode(linkedList_h* CL, char* x);
void insertMiddleNode(linkedList_h* CL, listNode* pre, char* x);
void deleteNode(linkedList_h* CL, listNode* pre, char* x);
listNode* searchNode(linkedList_h* CL, char* x);