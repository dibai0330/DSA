#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Rectangle{
    int left;   
    int down;
    int width;  //宽
    int length; //长
    int parent; //父结点
    int count;  //权
}Rectangle;

Rectangle shape[10000];

void GetRectangle(){
    //随机生成矩形，长宽均不超过100
    srand(time(NULL));
    for(int i=0; i<10000; i++){
        shape[i].left = rand() %10000;
        shape[i].down = rand() %10000;
        shape[i].length = rand() %100;
        shape[i].width = rand() %100;
        shape[i].parent = i;
        shape[i].count = 1;
    }
}

int Connect(int i, int j){
    //判断第i个和第j个矩形是否相连
    if((shape[i].left + shape[i].width < shape[j].left) ||(shape[j].left + shape[j].width < shape[i].left) ||
        (shape[i].down < shape[j].down - shape[j].length) ||(shape[j].down < shape[i].down - shape[i].length)){
            return 0;
        }
    else    return 1;
}

int GetRoot(int i){
    //找到第i个矩形的根
    if(shape[i].parent != i){
        shape[i].parent = GetRoot(shape[i].parent);
    }
    return shape[i].parent;
}

void Union(int i, int j){
    //合并两棵树
    int root_i = GetRoot(i);
    int root_j = GetRoot(j);
    if(root_i != root_j){
        //把小的一棵树并入大的
        if(shape[i].count > shape[j].count){
            shape[root_j].parent = root_i;
            shape[root_i].count += shape[root_j].count;
        }
        else{
            shape[root_i].parent = root_j;
            shape[root_j].count += shape[root_i].count;
        }
    }
}

int main(){
    GetRectangle();

    int i,j;
    for(i=0; i<10000; i++){
        for(j=0; j<10000; j++){
            if(Connect(i,j))    Union(i,j);
        }
    }

    for(i=0; i<10000; i++){
        //找出所有根
        if(GetRoot(i) == i){
            printf("线网%4d中的导体有：",i);
            for(j=0; j<10000; j++){
                if(GetRoot(j) == i)     printf("%d ",j);
            }
            printf("\n");
        }
    }

    return 0;
}
