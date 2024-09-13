#include <stdio.h>

int main(){
    int a[20] = {0}, sum[20] ={0};   //数组中最多50个数
    int len = 0, tmp;      //len为数组中元素的实际个数
    printf("请输入数组中的元素，以空格隔开，以回车结束\n");
    do {  
        scanf("%d", &tmp);
        a[len] = tmp;
        len++;
    } while(getchar() != '\n');

    for(tmp = 0;tmp < len; tmp ++){
        if(tmp ==0){
            sum[tmp] = a[tmp];
        }
        else{
            sum[tmp] = sum[tmp -1] + a[tmp];
        }
        printf("%d\t",sum[tmp]);
    }
    
    return 0;
}