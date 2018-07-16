#include"utils.h"

void PrintfArray(int *a) {
	for (int i = 0; i < L; i++) {
		printf("%d,", a[i]);
	}
	printf("\n");
}

void main() {
	srand((unsigned)time(NULL));
	int x[L] = { 0 };

	for (int i = 0; i < L; i++) {
		x[i] = rand() % R;
	}
	PrintfArray(x);

	RBTree tree;

	for (int i = 0; i < L; i++) {
		tree.InsertTree(x[i]);
	}
	tree.PrintTree(tree.root);
	
	for (int i = 0; i < R; i++) {
		printf("\n");
		tree.DeletTree(i);
		tree.PrintTree(tree.root);
	}

	system("pause");
}

