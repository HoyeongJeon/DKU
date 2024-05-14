#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "bst.h"

// 이진 탐색 트리에서 키값이 x인 노드의 위치를 탐색하는 연산
treeNode* searchBST(treeNode* root, element x) {
    treeNode* p;
    int count = 0;
    p = root;
    while (p != NULL)
    {
        count++;
        if(x < p->key) {
            p = p->left;
        } else if(x == p->key) {
            printf("%3d번째에 탐색 성공", count);
            return p;
        } else {
            p = p->right;
        }
    }
    printf("\n %3d번째에 탐색 실패! 찾는 키가 없습니다!",count);
    return p;
}

// 포인터 p가 가리키는 노드와 비교하여 노드 x를 삽입하는 연산
treeNode* insertBSTNode(treeNode* p, element x) {
    treeNode* newNode;
    if(p == NULL) {
        newNode = (treeNode *)malloc(sizeof(treeNode));
        newNode->key = x;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    } else if(x < p->key) {
        p->left = insertBSTNode(p->left, x);
    } else if(x > p->key) {
        p->right = insertBSTNode(p->right, x);
    } else {
        printf("\n 이미 같은 키가 있습니다! \n");
    }

    return p;
}

// 루트 노드부터 탐색해 키값과 같은 노드를 찾아 삭제하는 연산
void deleteBSTNode(treeNode* root, element key) {}