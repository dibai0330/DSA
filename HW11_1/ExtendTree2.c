#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char info;
    struct Node* left;
    struct Node* right;
}Node;

//辅助函数，创建结点
Node* CreateNode(char info, Node* left, Node* right){
    Node* new = (Node*)malloc(sizeof(Node));
    new->info = info;
    new->left = left;
    new->right = right;
    return new;
}

void ExtendTree(Node** root){
    if(*root==NULL){
        *root = CreateNode('#', NULL, NULL);
        return;
        }
    ExtendTree(&(*root)->left);
    ExtendTree(&(*root)->right);
}

//前序遍历二叉树
void preorder(Node* root) {
    if(root == NULL)    return;
    printf("%c ", root->info);
    preorder(root->left);
    preorder(root->right);
}

int main(){
    // 示例树结构:
    //        1
    //       / \
    //      2   3
    //         / \
    //        4   5
    Node* root1 = CreateNode('1', NULL,NULL);
    root1->left = CreateNode('2', NULL,NULL);
    root1->right = CreateNode('3', NULL,NULL);
    root1->right->left = CreateNode('4', NULL,NULL);
    root1->right->right = CreateNode('5', NULL,NULL);
    ExtendTree(&root1);
    preorder(root1);
    printf("\n");

    //测试样例2为一棵空树
    Node* root2 = NULL;
    ExtendTree(&root2);
    printf("空树的遍历结果： ");
    preorder(root2);
    printf("\n");
    return 0;
}
