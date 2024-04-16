#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

// 공백 큐 생성하는 연산
LQueueType* createLinkedQueue(void) {
    LQueueType* LQ;
    LQ = (LQueueType*)malloc(sizeof(LQueueType));
    LQ->front = NULL;
    LQ->rear = NULL;    
    return LQ;
}

// 공백 큐인지 검사하는 연산
int isEmpty(LQueueType* LQ) {
    if(LQ->front == NULL) {
        printf("\n Linked Queue is empty! \n");
        return 1;
    } else {
        return 0;
    } 
}

// 큐에 원소를 삽입하는 연산
void enQueue(LQueueType* LQ, element item) {
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = item;
    newNode->link = NULL;
    // 현재 연결 큐가 공백인 경우
    if(LQ->front == NULL) {
        LQ->front = newNode;
        LQ->rear = newNode;
    } else {
    // 현재 연결 큐가 공백이 아닌 경우
        LQ->rear->link = newNode; // 마지막 노드의 링크 필드를 새로운 노드를 가리키도록 설정
        LQ->rear = newNode; // rear가 새로운 노드를 가리키도록 설정
    }
}

// 큐에서 원소를 삭제하는 연산
element deQueue(LQueueType* LQ) {
    QNode* old = LQ->front;
    element item;
    if(isEmpty(LQ)) {
        return ;
    } else {
        item = old->data;
        LQ->front = LQ->front->link;
        if(LQ->front == NULL) {
            LQ->rear = NULL;
        }
        free(old);
        return item;
    }
}

element peekQ(LQueueType* LQ) {
    element item;
    if(isEmpty(LQ)) {
        return;
    } else {
        item = LQ->front->data;
        return item;
    }
}

void printQ(LQueueType* LQ){
        QNode* temp = LQ->front;
        printf("Linked Queue: [");
        while(temp) {
            printf("%3c", temp->data);
            temp = temp->link;
        }
        printf(" ] ");
}