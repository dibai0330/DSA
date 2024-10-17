#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ctype库可以用于进行字符类型的分类处理
#include <ctype.h>

#define MAX_SIZE 100

// 定义栈结构
typedef struct {
    int top;
    int items[MAX_SIZE];
} Stack;

// 初始化栈
void initStack(Stack* s) {
    s->top = -1;
}

// 检查栈是否为空
int isEmpty(Stack* s) {
    return s->top == -1;
}

// 入栈操作
void push(Stack* s, double value) {
    if (s->top < MAX_SIZE - 1) {
        s->items[++(s->top)] = value;
    } else {
        printf("栈溢出\n");
        exit(EXIT_FAILURE);
    }
}

// 出栈操作
double pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    } else {
        printf("栈为空\n");
        exit(EXIT_FAILURE);
    }
}

// 计算后缀表达式
double evaluatePostfix(const char* expression) {
    Stack s;
    initStack(&s);
    char* token;
    //创建表达式的副本以便分割，strup用于复制一个字符串并且返回指向该字符串的指针
    char* exprCopy = strdup(expression); 

    // 分割字符串并处理每个token
    //strtok用于分隔字符串为token，会将分隔符 变成\0,返回指向下一个分隔符的指针
    token = strtok(exprCopy, " ");
    while (token != NULL) {
        // 如果token是数字，入栈
        //正数或负数
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&s, atof(token));  //atof将字符串转为double
        } else {
            // token是运算符，出栈两个数并计算
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            switch (token[0]) {
                case '+':
                    push(&s, operand1 + operand2);
                    break;
                case '-':
                    push(&s, operand1 - operand2);
                    break;
                case '*':
                    push(&s, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) {
                        push(&s, operand1 / operand2);
                    } else {
                        printf("除数不能为零\n");
                        exit(EXIT_FAILURE);
                    }
                    break;
                default:
                    printf("未知运算符: %s\n", token);
                    exit(EXIT_FAILURE);
            }
        }
        //后续调用时传入NULL,表示继续从上一次停止的地方查找下一个token,strtok会自动维护一个内部指针
        token = strtok(NULL, " ");
    }

    free(exprCopy); // 释放内存
    return pop(&s); // 返回结果
}

int main() {
    char expression[MAX_SIZE];
    
    printf("请输入后缀表达式: ");
    fgets(expression, sizeof(expression), stdin);
    
    // 去掉换行符
    expression[strcspn(expression, "\n")] = '\0';
    
    int result = evaluatePostfix(expression);
    printf("后缀表达式的结果是: %d\n", result);
    
    return 0;
}

