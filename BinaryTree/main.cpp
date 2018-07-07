#include <iostream>
#include "utils.h"

static const int L=20;
static const int R=20;

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));
    
    int a[L]={0};
    
    for(int i=0;i<L;i++){
        a[i]=rand()%R;
    }
    
    for(int i=0;i<L;i++){
        printf("%d ",a[i]);
    }
    printf("\n\n");
    
    Tree tree;
    //插入数据
    for(int i=0;i<L;i++){
        tree.InsertTree(a[i]);
    }
    tree.PrintTree(MinToMax);
    
    //反转二叉树
    tree.ReverseTree();
    tree.PrintTree(MinToMax);
    tree.ReverseTree();
    
    //删除数据
    for(int i=0;i<R;i++){
        tree.DeletTree(i);
        tree.PrintTree(MinToMax);
    }
    
    //销毁树
    tree.DestroyTree();
    return 0;
}
