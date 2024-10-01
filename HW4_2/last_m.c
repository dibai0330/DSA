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

Node* find_m(Node* head, int m){
    //查找倒数第m个元素：双指针，间隔为m，p到达最后一个元素的后一个时，q到达倒数第m个
    Node* p = head;
    Node* q = head;
    for(int i=0; i<m; i++){
       if(p != NULL) p = p->next;
    }
    if(p == NULL){
        printf("error,链表中的元素总数少于%d,",m);
        return NULL;
    }
    else{
        while(p!=NULL){
            p = p->next;
            q = q->next;
        }
        printf("倒数第%d个结点的值是%d\n", m, q->info);
        return q;
    }
}

int main(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->info = 0;
    head->next = NULL;

    insert(head);
    printf("原链表为：");
    PrintList(head->next);

    int m;
    printf("输入想查找倒数第几个结点\n");
    scanf("%d",&m);
    printf("倒数第%d个结点的地址是%d\n", m, find_m(head,m));

    return 0;
}