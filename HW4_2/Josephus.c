#include<stdio.h>
#include<stdlib.h>

int main(){
    //读入数据
    int n,s,m,i,j=0;
    printf("请输入总人数n，开始报数的人s，报数m\n");
    scanf("%d %d %d",&n,&s,&m);
    //生成一个大小为n的数组，用于存储出列的结果
    int* result = (int*)malloc(n * sizeof(int));

    //生成一个单循环链表，节点数为n，不带表头
    typedef struct Node{
        int num;
        struct Node* next;
    }Node;
    Node* head = (Node*)malloc(sizeof(Node));
    Node* p = head;
    for(i=1; i<n; i++){
        p->num = i;
        Node* q = (Node*)malloc(sizeof(Node));
        p->next = q;
        p = q;
    }
    p->num = i++;
    p->next = head;
    
    //找到第s个人，指针指向s-1人方便后续操作
    //报数均为1-base
    for(i=1; i<s; i++){
        p = p->next;
    }
    
    //找到报数m的人，指针指向报数m-1的人方便后续操作,直到index=n-1
    while (j<n)
    {
       for(i=1; i<m; i++){
            p = p->next;
        }
        //报数m的人出列，即从链表中删除该结点
        Node* tmp;
        tmp = p->next;    //tmp指向该出列的结点
        p->next = tmp->next;
        result[j++] = tmp->num;
        free(tmp);
    }
    
    //输出结果
    for(i=0; i<n; i++){
        printf("%d ",result[i]);
    }
    return 0;
}