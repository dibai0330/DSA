#include <stdio.h>
int gcd(int a, int b){
    int tmp;
    if(a<b){
        return gcd(b,a);
    }
    else if(a>b){
        tmp = b;
        b = a-b;
        a = tmp;
        return gcd(a,b);
    }
    else{
        return a;
    }
}

int main(){
    int m,n;
    printf("请输入要求的两个数，以空格隔开\n");
    scanf("%d %d",&m,&n);
    printf("%d和%d的最大公约数是%d",m,n,gcd(m,n));
    return 0;
}