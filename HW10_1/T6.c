#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int node;
    struct Node* left;
    struct Node* right;
}Node;

//求最大值
int max(int a, int b){
    return (a>b) ? a : b;
}

//递归计算树高度的函数
int height(Node* root){
    if(root==NULL)  return 0;
    else if(root->left==NULL && root->right==NULL)  return 1;
    return (1 + max(height(root->left), height(root->right)));
}

//辅助函数，创建结点
Node* createNode(int value) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->node = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

int main(){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->right->left = createNode(4);
    root->right->right = createNode(5);

    printf("树的高度是%d\n", height(root)); 
    return 0;
}