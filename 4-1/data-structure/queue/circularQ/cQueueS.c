#include <stdio.h>
#include <stdlib.h>
#include "cQueueS.h"  

// Create a new circular queue
QueueType* createQueue(void) {
    QueueType* cQ;
    cQ = (QueueType*)malloc(sizeof(QueueType));
    cQ->front = 0;
    cQ->rear = 0;    
    return cQ;
}

// Check if the circular queue is empty
int isCQueueEmpty(QueueType* cQ) {
    if(cQ->front == cQ->rear) {
        printf("Circular Queue is empty!\n");
        return 1;
    } else {
        return 0;
    }
}

// Check if the circular queue is full
int isCQueueFull(QueueType* cQ) {
    if((cQ->rear + 1) % cQ_SIZE == cQ->front) {
        printf("Circular Queue is full!\n");
        return 1;
    } else {
        return 0;
    }
}

void enCQueue(QueueType* cQ, element item) {
    if(isCQueueFull(cQ)) {
        return;
    } else {
        cQ->rear = (cQ->rear + 1) % cQ_SIZE;
        cQ->queue[cQ->rear] = item;
    }
}

element deCQueue(QueueType* cQ) {
    if(isCQueueEmpty(cQ)) {
        return "empty";
    } else {
        cQ->front = (cQ->front + 1) % cQ_SIZE;
        return cQ->queue[cQ->front];
    }
}

element peekCQ(QueueType* cQ) {
    if(isCQueueEmpty(cQ)) {
        return "empty";
    } else {
        return cQ->queue[(cQ->front + 1) % cQ_SIZE];
    }
}

// 다시 보기 ?
void printCQ(QueueType* cQ) {
    int i, first, last;
    first = (cQ->front + 1) % cQ_SIZE;
    last = (cQ->rear + 1) % cQ_SIZE;
    printf("Circular Queue: [");
    i = first;
    while (i!=last) {
        printf("%3c", cQ->queue[i]);
        i = (i + 1) % cQ_SIZE;
    }
    printf(" ]\n");
}