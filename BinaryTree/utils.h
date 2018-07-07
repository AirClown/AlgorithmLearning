#include<stdio.h>
#include<time.h>
#include<stdlib.h>

enum MyEnum
{
	MinToMax = 1,
	MaxToMin = 2
};

struct Leaf {
	int num;
    int count;
	Leaf *left;
	Leaf *right;
	Leaf *parent;
};

class Tree {
public:
	Tree();
	void InsertTree(int num);
	void PrintTree(int sign);
	void DeletTree(int num);
	Leaf* FindMax();
	Leaf* FindMin();
	Leaf* Find(int num);

private:
	Leaf *root;
	void PrintFromMin(Leaf *l);
	void PrintFromMax(Leaf *l);
};
