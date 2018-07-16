#include<iostream>
#include<time.h>

using namespace std;

static const int L = 200;
static const int R = 100;

enum Color
{
	BLACK = 0,
	RED = 1
};

struct Node {
	int key;
	int count;
	int color;
	Node* parent;
	Node* left;
	Node* right;
};

class RBTree {
public:
	Node* root;
	RBTree();
	~RBTree();
	void InsertTree(int key);
	void DeletTree(int key);
	Node* FindTree(int key);
	void PrintTree(Node* node);

private:
	void DestroyTree(Node *node);
	void Insert_Fixup(Node* node);
	void Delet_Fixup(Node* parent, Node* node);
	void Rotation_Right(Node* node);
	void Rotation_Left(Node* node);
};