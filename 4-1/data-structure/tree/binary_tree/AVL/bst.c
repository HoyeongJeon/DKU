#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "bst.h"

// 이진트리 탐색
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

// 이진트리 삽입
// 포인터 p가 가리키는 노드와 비교하여 노드 x를 삽입하는 연산
treeNode* insertBSTNode(treeNode* p, element x) {
    treeNode* newNode;
    if(p == NULL) { // 트리가 공백이면 새로운 노드를 생성
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
void deleteBSTNode(treeNode* root, element key) {
    treeNode* parent, *p, *succ, *succ_parent; // succ는 후계자 노드, succ_parent는 후계자 노드의 부모 노드, parent는 삭제할 노드의 부모 노드, p는 삭제할 노드
    treeNode* child; // 삭제할 노드의 자식 노드

    parent = NULL;
    p = root;

    while((p != NULL) && (p->key != key)) { // 삭제할 노드 탐색
        parent = p;
        if(key < p->key) {
            p = p->left;
        } else {
            p = p->right;
        }
    }

    // 삭제할 노드가 없는 경우
    if (p == NULL) {
        printf("\n 찾는 키가 이진 탐색 트리에 없습니다! \n");
        return;
    }


    // 삭제할 노드가 단말 노드인 경우
    if((p->left == NULL) && (p->right == NULL)) {
        if(parent != NULL) {
            if(parent->left == p) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        } else {
            root = NULL; // 삭제할 노드가 루트 노드인 경우
        }
    }
    // 삭제할 노드가 자식 노드를 한 개 가진 경우
    else if((p->left == NULL) || (p->right == NULL)) {
        if(p->left != NULL) {
            child = p->left;
        } else {
            child = p->right;
        }

        if(parent != NULL) {
            if(parent->left = p) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        } else {
            root = child;
        }
    }
    // 삭제할 노드가 자식 노드를 두 개 가진 경우
    else {
        succ_parent = p;
        succ = p->left;
        while (succ->right != NULL) {
            succ_parent = succ;
            succ = succ->right;
        }
        if (succ_parent->left == succ) {
            succ_parent->left = succ->left;
        } else {
            succ_parent->right = succ->left;
        }
        p->key = succ->key;
        p = succ;
    }
    free(p);
}