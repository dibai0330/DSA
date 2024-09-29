#include<stdio.h>
#include<stdlib.h>

int main(){
    //初始化一个大小为n的数组
    int n;
    printf("请输入初始数组的大小\n");
    scanf("%d", &n);
    int* array1 = (int*)malloc(n * sizeof(int));
    //不妨将array1中的数据初始化为0 ~ n-1
    int i;
    for(i=0; i<n; i++){
        array1[i] = i;
    }

    //更改数组的大小，假设每次增加的大小 deta_n = 20
    printf("请输入需要增加的数组的大小\n");
    int deta;
    scanf("%d", &deta);
    int now_use = n;
    int new_size = n;
    int count = 0;  //计数器
    for(int j=0; j<=deta; j++){ 
        now_use = n+j;
        if(now_use >= new_size){
            new_size *= 2;
            int* array2 = (int*)malloc(new_size * sizeof(int));
            //不妨将array2中的数据初始化为0
            for(i=0; i<new_size; i++){
             array2[i] = 0;
            }

            //将array1数据复制到array2中
            for(i=0; i<new_size/2; i++){
               array2[i] = array1[i];
               count ++;
            }
            
            //最后释放array1,将array1指向array2
            free(array1);
            array1 = array2;
        }
    }
    
    //打印更新后array1中的数据
    //for(i=0; i<new_size; i++){
    //printf("%-3d ", array1[i]);
    //}
    printf("\n%d",count);
    return 0;
}