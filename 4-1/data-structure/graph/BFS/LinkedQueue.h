#pragma once
typedef int element;

typedef struct QNode { // 연결 큐의 노드를 구조체로 정의
    element data;
    struct QNode* link;
}QNode;

typedef struct { // 연결 큐에서 사용하는 포인터 front와 rear를 구조체로 정의
    QNode* front, *rear;
}LQueueType;

LQueueType* createLinkedQueue(void); // 공백 연결 큐를 생성하는 연산
int isEmpty(LQueueType* Q);
void enQueue(LQueueType* Q, element item); 
element deQueue(LQueueType* Q);
element peekQ(LQueueType* Q);
void printQ(LQueueType* Q);