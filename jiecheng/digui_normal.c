#include <stdio.h>

double digui(int n){
    return( (n<=1) ? 1: n*digui(n-1));
}

int main(){
    int n;
    double result;
    printf("请输入需要计算多少的阶乘");
    scanf("%d",&n);
    result = digui(n);
    printf("%d的阶乘结果是%.0f",n,result);
    return 0;
}