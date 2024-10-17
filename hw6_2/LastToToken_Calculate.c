#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

//栈的辅助函数
int isEmpty(int top){
    return (top==-1) ? 1 : 0;
}

void push(int* stack, int* top, int value){
    if(*top < 99){//假设栈的最大容量为100
        (*top)++;
        stack[*top] = value;
    }
    else{
        printf("栈已满\n");
    }
}

int pop(int* stack, int* top){
    if(*top == -1){
        printf("栈已空\n");
        return 0;
    }
    else{
        int value = stack[*top];
        (*top)--;
        return value;
    }
}

int result(char* expr){
    //初始化栈
    int stack[100];
    int top = -1;

    //分割字符串为token
    char* token;
    //创建表达式的副本以便分割，strdup用于复制一个字符串并且返回指向该字符串的指针
    char* copy = strdup(expr); 
    token = strtok(copy, " ");

    //利用栈计算后缀表达式
    while (token != NULL){
        //如果是数字，进栈
        if(isdigit(token[0])){
            push(stack, &top, atoi(token)); //atoi函数可以将字符串转为int
        }
        //如果是操作符，栈顶两个元素出栈，运算，然后结果重新进栈
        else{
            if(top < 1){//栈中少于两个元素，有问题
                printf("操作符和操作数的数量不匹配，表达式有误\n");
                return 0;
            }
            int op1,op2,res;
            op1 = pop(stack, &top);
            op2 = pop(stack, &top);
            switch(token[0]){
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op2 - op1;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':{
                    if(op1 != 0) res = op2 / op1;
                    else{
                        printf("除数不能为0\n");
                        return 0;
                    }
                }
                    break;      
            }
            push(stack, &top, res);
        }

        //后续调用时传入NULL,表示继续从上一次停止的地方查找下一个token,strtok会自动维护一个内部指针
        token = strtok(NULL, " ");
    }
    return pop(stack, &top);
}

int main(){
    char expr[100];
    printf("请输入后缀表达式\n");
    fgets(expr, sizeof(expr), stdin);
    //去掉换行符
    expr[strcspn(expr, "\n")] = '\0';
    printf("结果是%d\n", result(expr));
    return 0;
}