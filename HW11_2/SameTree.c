#include<stdio.h>
#include"BuildTree.c"

int SameTree(Node* root1, Node* root2){
    //递归判断两棵树是否相同
    if(root1==NULL && root2==NULL)  return 1;
    else if(root1==NULL || root2==NULL) return 0;
    else if(root1->info != root2->info)  return 0;
    return(SameTree(root1->left, root2->left) && SameTree(root1->right, root2->right));
}

int main(){
    char pre1[50],middle1[50], pre2[50],middle2[50];
    printf("请输入树1的前序遍历结果\n");
    scanf("%s", pre1);
    printf("请输入树1的中序遍历结果\n");
    scanf("%s", middle1);
    printf("请输入树2的前序遍历结果\n");
    scanf("%s", pre2);
    printf("请输入树2的中序遍历结果\n");
    scanf("%s", middle2);
    Node* root1 = BuildTree(pre1, middle1);
    Node* root2 = BuildTree(pre2, middle2);

    if(SameTree(root1, root2))  printf("两棵树一样\n");
    else    printf("两棵树不一样\n");
    return 0;
}