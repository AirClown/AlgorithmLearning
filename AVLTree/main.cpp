#include"utils.h"

void main() {
	srand((unsigned)time(NULL));

	AVLTree tree;
	for (int i = 0; i < L; i++) {
		int x = rand() % R;
		tree.root = tree.InsertTree(x, tree.root);
		printf("%d,", x);
	}
	printf("\n");

	tree.PrintTree(RootMid);

	for (int i = 0; i < R; i++) {
		tree.root=tree.DeletTree(i, tree.root);
		tree.PrintTree(RootMid);
		printf("\n");
	}
	
	tree.root = tree.DestroyTree(tree.root);
	system("pause");
}
