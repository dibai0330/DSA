#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//5行5列的棋盘
#define ROW 5
#define COL 5
int square[ROW][COL];
int visited[ROW][COL] = {0};    //记录这格是否被访问过
int path[ROW*COL][2];   //记录路径，分别记录x和y坐标
int pathi =0;

void mark(int x, int y){
    visited[x][y] = 1;
}

void remark(int x, int y){
    visited[x][y] = 0;
}

int FindPath(int x, int y){
    mark(x,y);
    path[pathi][0] = x;
    path[pathi][1] = y;
    pathi ++;

    if((x==ROW-1) && (y==COL-1))    return 1;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for(int i=0; i<4; i++){
        int x_pie = x + dx[i];
        int y_pie = y + dy[i];
        if((x_pie>=0) && (x_pie<ROW) && (y_pie>=0) && (y_pie<COL) && (square[x_pie][y_pie]==1) && (visited[x_pie][y_pie]==0)) {
            if(FindPath(x_pie, y_pie)){
                return 1;
            }
        }
    }
    remark(x,y);
    pathi--;
    return 0;
}

int main(){
    srand(time(NULL));
    //随机初始化棋盘，0表示这格不通，1表示可以通行
    int i,j;
    for(i=0; i<ROW; i++){
        for(j=0; j<COL; j++){
            square[i][j] = rand() % 2;
        }
    }
    square[0][0] = 1;
    square[ROW-1][COL-1] = 1;
    for(i=0; i<ROW; i++){
        for(j=0; j<COL; j++){
            printf("%d  ", square[i][j]);
        }
        printf("\n");
    }

    if(FindPath(0,0)){
        printf("路径如下\n");
        for(i=0; i<pathi; i++){
            printf("(%d, %d) ", path[i][0], path[i][1]);
        }
    }
    else    printf("找不到路径\n");
    return 0;
}