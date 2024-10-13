#include<stdio.h>
//假设数组大小不大于10

void print(int* list, int size){
    //辅助函数，逐个打印数组中的元素
    int i;
    for(i=0; i<size; i++){
        printf("%d ",list[i]);
    }
    printf("\n");
}

void result(int *in, int in_size, int *stack, int stack_size, int *out, int out_size){
    //各个size均表示数组中实际有的元素的个数
    if(in_size == 0){
        if(stack_size == 0){
            //若输入和stack均为空，打印output中的元素
            print(out, out_size);
        }
        else{
            //若输入为空，stack非空，将stack中栈顶的元素弹出到output中，然后递归
            out[out_size] = stack[stack_size -1];
            stack_size--;
            out_size++;
            result(in, in_size, stack, stack_size, out, out_size);
        }
    }
    else{
        //input不为空
        if(stack_size >0){
            //stack也不为空时，可以选择让stack栈顶出栈，也可以让input的第一个进入stack(同stack为空的时候)
            //需要保留原本的input stack和output，所以复制一份
            int tmp_input[10],tmp_stack[10],tmp_output[10];
            int tmp_in_size=in_size, tmp_stack_size=stack_size, tmp_out_size=out_size;
            int i;
            for(i=0; i<in_size; i++){
                tmp_input[i] = in[i];
            }
            for(i=0; i<stack_size; i++){
                tmp_stack[i] = stack[i];
            }
            for(i=0; i<out_size; i++){
                tmp_output[i] = out[i];
            }
            //stack栈顶出栈，进入output
            tmp_output[tmp_out_size] = stack[tmp_stack_size -1];
            tmp_out_size++;
            tmp_stack_size--;
            result(tmp_input, tmp_in_size, tmp_stack, tmp_stack_size, tmp_output, tmp_out_size);
        }

        //若input不为空，因为input[0]直接加入output中等同于加入stack，然后stack栈顶出栈，所以不论stack是否为空，将input[0]加入stack中
        stack[stack_size] = in[0];
        for(int i=0; i<in_size-1; i++){
            in[i] = in[i+1];
        }
        in_size--;
        stack_size++;
        result(in, in_size, stack, stack_size, out, out_size);
        }
    }


int main(){
    int n,i;  
    int input[10], output[10], stack[10];
    printf("请输入一共多少个数\n");
    scanf("%d",&n);      //n为数据总个数    
    //初始化输入序列
    for(i=0; i<n; i++){
        input[i] = i+1;
    }

    result(input, n, stack, 0, output, 0);
    return 0;
}