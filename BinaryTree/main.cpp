#include <iostream>
#include "utils.h"

static const int L=60;
static const int R=30;

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
    
    for(int i=0;i<L;i++){
        tree.InsertTree(a[i]);
    }
    
    tree.PrintTree(MinToMax);
    for(int i=0;i<R;i++){
        tree.DeletTree(i);
        tree.PrintTree(MinToMax);
    }
    
    tree.DestroyTree();
    return 0;
}
