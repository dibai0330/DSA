#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int m,n;

void PrintTable(int **table, int x,int y,int deta_x, int deta_y){
    //参数为  表格，其实的横纵坐标，x变化量，y变化量
    //矩阵 table[y坐标][x坐标]
    if(y>=0 && x>=0){
        int i;
        //上边，含一个转折点
        for(i=x; i<=x+deta_x; i++){
            if(i>=0 && i<n && deta_x>0 && y>=0) printf("%d ", table[y][i]);
        }
        //右边，含一个转折点
         for(i=y+1; i<=y+deta_y;i++){
           if(i>=0 && i<m && x+deta_x<n)  printf("%d ",table[i][x + deta_x]);
        }
        //下边，含一个转折点
        for(i=x+deta_x-1; i>=x-1; i--){
            if(i>=0 && i<n && deta_x>0 && y+deta_y<m) printf("%d ", table[y+deta_y][i]);
        }
        //左边，含一个转折点
        for(i = y+deta_y-1; i>y-1;i--){
            if(i>=0 && i<m && deta_y>0 && x>0) printf("%d ",table[i][x-1]);
        } 
        PrintTable(table, x-1,y-1,deta_x+2, deta_y+2) ;
    }      
}


int main(){
    //生成一个n*m的矩阵，每个值均为两位整数
    srand(time(NULL));  // 初始化随机数种子
    int i,j;
    printf("请输入矩阵的大小m*n，m和n之间用空格隔开 \n");
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

    //先处理n=1或m=1的特殊情况
    if(m==1){
        for(int i=0;i<n;i++){
            printf("%d ",table[0][i]);
        }
    }

    else if(n==1){
        for(int i=0;i<m;i++){
            printf("%d ",table[i][0]);
        }
    }

    else if(n >= m){
        //矩阵x边长大于或等于y边时
        int begin_x = (m-1)/2;  //起始点的x坐标
        int begin_y = begin_x;
        int deta_x = (n- 2*begin_x)-1;    //边长包含的实际的x个数
        int deta_y = (m- 2*begin_y)-1;
        //deta_x和deta_y至少是1
        deta_x = (deta_x==0) ? 1:deta_x;
        deta_y = (deta_y==0) ? 1:deta_y;
        PrintTable(table,begin_x,begin_y,deta_x,deta_y);
    }
    else{
        //矩阵x边长小于y边时
        int begin_x = n- (n+1)/2 ;
        int begin_y = (n+1)/2 -1;
        int deta_x = (n-1)%2;
        int deta_y = m-2*begin_y-1;

        //printf("%d %d %d\n",table[begin_y][begin_x],begin_x,begin_y);
        //printf("%d %d %d",table[begin_y+deta_y][begin_x-deta_x],deta_x,deta_y);
        //先打印中心两行
        for(int i=begin_y;i<=begin_y+deta_y;i++){
            printf("%d ",table[i][begin_x]);
        }
        for(i=begin_y+deta_y;i>=begin_y;i--){
            printf("%d ",table[i][begin_x-1]);
        }
    //注意n为奇数和偶数时，下一次的deta_x不同
    if(n%2==0)  PrintTable(table,begin_x-1,begin_y-1,deta_x+1,deta_y+2);
    else    PrintTable(table,begin_x-1,begin_y-1,deta_x+2,deta_y+2);
    }

    
    //printf("%d",table[begin][begin]);

    //释放动态分配的内存
    for (i = 0; i < m; i++) {
        free(table[i]);
    }
    free(table);
    return 0;
}