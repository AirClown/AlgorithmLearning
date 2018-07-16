#include"utils.h"

RBTree::RBTree() {
	root = (Node*)malloc(sizeof(Node));
	root->key = 0;
	root->count = 0;
	root->color = BLACK;
	root->parent = NULL;
	root->left = NULL;
	root->right = NULL;
}

RBTree::~RBTree() {
	DestroyTree(root);
}

void RBTree::InsertTree(int key) {
	if (root->count == 0) {
		root->key = key;
		root->count++;
	}
	else {
		Node* node=root;
		Node* parent=root->parent;

		while (node != NULL) {
			parent = node;

			if (key == node->key) {
				node->count++;
				return;
			}
			else if (key < node->key) {
				node = node->left;
			}
			else {
				node = node->right;
			}
		}

		node = (Node*)malloc(sizeof(Node));
		node->key = key;
		node->count = 1;
		node->color = RED;
		node->parent = parent;
		node->left = NULL;
		node->right = NULL;

		if (key < parent->key) {
			parent->left = node;
		}
		else {
			parent->right = node;
		}

		Insert_Fixup(node);
	}
}

void RBTree::Insert_Fixup(Node* node) {
	while (node->parent != NULL&&node->parent->color == RED) {
		Node* parent = node->parent;
		Node* gparent = parent->parent;
		Node* uncle;

		if (parent == gparent->left) {
			uncle = gparent->right;

			if (uncle != NULL&&uncle->color==RED) {
				uncle->color = BLACK;
				parent->color = BLACK;
				gparent->color = RED;
				node = gparent;
			}
			else {
				if (node == parent->right) {
					node = parent;
					Rotation_Left(node);
					parent = node->parent;
				}
				parent->color = BLACK;
				gparent->color = RED;
				Rotation_Right(gparent);
			}
		}
		else {
			uncle = gparent->left;

			if (uncle != NULL&&uncle->color == RED) {
				uncle->color = BLACK;
				parent->color = BLACK;
				gparent->color = RED;
				node = gparent;
			}
			else {
				if (node == parent->left) {
					node = parent;
					Rotation_Right(node);
					parent = node->parent;
				}
				parent->color = BLACK;
				gparent->color = RED;
				Rotation_Left(gparent);
			}
		}
	}

	root->color = BLACK;
}

void RBTree::DeletTree(int key) {
	root;
	Node* node = FindTree(key);

	if (node != NULL) {
		Node* parent = node->parent;

		if (node->left != NULL&&node->right != NULL) {
			Node *p = node->right;

			while (p->left != NULL) {
				p = p->left;
			}

			int key = p->key;
			node->count = p->count;
			DeletTree(p->key);
			node->key = key;
		}
		else {
			Node* child = node->left == NULL ? node->right : node->left;

			if (child != NULL) {
				child->parent = parent;
			}

			if (parent != NULL) {
				if (node == parent->left) {
					parent->left = child;
				}
				else {
					parent->right = child;
				}
			}
			else {
				if (child != NULL) {
					root = child;
				}
				else {
					root->count = 0;
				}
			}

			if (node->color == BLACK) {
				Delet_Fixup(parent, child);
			}
		}
	}
}

void RBTree::Delet_Fixup(Node* parent,Node* node) {
	parent;
	while (parent!=NULL && (node == NULL || node->color == BLACK)) {
		if (node == parent->left) {
			Node* uncle = parent->right;
			if (uncle->color == RED) {
				uncle->color = BLACK;
				parent->color = RED;
				Rotation_Left(parent);

				uncle = parent->right;
			}

			if ((uncle->left == NULL||uncle->left->color==BLACK)&&
				(uncle->right == NULL|| uncle->right->color == BLACK)) {
				uncle->color = RED;
				node = parent;
				parent = node->parent;
			}
			else {
				if (uncle->right == NULL || uncle->right->color == BLACK) {
					uncle->color = RED;
					uncle->left->color = BLACK;
					Rotation_Right(uncle);
					uncle = parent->right;
				}

				uncle->color = parent->color;
				parent->color = BLACK;
				uncle->right->color = BLACK;
				Rotation_Left(parent);
				break;
			}
		}
		else {
			Node* uncle = parent->left;

			if (uncle->color == RED) {
				uncle->color = BLACK;
				parent->color = RED;

				Rotation_Left(parent);

				uncle = parent->left;
			}

			if ((uncle->left == NULL || uncle->left->color == BLACK) &&
				(uncle->right == NULL || uncle->right->color == BLACK)) {
				uncle->color = RED;
				node = parent;
				parent = node->parent;
			}
			else {
				if (uncle->left == NULL || uncle->left->color == BLACK) {
					uncle->color = RED;
					uncle->right->color = BLACK;
					Rotation_Left(uncle);
					uncle = parent->right;
				}
				uncle->color = parent->color;
				parent->color = BLACK;
				uncle->left->color = BLACK;
				Rotation_Right(parent);
				break;
			}
		}
	}
	if (node != NULL) {
		node->color = BLACK;
	}

	root->color = BLACK;
}

void RBTree::Rotation_Right(Node* node) {
	Node* p = node->left;

	if (p->right != NULL) {
		p->right->parent = node;
	}
	node->left = p->right;

	p->right = node;
	p->parent = node->parent;
	node->parent = p;
	
	if (p->parent==NULL) {
		root = p;
	}
	else {
		if (node == p->parent->left) {
			p->parent->left = p;
		}
		else {
			p->parent->right = p;
		}
	}
}

void RBTree::Rotation_Left(Node* node) {
	Node* p = node->right;

	if (p->left != NULL) {
		p->left->parent = node;
	}
	node->right = p->left;

	p->left = node;
	p->parent = node->parent;
	node->parent = p;

	if (p->parent == NULL) {
		root = p;
	}
	else {
		if (node == p->parent->left) {
			p->parent->left = p;
		}
		else {
			p->parent->right = p;
		}
	}
}

void RBTree::PrintTree(Node* node) {
	if (node != NULL) {
		PrintTree(node->left);

		for (int i = node->count; i > 0; i--) {
			printf("%d,", node->key);
		}

		PrintTree(node->right);
	}
}

Node* RBTree::FindTree(int key) {
	Node* node = root;

	while (node != NULL) {
		if (key == node->key) {
			return node;
		}
		else if (key < node->key) {
			node = node->left;
		}
		else {
			node = node->right;
		}
	}

	return node;
}

void RBTree::DestroyTree(Node* node) {
	if (node != NULL) {
		DestroyTree(node->left);
		DestroyTree(node->right);
		free(node);
	}
}