#pragma once
typedef char element; // 이진 탐색 트리 element의 자료형 정의

typedef struct treeNode {
    element key;
    struct treeNode* left;
    struct treeNode* right;
}treeNode;

void displayInorder(treeNode* root);