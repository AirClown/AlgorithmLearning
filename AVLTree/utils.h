#include<time.h>
#include<Windows.h>
#include<iostream>

#define GetMax(a,b) (a>b?a:b)
#define GetMin(a,b) (a>b?b:a)

static const int L = 100;
static const int R = 100;

enum PrintType
{
	RootFirst = 0,
	RootMid = 1,
	RootLast = 2
};

struct Node {
	int key;
	int count;
	int height;
	Node* right;
	Node* left;
};

class AVLTree {
public:
	Node* root;
	AVLTree();
	Node* InsertTree(int num,Node* node);
	Node* DeletTree(int num, Node* node);
	void PrintTree(int type);
	Node* FindTree(int num);
	Node* FindMax(Node* node);
	Node* FindMin(Node* node);
	Node* DestroyTree(Node* node);

private:
	Node* CreateNode(int num);
	int getHeight(Node* node);
	Node* Rotation_Left_Left(Node* node);
	Node* Rotation_Left_Right(Node* node);
	Node* Rotation_Right_Right(Node* node);
	Node* Rotation_Right_Left(Node* node);
	void PrintTreeRootFirst(Node* node);
	void PrintTreeRootMid(Node* node);
	void PrintTreeRootLast(Node* node);
};