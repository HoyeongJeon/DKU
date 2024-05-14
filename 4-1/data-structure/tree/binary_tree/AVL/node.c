#include <stdio.h>
#include "node.h"

// 이진 탐색 트리 중위 순회
void displayInorder(treeNode* root) {
    if(root) {
        displayInorder(root->left);
        printf("%d_", root->key);
        displayInorder(root->right);
    }
}