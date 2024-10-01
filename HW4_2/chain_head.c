#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
        int info;
        struct Node* next;
    }Node;

void insert(Node* head){
    //插入元素，都采用尾插法
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

    //打印链表
    p = head->next;
    for(i=0; i<n; i++){
        printf("%d ",p->info);
        p = p->next;
    }
    printf("\n");
}

int number_loop(Node* head, int n){
    //输入n，返回指向第n个元素的指针，循环实现
    int i;
    if(n<=0){
        printf("error,请输入正确的数值\t");
        return 0;
    }
    else{
        Node* p = head->next;
        for(i=1; i<n; i++){
            if(p->next != NULL) p = p->next;
            else{
                printf("error,请输入正确的数值\t"); 
                return 0;
            }    
        }
        return p->info;
    }
}

int number_recursion(Node* head, int n){
    //输入n，返回指向第n个元素的指针，递归实现
    if(n<1 || head==NULL){
        printf("error,请输入正确的数值\t"); 
        return 0;
    }
    else if(n==1){
        return head->info;
    }
    return number_recursion(head->next, n-1);
}

int main(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->info = 0;
    head->next = NULL;

    insert(head);

    int number;     //返回的元素序号，1-base
    printf("请输入要返回第几个元素(1-n)\n");
    scanf("%d",&number);
    printf("链表中第%d个元素是%d\n", number, number_loop(head,number));
    //因为递归时数据结构需具有一致性，所以视作无表头的链表，找到第n+1个元素
    printf("链表中第%d个元素是%d\n", number, number_recursion(head,number+1));  

    return 0;
}

