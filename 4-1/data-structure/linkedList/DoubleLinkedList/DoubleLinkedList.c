#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoubleLinkedList.h"

linkedList_h* createLinkedList(void) {
    linkedList_h* DL;
    DL = (linkedList_h*)malloc(sizeof(linkedList_h));
	DL->head = NULL;
	return DL;
}

void printList(linkedList_h* DL) {
	listNode* temp;
	printf("DL = [ ");
	temp = DL->head;
	while(temp) {
		printf("%s", temp->data);
		temp = temp->rlink;
		if(temp != NULL) printf(", ");
	}
	printf("] \n");
}

void insertNode(linkedList_h* DL, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if(DL->head == NULL) {
		newNode->llink = NULL;
		newNode->rlink = NULL;
		DL->head = newNode;
	} else {
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		if(newNode->rlink != NULL) {
			newNode->rlink->llink = newNode;
		}
	}
}

void deleteNode(linkedList_h* DL, listNode* old) {
	if(DL->head == NULL) return;
	else if (old == NULL) return;
	else {
		old->rlink->llink = old->llink;
		old->llink->rlink = old->rlink;
		free(old);
		return;
	}
}

listNode* searchNode(linkedList_h* DL, char* x) {
	listNode* temp;
	temp = DL->head;
	strcpy(temp->data, x);
	while(temp != NULL) {
		if(strcmp(temp->data, x) == 0) return temp;
		else temp = temp->rlink;
	}
	return temp;
}

