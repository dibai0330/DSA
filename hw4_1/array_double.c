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
    scanf("%d", &i);
    int size = n + (i/n + 1)*n;
    int* array2 = (int*)malloc(size * sizeof(int));
    //不妨将array2中的数据初始化为0
    for(i=0; i<size; i++){
        array2[i] = 0;
    }

    //将指向array1的指针重新指向array2
    int* tmp;
    tmp = array1;
    array1 = array2;
    //将tmp（原array1）中的数据复制到现array1中
    for(i=0; i<n; i++){
        array1[i] = tmp[i];
    }
    
    //打印更新后array1中的数据
    for(i=0; i<size; i++){
        printf("%-3d ", array2[i]);
    }

    //最后释放空间
    free(tmp);
    free(array2);
    return 0;
}