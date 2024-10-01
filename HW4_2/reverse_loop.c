#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
        int info;
        struct Node* next;
    }Node;

void PrintList(Node* head){
    //打印链表
    Node* p = head;
    while(p!=NULL && p->next!=NULL){
        printf("%d ",p->info);
        p = p->next;
    }
    printf("%d\n",p->info);
}

void insert(Node* head){
    //插入元素，都采用尾插法，创建一个带表头的链表
    Node* p = head;
    printf("要插入几个元素\n请输入要插入的元素，以空格隔开\n");
    int n,tmp,i;
    //n用于存储要插入的元素个数
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&tmp);
        Node *q = (Node*)malloc(sizeof(Node));
        q->info = tmp;
        q->next = NULL;
        p->next = q;
        p = q;
    }
}

Node* reverse(Node* head){
    Node* p = head->next;
    Node* q;
    Node* re = NULL;
    //re为倒置之后的链表表头，倒置之后是不带表头的链表
    //p指向结点，将p从原链表上移动到倒置之后的链表上，直接将p插在re前，更新re
    while(p->next != NULL){
        q = p->next;
        p->next = re;
        re = p;
        p = q;
    }
    //原链表的最后一个，直接插在re前
    p->next = re;
    return p;
}

int main(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->info = 0;
    head->next = NULL;

    insert(head);
    printf("原链表为：");
    PrintList(head->next);
    printf("\n倒置之后的链表为：");
    PrintList(reverse(head));
    return 0;
}