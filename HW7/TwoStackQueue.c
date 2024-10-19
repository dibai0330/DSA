#include<stdio.h>
#define MAX 100 //设栈的最大容量为100

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

//进队函数
void enque(int* s1, int* s2, int* top1, int* top2, int value){
    if(!isFull(*top1)){
        pushStack(s1, top1, value);
    }
    else if(isFull(*top1) && (isEmpty(*top2))){
        pushStack(s2, top2, value);
    }
    else{
        printf("Error,队列已满，无法进队\n");
    }
}

//出队函数
int deque(int* s1, int* s2, int* top1, int* top2){
    int tmp,num;
    while (!isEmpty(*top1)){
        tmp = popStack(s1, top1);
        pushStack(s2, top2, tmp);
    }
    num = popStack(s2, top2);
    while (!isEmpty(*top2)){
        tmp = popStack(s2, top2);
        pushStack(s1, top1, tmp);
    }
    return num;
}

int main(){
    int stack1[MAX], stack2[MAX];
    int top1=99, top2=-1;
    for(int i=0; i<MAX; i++){
        stack1[i] = i;
    }

    int action;
    printf("请输入要进行的操作\n1入队 2出队 3打印当前队列");
    while(scanf("%d", &action) != EOF){
        if(action == 1){
            printf("请输入要入队的数字\n");
            int num;
            scanf("%d", &num);
            enque(stack1, stack2, &top1, &top2, num);
        }

        else if(action == 2){
            printf("当前出队的数字是%d\n", deque(stack1, stack2, &top1, &top2));
        }

        else if(action == 3){
            printStack(stack1, top1);
            if(!isEmpty(top2)){
                printf(" %d", stack2[0]);
            }
            printf("\n");
        }

        else    printf("Error,请输入1-3之间的数字\n");
        printf("请输入要进行的操作\n1入队 2出队 3打印当前队列");
    }
    return 0;
}