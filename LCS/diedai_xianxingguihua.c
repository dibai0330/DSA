#include <stdio.h>
#include<string.h>

int MAX(int a, int b){
    return a>b ? a : b;
}

int main(){
    char strA[100], strB[100];
    printf("请输入字符串A\n");
    scanf("%s", strA);
    printf("请输入字符串B\n");
    scanf("%s", strB);
    
    int lenA=strlen(strA), lenB=strlen(strB);
    int result[lenA +1][lenB +1];   //存储线性规划得到的矩阵
    int i,j;

    //将result的第一行和第一列都初始化为0
    for(i=0; i<lenA+1; i++){
        result[i][0] = 0;
    }
    for(j=1; j<lenB+1; j++){
        result[0][j] = 0;
    }

    for(i=0; i<lenA; i++){
        for(j=0; j<lenB; j++){
            //若这个字符相同，为左上角值+1
            if(strA[i] == strB[j]){
                result[i+1][j+1] = result[i][j]+1;
            }
            //若这个字符不同，为左邻和上邻中较大值
            else{
                result[i+1][j+1] = MAX(result[i][j+1], result[i+1][j]);
            }
        }
    }

    printf("最长子序列长度是 %d\n",result[lenA][lenB]);

    return 0;
}