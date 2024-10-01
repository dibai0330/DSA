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
    printf("%d",p->info);
}

void insert(Node* head){
    //插入元素，都采用尾插法，创建一个不带表头的链表
    Node* p = head;
    printf("要插入几个元素\n请输入要插入的元素，以空格隔开\n");
    int n,tmp,i;
    //n用于存储要插入的元素个数
    scanf("%d",&n);
    scanf("%d",&tmp);
    p->info = tmp;
    for(i=1; i<n; i++){
        scanf("%d",&tmp);
        Node *q = (Node*)malloc(sizeof(Node));
        q->info = tmp;
        q->next = NULL;
        p->next = q;
        p = q;
    }
}

Node* reverse(Node* now, Node* pre){
    //传参时就需要传入head的前一个结点pre
    //链表倒置，后一个结点的next指向前一个结点
    if(now==NULL){
        return  pre;
    }
    Node* p = now->next;
    now->next = pre;
    //倒置之后为不带表头的链表，返回倒置之后的表头
    return reverse(p,now);
}

int main(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->info = 0;
    head->next = NULL;

    insert(head);
    printf("原链表为：");
    PrintList(head);
    printf("\n倒置之后的链表为：");
    PrintList(reverse(head,NULL));
    return 0;
}