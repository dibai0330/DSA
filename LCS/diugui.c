#include <stdio.h>
#include<string.h>

int MAX(int a, int b){
    return a>b ? a : b;
}

int LCS(char* str1, char* str2){
    int len1 = strlen(str1), len2 = strlen(str2); 

    //若已经没有字符，返回0；
    if(len1==0 || len2==0)  return 0;

    char str1_next[len1], str2_next[len2];
    //strncpy(B, A, n); B[n]='\0';  实现复制字符串A的前n个到字符串B中，记得添加字符串结束符
    strncpy(str1_next, str1, len1-1);
    strncpy(str2_next, str2, len2-1);
    str1_next[len1 -1] = '\0';
    str2_next[len2 -1] = '\0';

    //若最后一个字符相同，则返回“字符串-末尾字符”+1
    if(str1[len1-1] == str2[len2-1]){
        return LCS(str1_next, str2_next) +1;
    }
    
    //若不相同，返回 “A-1”与“B" 和 “B-1”与“A" 中较大值
    else{
        return MAX(LCS(str1_next, str2), LCS(str2_next,str1));
    }

}

int main(){
    char strA[100], strB[100];
    printf("请输入字符串A\n");
    scanf("%s", strA);
    printf("请输入字符串B\n");
    scanf("%s", strB);
    
    printf("最长子序列长度是 %d\n",LCS(strA, strB));
    return 0;
}