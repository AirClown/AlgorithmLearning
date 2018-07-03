#include"utils.hpp"

List::List() {
	head = (Position *)malloc(sizeof(Position));
	head->next = NULL;
}

void List::Add(int x, int y, Position *parent) {
	Position *p = head;
	while (p->next != NULL) {

		if (p->x == x&&p->y == y) {
			return;
		}

		p = p->next;
	}

	Position *node = (Position *)malloc(sizeof(Position));
	node->x = x;
	node->y = y;
	node->parent = parent;
	node->next = NULL;

	p->next = node;
}

void List::AddOne(Position *point) {
	Position *p = head;
	while (p->next != NULL) {
		if (p->x == point->x&&p->y == point->y) {
			return;
		}

		p = p->next;
	}

	p->next = point;
	point->next = NULL;
}

void List::Delet(int x, int y) {
	Position *p = head->next;
	Position *p2 = head;
	while(p!= NULL) {
		if (p->x == x&&p->y == y) {
			p2->next = p->next;
			return;
		}

		p2 = p;
		p = p->next;
	}
}

Position *List::Find(int x, int y) {
	Position *p = head->next;
	while(p!= NULL) {
		if (p->x == x&&p->y == y) {
			return p;
		}

		p = p->next;
	}

	return NULL;
}

Position* List::FindMin() {
	int min = 100000;
	Position *M = NULL;
	Position *p = head->next;
	while (p != NULL) {
		int f = p->H + p->G;

		if (min > f) {
			min = f;
			M = p;
		}

		p = p->next;
	}

	return M;
}

void List::Change(int x, int y, Position *parent) {
	Position *p = head->next;
	while (p != NULL) {
		if (p->x == x&&p->y == y) {
			p->parent = parent;
			return ;
		}

		p = p->next;
	}
}

Position *List::LastOne() {
	Position *p = head;
	while (p->next!= NULL) {

		p = p->next;
	}
	return p;
}

void List::printList() {
	Position *p = head->next;

	if (p != NULL) {
		while (p != NULL) {
			printf("%d,%d\n", p->x, p->y);
		}
	}
	else {
		printf("NULL\n");
	}
}

void List::DestroyList() {
	Position *p = head;

	while (p == NULL) {
		Position *node = p;
		p = p->next;
		free(node);
	}
}