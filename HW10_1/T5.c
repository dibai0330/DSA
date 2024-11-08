#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int node;
    struct Node* left;
    struct Node* right;
}Node;

//计算叶结点数的递归函数
int CountLeaves(Node* node){
    if(node==NULL)  return 0;
    else if(node->left==NULL && node->right==NULL)   return 1;
    return(CountLeaves(node->left) + CountLeaves(node->right));
}

//辅助函数，创建结点
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->node = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // 示例树结构:
    //        1
    //       / \
    //      2   3
    //         / \
    //        4   5
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->right->left = createNode(4);
    root->right->right = createNode(5);

    printf("一共有%d个叶结点\n", CountLeaves(root)); 
    return 0;
}
