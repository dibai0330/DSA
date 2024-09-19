#include <stdio.h>

double digui(int n,double result){
    if(n==1)    return result;
    return digui(n-1, n*result);
}

//double tmp(int n){
//    return digui(n,1);
//}

int main(){
    int n;
    double result_final;
    printf("请输入需要计算多少的阶乘");
    scanf("%d",&n);
    result_final = digui(n,1);
    printf("%d的阶乘结果是%.0f",n,result_final);
    return 0;
}