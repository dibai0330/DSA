#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

//中缀表达式转换为后缀表达式思路：读入input，如果是数字：直接添加到output，如果是左括号：压栈，右括号：弹栈
//运算符：与栈中运算符比较优先级，弹出栈中优先级≥当前的，当前压栈；input处理完全部弹栈

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

int order(char op){
    //辅助函数，返回操作符op的优先级
    int order=0;
    if(op=='+' || op=='-')  order=1;
    else if(op=='*' || op=='/') order=2;
    return order;
}

void getLast(char* middle, char* last){//不能在函数中申请last变量，会因为所在栈被销毁而得不到返回值
    int stack[100];
    int top=-1;

    int i=0, j=0;   //分别指向last和middle中的当前字符
    for(i=0; middle[i]!='\0'; i++){
        if(isdigit(middle[i])){
            //如果是数字，可能是多位数
            while(isdigit(middle[i])){
                last[j] = middle[i];
                i++;
                j++;
            }
            last[j] = ' ';    //空格隔开后缀表达式的元素
            j++;
            i--;    //易错：while循环中i++，已经指向了数字后的第一个字符，for循环还会i++
        }

        else if(middle[i]=='+' || middle[i]=='-' || middle[i]=='*' || middle[i]=='/'){
            //如果是操作符，比较优先级
            while((!isEmpty(top)) && (order(stack[top]) > order(middle[i]) || order(stack[top]) == order(middle[i]))){
                last[j] = pop(stack, &top);
                j++;
                last[j] = ' ';
                j++;
            }
            push(stack, &top, middle[i]);   //当前操作符进栈
        }

        else if(middle[i] == '('){
            push(stack, &top, middle[i]);
        }

        else if(middle[i] == ')'){
            while(stack[top] != '('){
                last[j] = pop(stack, &top);
                j++;
                last[j] = ' ';    //弹栈得到的都是操作符，用空格隔开
                j++;
            }
        pop(stack, &top);    //弹出左括号
        }

        else if(middle[i] == ' ')    continue;   //注意空格的处理
        else{
            printf("不是正确的表达式，请输入正确的表达式\n");
            last[0] = '\0';
            return;
        }
    }
    //栈中剩下的元素弹栈
    while(!isEmpty(top)){
        last[j] = pop(stack, &top);
        j++;
        last[j] = ' ';
        j++;
    }
    last[j] = '\0';
}

int main(){
    char middle[100];
    char last[100];
    last[0] = '\0';
    printf("请输入中缀表达式\n ");
    fgets(middle, sizeof(middle), stdin);
    middle[strcspn(middle, "\n")] = '\0'; //移除换行符
    getLast(middle, last);
    printf("后缀表达式是%s\n", last);
    return 0;
}