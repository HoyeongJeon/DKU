#pragma once
typedef struct treeThNode
{
    char data;
    struct treeThNode *left;
    struct treeThNode *right;
    int isThreadRight; // 후속자에 대한 스레드 여부
}treeThNode;


treeThNode* makeRootThNode(char data, treeThNode* leftNode, treeThNode* rightNode, int isThreadRight);
treeThNode* findThreadSuccessor(treeThNode* p);
void threadInorder(treeThNode* root);

