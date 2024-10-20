#include<stdio.h>
#include<stdlib.h>

int W[10] = {0};    //保存各个物品的重量，初始化为0

typedef struct{//栈帧的结构
    int s;  //剩余的容量
    int n;  //剩余物品数量
    int keep;   //递归时是否完成了package(s,n)的阶段
}StackFrame;

typedef struct{//栈的结构
    StackFrame* data;   //指向栈帧的指针
    int top;
    int capacity;
}Stack;

//栈的辅助函数
int isEmpty(Stack* stack){
    return stack->top == -1;
}

void pushStack(Stack* stack, int s, int n, int keep){
    if(stack->top < stack->capacity-1){
        stack->top++;
        stack->data[stack->top].s = s;
        stack->data[stack->top].n = n;
        stack->data[stack->top].keep = keep;
    }
    else    printf("Error,栈已满，无法进栈");
}

StackFrame popStack(Stack* stack){
    StackFrame tmp = stack->data[stack->top];
    stack->top--;
    return tmp;
}

StackFrame readStackTop(Stack* stack){
    return stack->data[stack->top];
}

void package(int s, int n){
    //栈的初始化，设最大容量是100
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (StackFrame*)malloc(100*sizeof(StackFrame)); 
    stack->top = -1;
    stack->capacity = 100;

    int result=0;   //是否能实现背包恰好装满
    pushStack(stack, s, n, 0);

    while(!isEmpty(stack)){
        StackFrame now = readStackTop(stack);   //保存当前的栈
        if(now.s ==0){
            result =1;
            break;
        }
        else if(now.s<0 || (now.s>0 && now.n<1)){
            //这种装填方式失败
            popStack(stack);
            continue;
        }
        else if(now.keep ==0){
            pushStack(stack, now.s-W[now.n], now.n-1, 0);
            stack->data[stack->top -1].keep = 1;    //记为已经进行过
        }
        else{
            if(result ==1){
                printf("%d ", W[now.n]);
            }
            popStack(stack);
        }
    }
    
    if(result ==1)  printf("\n可以成功装填背包");
    else    printf("\n不能成功装填背包");
}

int main(){
    int s,n,i;
    printf("请输入物品数量n和背包容量s,以空格隔开(n<10)\n");
    scanf("%d %d", &n, &s);
    printf("请输入各个物品的重量，以空格隔开\n");
    for(i=0; i<n; i++){
        scanf("%d", &W[i+1]);   //背包问题的物品编号一般从1开始
    }
    package(s,n);
    return 0;
}