#include <stdio.h>

int main(){
    int n,i;
    double result=1;
    printf("请输入需要计算多少的阶乘");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        result *= i;
    }
    printf("%d的阶乘结果是%.0f",n,result);
    return 0;
}