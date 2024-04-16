#include <stdio.h>
#include <stdlib.h>
#include "deQue.h"

DQueType* createDQue(void) {
    DQueType* DQ;
    DQ = (DQueType*)malloc(sizeof(DQueType));
    DQ->front = NULL;
    DQ->rear = NULL;
    return DQ;
}

int isDeQEmpty(DQueType* DQ) {
    if(DQ->front == NULL) return 1;
    else return 0;
}


// 데크의 front로 원소를 삽입하는 연산
void insertFront(DQueType* DQ, element item) {
    DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode->data = item;
    if(isDeQEmpty(DQ)) {
        // 비어있는 경우
        DQ->front = newNode;
        DQ->rear = newNode;
        newNode->rlink = NULL;
        newNode->llink = NULL;
    } else {
        // 안비어있는 경우
        DQ->front->llink =  newNode;
        newNode->rlink = DQ->front;
        newNode->llink = NULL;
        DQ->front = newNode;
    }
}

// 데크의 rear뒤로 원소를 삽입하는 연산
void insertRear(DQueType* DQ, element item) {
    DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode->data = item;
    if(isDeQEmpty(DQ)) {
        // 비어있는 경우
        DQ->front = newNode;
        DQ->rear= newNode;
        newNode->llink = NULL;
        newNode->rlink = NULL;
    } else {
        // 안비어있는 경우
        DQ->rear->rlink = newNode;
        newNode->llink = DQ->rear;
        newNode->rlink = NULL;
        DQ->rear = newNode;
    }
}

// 데크의 front 노드를 삭제하고 반환하는 연산
element deleteFront(DQueType* DQ) {
    DQNode* old = DQ->front;
    element item;
    if(isDeQEmpty(DQ)) {
        printf("\n Linked deQue is empty! \n");
        return "Empty";
    } else {
        item = old->data;
        if(DQ->front->rlink == NULL) {
            DQ->front = NULL;
            DQ->rear = NULL;
        } else {
            DQ->front = DQ->front->rlink;
            DQ->front->llink = NULL;
        }
        free(old);
        return item;
    } 
}

// 데크의 rear 노드를 삭제하고 반환하는 연산
element deleteRear(DQueType* DQ) {
    DQNode* old = DQ->rear;
    element item;
    if(isDeQEmpty(DQ)) {
        printf("\n Linked deQue is empty! \n");
        return "Empty";
    } else {
        item = old->data;
        if(DQ->rear->llink == NULL) {
            DQ->front = NULL;
            DQ->rear = NULL;
        } else {
            DQ->rear = DQ->rear->llink;
            DQ->rear->rlink = NULL;
        }
        free(old);
        return item;
    }
}

// 데크의 front 노드의 데이터 필드를 반환하는 연산
element peekFront(DQueType* DQ) {
    element item;
    if(isDeQEmpty(DQ)) {
        // DQ가 비어있는 경우
        printf("\n Linked deQue is empty! \n");
        return "Empty";
    } else {
        item = DQ->front->data;
        return item;
    }
}

// 데크의 rear 노드의 데이터 필드를 반환하는 연산
element peekRear(DQueType* DQ) {
        element item;
    if(isDeQEmpty(DQ)) {
        // DQ가 비어있는 경우
        printf("\n Linked deQue is empty! \n");
        return "Empty";
    } else {
        item = DQ->rear->data;
        return item;
    }
}

void printDQ(DQueType* DQ) {
     DQNode* temp = DQ->front;
     printf("DeQue: [");
     while(temp) {
        printf("%3c",temp->data);
        temp = temp->rlink;
     }
     printf(" ] ");
}