#include<stdio.h>
#define MAX 100

//栈的辅助函数
int isEmpty(int top){
    return top==-1;
}

int isFull(int top){
    return top == MAX -1;
}

int popStack(int* stack, int* top){
    if(!isEmpty(*top)){
        int value = stack[*top];
        (*top)--;
        return value;
    }
    else{
        printf("Error,栈已空\n");
        return 0;
    } 
}

void pushStack(int* stack, int* top, int value){
    (*top)++;
    stack[*top] = value;
}

void printStack(int* stack, int top){
    int i;
    for(i=0; i<=top; i++){
        printf("%d ", stack[i]);
    }
}

void ReverseStack(int* s1, int* top1, int size){//size为要倒置的栈中实际元素的数目，此次设为max
    int s2[MAX];    //s2为辅助的栈
    int top2 = -1;
    int tmp, num;
    //思路：将s1的元素倒进s2中，取出s2的栈顶num，将s2中元素倒回s1的时候，选择合适的时间放回num
    for(int times=1; times<size; times++){
        while(!isEmpty(*top1)){
            tmp = popStack(s1, top1);
            pushStack(s2, &top2, tmp);
        }
        num = popStack(s2, &top2);
        //第times次，放回size-times个元素后，放入num
        for(int i=0; i<size-times; i++){
            tmp = popStack(s2, &top2);
            pushStack(s1, top1, tmp);
        }
        pushStack(s1, top1, num);
        //还剩下times-1个元素，放回s1
        for(int i=0; i<times-1; i++){
            tmp = popStack(s2, &top2);
            pushStack(s1, top1, tmp);
        }
    }
}

int main(){
    int s1[MAX];
    int top1=-1;

    //初始化s1，不妨初始化为0 - MAX-1
    for(int i=0; i<MAX; i++){
        s1[i] = i;
    }
    top1 = MAX-1;
    printStack(s1, top1);
    printf("\n");

    ReverseStack(s1, &top1, MAX);
    printStack(s1, top1);

    return 0;
}