#include"utils.h"

AVLTree::AVLTree() {
	root = NULL;
}

Node* AVLTree::CreateNode(int num) {
	Node* p = NULL;
	p = (Node*)malloc(sizeof(Node));
	p->key = num;
	p->count = 1;
	p->height = 0;
	p->left = NULL;
	p->right = NULL;

	return p;
}

Node* AVLTree::InsertTree(int num,Node* node) {
	if (node == NULL) {
		node = CreateNode(num);
	}
	else if(num==node->key){
		node->count++;
	}
	else if(num<node->key) {
		node->left=InsertTree(num, node->left);

		if (getHeight(node->left) - getHeight(node->right) == 2) {
			if (num<node->left->key) {
				node = Rotation_Left_Left(node);
			}
			else {
				node = Rotation_Left_Right(node);
			}
		}
	}
	else if(num>node->key) {
		node->right=InsertTree(num, node->right);
		if (getHeight(node->right) - getHeight(node->left) >= 2) {
			if (num > node->right->key) {
				node=Rotation_Right_Right(node);
			}
			else {
				node=Rotation_Right_Left(node);
			}
		}
	}

	node->height = GetMax(getHeight(node->left), getHeight(node->right))+1;
	return node;
}

Node* AVLTree::Rotation_Left_Left(Node* node) {
	Node* p = node->left;
	node->left = p->right;
	p->right = node;

	node->height = GetMax(getHeight(node->left) , getHeight(node->right))+1;
	p->height = GetMax(getHeight(p->left),getHeight(p->right))+1;
	return p;
}

Node* AVLTree::Rotation_Left_Right(Node* node) {
	node->left = Rotation_Right_Right(node->left);
	return Rotation_Left_Left(node);
}

Node* AVLTree::Rotation_Right_Right(Node* node) {
	Node* p = node->right;
	node->right = p->left;
	p->left = node;

	node->height = GetMax(getHeight(node->left) , getHeight(node->right))+1;
	p->height = GetMax(getHeight(p->left) , getHeight(p->right))+1;
	return p;
}

Node* AVLTree::Rotation_Right_Left(Node* node) {
	node->right = Rotation_Left_Left(node->right);
	return Rotation_Right_Right(node);
}

int AVLTree::getHeight(Node* node) {
	if (node == NULL) {
		return 0;
	}
	else {
		return node->height;
	}
}

Node* AVLTree::FindTree(int num){
	Node* p = root;

	while(p != NULL) {
		if (p->key == num) {
			return p;
		}

		if (p->key > num) {
			p = p->left;
		}
		else {
			p = p->right;
		}
	}
	return NULL;
}

Node* AVLTree::FindMax(Node* node) {
	
	if (node == NULL) {
		return NULL;
	}

	if (node->right != NULL) {
		return FindMax(node->right);
	}
	return node;
}

Node* AVLTree::FindMin(Node* node) {

	if (node == NULL) {
		return NULL;
	}

	if (node->left != NULL) {
		return FindMin(node->left);
	}
	return node;
}

void AVLTree::PrintTree(int type) {
	switch (type) {
	case RootFirst:
		PrintTreeRootFirst(root);
		break;
	case RootMid:
		PrintTreeRootMid(root);
		break;
	case RootLast:
		PrintTreeRootLast(root);
		break;
	}
	printf("\n");
}

void AVLTree::PrintTreeRootFirst(Node* node) {
	if (node == NULL) {
		return;
	}

	for (int i = node->count; i > 0; i--) {
		printf("%d ", node->key);
	}
	PrintTreeRootFirst(node->left);
	PrintTreeRootFirst(node->right);
}

void AVLTree::PrintTreeRootMid(Node* node) {
	if (node == NULL) {
		return;
	}
	
	PrintTreeRootMid(node->left);
	for (int i = node->count; i > 0; i--) {
		printf("%d£¬", node->key);
	}

	PrintTreeRootMid(node->right);
}

void AVLTree::PrintTreeRootLast(Node* node) {
	if (node == NULL) {
		return;
	}

	PrintTreeRootLast(node->left);
	PrintTreeRootLast(node->right);
	for (int i = node->count; i > 0; i--) {
		printf("%d ", node->key);
	}
}

Node* AVLTree::DestroyTree(Node* node) {
	if (node != NULL) {
		node->right=DestroyTree(node->right);
		node->left=DestroyTree(node->left);
		free(node);
	}
	return NULL;
}

Node* AVLTree::DeletTree(int num,Node* node) {
	if (node == NULL) {
		return NULL;
	}
	else if (num == node->key) {
		if (node->left != NULL&&node->right != NULL) {
			
			Node* p;
			if (getHeight(node->left) > getHeight(node->right)) {
				p = FindMax(node->left);
				node->key = p->key;
				node->count = p->count;
				node->left = DeletTree(p->key, node->left);
			}
			else {
				p = FindMin(node->right);
				node->key = p->key;
				node->count = p->count;
				node->right = DeletTree(p->key, node->right);
			}
		}
		else {
			if (node->left == NULL&&node->right == NULL) {
				free(node);
				return NULL;
			}
			else {
				Node* p = node;
				node = node->left != NULL ? node->left : node->right;
				free(p);
			}
		}
	}
	else if (num < node->key) {
		node->left = DeletTree(num, node->left);

		if ((getHeight(node->right) - getHeight(node->left))==2) {
			if (getHeight(node->right->right) < getHeight(node->right->left)) {
				node = Rotation_Right_Left(node);
			}
			else {
				node = Rotation_Right_Right(node);
			}
		}
	}
	else if (num > node->key) {
		node->right = DeletTree(num,node->right);

		if ((getHeight(node->left) - getHeight(node->right)) == 2) {
			if (getHeight(node->left->left) < getHeight(node->left->right)) {
				node = Rotation_Left_Right(node);
			}
			else {
				node = Rotation_Left_Left(node);
			}
		}
	}

	node->height = GetMax(getHeight(node->left), getHeight(node->right))+1;
	return node;
}