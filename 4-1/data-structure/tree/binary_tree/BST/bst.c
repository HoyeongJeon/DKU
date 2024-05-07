#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "bst.h"

// 이진 탐색 트리에서 키값이 x인 노드의 위치 탐색
treeNode* searchBST(treeNode* root, element x) {
    treeNode* p;
    p = root;
    while (p != NULL)
    {
        if(x < p->key) {
            p = p->left;
        } else if(x == p->key) {
            return p;
        } else {
            p = p->right;
        }
    }
    printf("\n 찾는 키값이 트리에 없습니다.");
    return p;
}

// 포인터 p가 가리키는 노드와 비교해 노드 x를 삽입하는 연산
treeNode* insertNode(treeNode* p, element x) {
    treeNode* newNode;
    if(p == NULL) {
        newNode = (treeNode*)malloc(sizeof(treeNode));
        newNode->key = x;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    } else if(x < p->key) {
        p->left = insertNode(p->left, x);
    } else if(x > p->key) {
        p->right = insertNode(p->right, x);
    } else {
        printf("\n 이미 같은 키가 있습니다.");
    }
}

void deleteBSTNode(treeNode* root, element key) {}