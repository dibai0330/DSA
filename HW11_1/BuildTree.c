#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
    int info;
    struct Node* left;
    struct Node* right;
}Node;

//辅助函数，创建树的结点
Node* CreateNode(int info, Node* left, Node* right){
    Node* new = (Node*)malloc(sizeof(Node));
    new->info = info;
    new->left = left;
    new->right = right;
}

//辅助函数，返回字符串s索引为i到j之间的子串
void substr(char* s, char* result, int i, int j){
    int resi=0;
    for(int k=i; k<=j; k++){
        result[resi ++] = s[k];
    }
    result[resi] = '\0';
}

Node* BuildTree(char* pre, char* middle){
    int length = strlen(pre);
    if(length == 0){
        return NULL;
    }

    //左子树为middle中 0~pre[0]-1 之间的，右子树为 pre[0]+1~end 之间的，确定左右子树
    char root = pre[0];
    int left_length, right_length;
    for(int i=0; i<length; i++){
        if(root == middle[i])    left_length=i;
    }
    right_length = length - 1 - left_length;

    //得到左右子串的遍历结果
    char left_pre[50], right_pre[50], left_middle[50], right_middle[50];    
    substr(pre, left_pre, 1, left_length);
    substr(pre, right_pre, left_length+1, length);
    substr(middle, left_middle, 0, left_length-1);
    substr(middle, right_middle, left_length+1, length-1);
    
    Node* left = BuildTree(left_pre, left_middle);
    Node* right = BuildTree(right_pre, right_middle);
    int rootNum = pre[0]-'0';   //将字符转为数字
    return CreateNode(rootNum, left, right);
}

//前序遍历二叉树
void preorder(Node* root) {
    if(root == NULL)    return;
    printf("%d ", root->info);
    preorder(root->left);
    preorder(root->right);
}
//中序遍历
void middleorder(Node* root){
    if(root == NULL)    return;
    middleorder(root->left);
    printf("%d ", root->info);
    middleorder(root->right);
}
//后序遍历
void lastorder(Node* root){
    if(root == NULL)    return;
    lastorder(root->left);
    lastorder(root->right);
    printf("%d ", root->info);
}

int main(){
    char pre[50],middle[50];
    printf("请输入前序遍历结果\n");
    scanf("%s", pre);
    printf("请输入中序遍历结果\n");
    scanf("%s", middle);

    Node* root = BuildTree(pre, middle);
    preorder(root);
    printf("\n");
    middleorder(root);
    printf("\n");
    lastorder(root);
    printf("\n");
    return 0;
}