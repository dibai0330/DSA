#include<stdio.h>

int f(int m,int n){
    //思路：转换为n和n-1相关的项
    if(m==1 || m==0 || n==1){
        return 1;
    }   
    else if(m<0 || n<0){
        return 0;
    }
    else return f(m-n,n)+f(m,n-1);
}

int main(){
    int m,n;
    printf("请输入m n，以空格隔开\n");
    scanf("%d %d",&m,&n);
    printf("f(m,n)=%d\n",f(m,n));
    return 0;
}