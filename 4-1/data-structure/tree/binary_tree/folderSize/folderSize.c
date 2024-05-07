#include <stdio.h>
#include <stdlib.h>
#include "folderSize.h"

treeNode* makeRootNode(int size , treeNode* leftNode, treeNode* rightNode){
    treeNode* root = (treeNode*)malloc(sizeof(treeNode));
    root->size = size;
    root->left = leftNode;
    root->right = rightNode;
    return root;
}

// 폴더의 크기를 계산하기 위한 후위 순회 연산
int postorder_FolderSize(treeNode* root) {
    if(root) {
        postorder_FolderSize(root->left);
        postorder_FolderSize(root->right);
        FolderSize += root->size;
    }

    return FolderSize;
}