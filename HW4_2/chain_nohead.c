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

    //打印链表
    p = head;
    for(i=0; i<n; i++){
        printf("%d ",p->info);
        p = p->next;
    }
    printf("\n");
}

Node* number_loop(Node* head, int n){
    //输入n，返回指向第n个元素的指针，循环实现
    int i;
    if(n<=0){
        printf("error,请输入正确的数值\t");
        return NULL;
    }
    else{
        Node* p = head;
        for(i=1; i<n; i++){
            if(p->next != NULL) p = p->next;
            else{
                printf("error,请输入正确的数值\t"); 
                return 0;
            }    
        }
        return p;
    }
}

Node* number_recursion(Node* head, int n){
    //输入n，返回指向第n个元素的指针，递归实现
    if(n<1 || head==NULL){
        printf("error,请输入正确的数值\t"); 
        return NULL;
    }
    else if(n==1){
        return head;
    }
    return number_recursion(head->next, n-1);
}

Node* delete_key(Node* head, int key){
    //删除第一个值为key的元素，递归实现
    //因为递归调用，无法访问当前head的前一个结点，无法在递归函数中更改它的next指针，所以返回每次的head
    if(head == NULL){
        //若head为空，说明已经访问到最后一个结点，仍然没有找到key
        printf("元素%d在链表中不存在\n", key);
        return NULL;
    }
    else if(head->info == key){
        //若head的值为key，删除head，将head更新为head->next
        Node* p = head;     //p指向待删除的结点
        head = head->next;
        free(p);
        return head;
    }
    head->next = delete_key(head->next, key);
    return head;
}

int main(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;

    insert(head);

    int number;     //返回的元素序号，1-base
    printf("请输入要返回第几个元素(1-n)\n");
    scanf("%d",&number);
    printf("链表中第%d个元素的地址是%d\n", number, number_loop(head,number));
    printf("链表中第%d个元素的地址是%d\n", number, number_recursion(head,number));  

    int key;
    printf("请输入要删除的元素的数值\n");
    scanf("%d",&key);
    Node* head_now = delete_key(head, key);
    //打印修改后的链表
    printf("修改后的链表为：");
    while(head_now != NULL && head_now->next != NULL){
        printf("%d ",head_now->info);
        head_now = head_now->next;
    }
    printf("%d", head_now->info);
    return 0;
}

