//
//  main.c
//  MySort
//
//  Created by LiteShare on 2018/9/7.
//  Copyright © 2018年 Luojuan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

static const int L=100;
static const int R=100000;

int count=0;
int swapcount=0;

void PrintArray(int *num,int length){
    for(int i=0;i<length;i++){
        printf("%d ",num[i]);
    }
    printf("\n");
}

void swap(int *x1,int *x2){
    int temp=*x1;
    *x1=*x2;
    *x2=temp;
    
    swapcount++;
}

void Reverse(int *num,int length){
    for(int i=0;i<length/2;i++){
        swap(num+i, num+length-1-i);
    }
}

void MySort(int *num,int length){
    int re=1;
    while (re) {
        re=0;
        for(int i=0;i<length-1;){
            if (num[i]>num[i+1]) {
                re=1;
                int index=i+2;
                while(num[i]>num[index]&&index<length){
                    index++;
                }
                Reverse(num+i, index-i);
                i=index-1;
            }else{
                ++i;
            }
        }
        count++;
    }
}

int main(int argc, const char * argv[]) {
    
    int x[L]={1,6,5,7,9,8,4,3,2,0};
    
    for(int i=0;i<L;i++){
        x[i]=rand()%R;
    }
    PrintArray(x, L);
    
    MySort(x, L);
    
    PrintArray(x, L);
    
    printf("%d,%d\n",count,swapcount);
    
    return 0;
}
