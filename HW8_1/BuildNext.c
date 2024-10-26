#include<stdio.h>
#define MAX 100

//打印数组的辅助函数
void printList(int *begin, int n){
    for(int i=0; i<n; i++){
        printf("%d ", begin[i]);
    }
    printf("\n");
}

int main(){
    int next[MAX], p[MAX];  //p用于存储元素，next为生成的next表
    int n,i;
    printf("请输入一共多少个元素\n");
    scanf("%d", &n);
    printf("请逐个输入元素\n");
    for(i=0; i<n; i++){
        scanf("%d", &p[i]);
    }

    next[0] = -1;
    int j,temp; //temp表示此处不满足则从p[temp]对齐开始
    for(j=0; j<n-1; j++){
        temp = next[j];
        while(p[j]!=p[temp] && temp!=-1){
            temp = next[temp];
        }
        next[j+1] = temp+1;
    }

    //gpt代码
    for(int j = 1; j < n; j++) {
        int temp = next[j - 1];  // 从前一个next值开始
        // 内层循环，寻找前缀匹配
        while (temp != -1 && p[temp] != p[j - 1]) {
            temp = next[temp];
        }
        // 设定next[j]值
        next[j] = temp + 1;
    }

    printList(p, n);
    printList(next, n);
    return 0;
}