#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char data[4];
  struct Node *link;
} Node;

typedef struct linkedList_h {
  Node *head;
} linkedList_h;

linkedList_h* createLinkedList_h(void) {
    linkedList_h* CL;
    CL = (linkedList_h *)malloc(sizeof(linkedList_h));
    CL->head = NULL; // 공백 리스트니까 head는 NULL
    return CL;
}

// 연결 리스트를 순서대로 출력하는 연산
void printList(linkedList_h *CL) {
    Node* p;
    printf("CL = (");
    p = CL->head;
    if(p == NULL) {
        printf(") \n");
        return;
    }
    do {
        printf("%s", p->data);
        p = p -> link;
        if(p != CL->head) {
            printf(", ");
        }
    } while (p != CL->head);
    printf(") \n");
}

void insertFirstNode(linkedList_h * CL, char *x) {
    Node* newNode, *temp;
    newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, x);
    if(CL->head == NULL) {
        CL->head = newNode;
        newNode->link = newNode;
    } else {
        temp = CL->head;
        while(temp->link != CL->head) {
            temp = temp->link;
        }
        newNode->link = temp->link;
        temp->link = newNode; // 마지막 노드를 첫 번째 노드인 newNode와 원형 연결
        CL->head = newNode;

    }
}

void insertMiddleNode(linkedList_h* CL, Node* pre, char* x) {
    Node* newNode;
    newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, x);
    if(CL->head == NULL) {
        CL->head = newNode;
        newNode->link = newNode;
    } else {
        newNode->link = pre->link;
        pre->link = newNode;
    }
}

void deleteNode(linkedList_h * CL, Node* old) {
    Node* pre;
    if(CL == NULL) { // 공백 리스트인 경우 삭제 연산 중단
        return ;
    } 

    if(CL->head->link == CL->head) { // 리스트에 노드가 하나만 있는 경우 
        free(CL->head);
        CL->head = NULL;
        return ;
    } else if(old == NULL) { // 삭제할 노드가 없는 경우 연산 중단
        return ;
    } else {
        pre = CL->head;
        while(pre->link != old) {
            pre = pre->link;
        }
        pre->link = old -> link;
        if(old == CL->head){
            CL->head = old->link;
        }
        free(old);
    }
}

Node* searchNode(linkedList_h * CL, char * x) {
    Node* temp;
    temp = CL->head;
    if(temp == NULL) {
        return NULL;
    }
    do {
        if(strcmp(temp->data, x) == 0) {
            return temp;
        } else {
            temp = temp->link;
        }
    } while(temp != CL->head); 
    return NULL;
}

int main(void) {
    linkedList_h * CL;
    Node* p;

    CL = createLinkedList_h();
    printf("(1) 원형 연결 리스트 생성하기! \n");
    printList(CL);

    printf("(2) 원형 연결 리스트에 [월] 노드 삽입하기! \n");
    insertFirstNode(CL, "월");
    printList(CL);

    printf("(3) 원형 연결 리스트의 [월] 노드 뒤에 [수] 노드 삽입하기! \n");
    p = searchNode(CL, "월");
    insertMiddleNode(CL, p, "수");
    printList(CL);

    printf("(4) 원형 연결 리스트 [수] 노드 뒤에 [금] 노드 삽입하기! \n");
    p = searchNode(CL, "수");
    insertMiddleNode(CL, p, "금");
    printList(CL);

    printf("(5) 원형 연결 리스트에서 [수] 노드 삭제하기! \n");
    p = searchNode(CL, "수");
    deleteNode(CL, p);
    printList(CL);

    getchar();
    return 0;

}



