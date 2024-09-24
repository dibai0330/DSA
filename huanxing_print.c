#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void PrintTable(int** table,int x, int deta_x, int y,int deta_y){
    if(deta_x>0 && deta_y>0){
        int i;
        //第一行
        for(i=0;i<deta_x;i++){
            printf("%-3d", table[y][x+i]);
        }
        //最后一列
        for(i=1;i<deta_y;i++){
            printf("%-3d",table[y+i][x+deta_x-1]);
        }  
        //最后一行 
        for(i=deta_x-1;i>0;i--){
            printf("%-3d",table[y+deta_y-1][x+i-1]);
        }
        //第一列
        for(i=deta_y-1;i>1;i--){
           printf("%-3d",table[y+i-1][x]);
        }
        PrintTable(table, x+1, deta_x-2,  y+1, deta_y-2);
    }
}

int main(){
    //生成一个n*m的矩阵，每个值均为两位整数
    srand(time(NULL));  // 初始化随机数种子
    printf("请输入矩阵的大小m*n，m和n之间用空格隔开 \n");
    int m,n,i,j;
    scanf("%d %d",&m,&n);

    //动态分配内存
    int **table = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        table[i] = (int *)malloc(n * sizeof(int));
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            table[i][j] = rand() % 100;
        }
    }
    //按顺序输出这个矩阵
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%3d",table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    PrintTable(table, 0,n,0,m);

    //释放动态分配的内存
    for (i = 0; i < m; i++) {
        free(table[i]);
    }
    free(table);
    return 0;
}