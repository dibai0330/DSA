#include<stdio.h>

//5行5列的棋盘
#define ROW 5
#define COL 5
int square[ROW][COL]= {
    {1,1,0,1,1},
    {0,1,0,1,0},
    {1,1,1,1,1},
    {1,0,0,0,1},
    {1,1,1,0,1}
};

int visited[ROW][COL] = {0};    //记录这格是否被访问过
int path[ROW*COL][2];   //记录路径，分别记录x和y坐标
int pathi =0;

void mark(int x, int y){
    //标记为访问过
    visited[x][y] = 1;
}

void remark(int x, int y){
    //标记为未访问
    visited[x][y] = 0;
}

int FindPath(int x, int y){
    mark(x,y);
    //相当于入栈，记录路径
    path[pathi][0] = x;
    path[pathi][1] = y;
    pathi ++;

    if((x==ROW-1) && (y==COL-1))    return 1;

    //移动一格的表示方法
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for(int i=0; i<4; i++){
        int x_pie = x + dx[i];
        int y_pie = y + dy[i];
        if((x_pie>=0) && (x_pie<ROW) && (y_pie>=0) && (y_pie<COL) && //先判断有效再访问数组的元素
            (square[x_pie][y_pie]==1) && (visited[x_pie][y_pie]==0)) {
            if(FindPath(x_pie, y_pie)){
                return 1;
            }
        }
    }
    //如果对这个点找不到路径，标位未访问，并回退路径
    remark(x,y);
    pathi--;
    return 0;
}

int main(){
    if(FindPath(0,0)){
        printf("找得到路径:");
        for(int i=0; i<pathi; i++){
            printf("(%d, %d) ", path[i][0], path[i][1]);
        }
    }
    else    printf("找不到路径\n");
    return 0;
}