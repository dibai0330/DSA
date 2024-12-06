#include<stdio.h>
#define MAX 100

int main(){
    //初始化数组
    int a[MAX]={0};
    int n, i,j;
    printf("数组中一共有多少个元素？\n");
    scanf("%d", &n);
    printf("请依次输入数组中的元素");
    for(i=0; i<n; i++)  scanf("%d", &a[i]);

    //i指针从前往后扫描,j从后往前扫描，i遇到正数停下，j遇到负数停下，二者交换，直到相遇
    i=0;    
    j=n-1;
    while(i<j){
        if(a[i] <= 0)   i++;
        if(a[j] >= 0)   j--;
        else if(a[i]>0 && a[j]<0){//swap(a[i], a[j])
            int tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
        }
    }

    //打印排序后的数组
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}