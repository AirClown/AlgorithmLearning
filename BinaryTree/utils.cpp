#include"utils.h"

Tree::Tree() {
    size=0;
	root = (Leaf *)malloc(sizeof(Leaf));
	root->num = -1;
    root->count=0;
	root->left = NULL;
	root->right = NULL;
	root->parent = NULL;
}

void Tree::InsertTree(int num) {
    Leaf *l=Find(num);
    
    if(l==NULL){
        if (root->num < 0) {
            root->num = num;
            root->count++;
        }
        else {
            l= (Leaf *)malloc(sizeof(Leaf));
            l->num = num;
            l->count=1;
            l->left = NULL;
            l->right = NULL;
            
            Leaf *p = root;
            Leaf *parent = root;
            while (p!=NULL) {
                parent = p;
                
                if (num < p->num) {
                    p = p->left;
                }
                else {
                    p = p->right;
                }
            }
            
            l->parent = parent;
            
            if (num < parent->num) {
                parent->left = l;
            }
            else {
                parent->right = l;
            }
        }
    }else{
        l->count++;
    }
    
    size++;
}

void Tree::PrintTree(int sign) {
	switch (sign)
	{
	case MinToMax:
		PrintFromMin(root);
		break;
	case MaxToMin:
		PrintFromMax(root);
		break;
	default:
		break;
	}

	printf("\n");
}

void Tree::PrintFromMin(Leaf *l) {
	if (l == NULL) {
		return;
	}

	PrintFromMin(l->left);
    for(int i=l->count;i>0;i--){
        printf("%d ",l->num);
    }
	PrintFromMin(l->right);
}

void Tree::PrintFromMax(Leaf *l) {
	if (l == NULL) {
		return;
	}

	PrintFromMax(l->right);
    for(int i=l->count;i>0;i--){
        printf("%d ", l->num);
    }
	PrintFromMax(l->left);
}

Leaf* Tree::FindMin() {
	Leaf *l = root;

	while (l->left != NULL) {
		l = l->left;
	}

	return l;
}

Leaf* Tree::FindMax(){
	Leaf *l = root;

	while (l->right != NULL) {
		l = l->right;
	}

	return l;
}

Leaf *Tree::Find(int num) {
	Leaf *l = root;

	while (l!=NULL) {
		if (num == l->num) {
			return l;
		}
        else if(num<l->num){
			l = l->left;
		}
		else {
			l = l->right;
		}
	}

	return NULL;
}

void Tree::DeletTree(int num) {
	Leaf *l=Find(num);
    
    if(l==NULL){
        return;
    }
    
    if(l->left==NULL&&l->right==NULL){
        Leaf *parent=l->parent;
        
        if(parent==NULL){
            l->count=0;
            l->num=-1;
            return;
        }
        
        if(l==parent->left){
            parent->left=NULL;
        }else{
            parent->right=NULL;
        }
        
        free(l);
    }else if(l->left==NULL){
        Leaf *parent=l->parent;
        if(parent==NULL){
            l->count=0;
            l->num=-1;
            return;
        }
        
        if(l==parent->left){
            parent->left=l->right;
            l->right->parent=parent;
        }else{
            parent->right=l->right;
            l->right->parent=parent;
        }
        
        free(l);
    }else if(l->right==NULL){
        Leaf *parent=l->parent;
        if(parent==NULL){
            l->count=0;
            l->num=-1;
            return;
        }
        
        if(l==parent->left){
            parent->left=l->left;
            l->right->parent=parent;
        }else{
            parent->right=l->left;
            l->right->parent=parent;
        }
        
        free(l);
    }else{
        Leaf *p=l->right;
        
        while(p->left!=NULL){
            p=p->left;
        }
        
        l->count=p->count;
        int n=p->num;
        DeletTree(p->num);
        l->num=n;
    }
}

int Tree::Size(){
    return size;
}

void Tree::DestroyTree(){
    Destroy(root);
}

void Tree::Destroy(Leaf *l){
    if(l==NULL){
        return;
    }
    
    Destroy(l->left);
    Destroy(l->right);
    free(l);
}
