#include"utils.hpp"

using namespace std;

static const int L = 8;
static const int H = 5;

enum MyEnum
{
	N = 0,
	W = 1,
	R = 2,
	S = 3,
	E = 4
};

void DrewPic(int a[][L]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < L; j++) {
			switch (a[i][j])
			{
			case W:
				printf("##");
				break;
			case N:
				printf("00");
				break;
			case R:
				printf("--");
				break;
			case S:
				printf("@@");
				break;
			case E:
				printf("$$");
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
	printf("\n");
}

void main() {
	int a[H][L] = {
		{ N,N,N,W,N,N,N,N },
		{ N,N,N,W,N,W,N,N },
		{ N,S,N,W,N,W,E,N },
		{ N,N,N,W,N,W,W,W },
		{ N,N,N,N,N,N,N,N }
	};
	int b[H][L] = { 0 };
	memcpy( b,a, L*H * sizeof(int));


	List openlist;
	List closelist;

	Position End = {
		End.x = 2,
		End.y = 6
	};

	Position *p = (Position *)malloc(sizeof(Position));
	p->x = 2;
	p->y = 1;
	p->G = 0;
	p->H = 0;
	p->parent = NULL;
	closelist.AddOne(p);

	int count = 0;

	while (p->x!=End.x||p->y!=End.y){

		printf("step:%d\n", ++count);
		for (int i = p->x - 1; i < p->x + 2; i++) {
			if (i >= 0 && i < H) {
				for (int j = p->y - 1; j < p->y + 2; j++) {
					if (j >= 0 && j < L) {
						if (a[i][j] != W&&closelist.Find(i, j) == NULL) {
							Position *node = openlist.Find(i, j);

							if (node == NULL) {
								node = (Position *)malloc(sizeof(Position));
								node->x = i;
								node->y = j;
								node->H = 10*(abs(i - End.x) + abs(j - End.y));
								if ((abs(i - p->x) + abs(j - p->y)) == 2) {
									node->G = p->G + 14;
								}
								else {
									node->G = p->G + 10;
								}
								node->parent = p;
								openlist.AddOne(node);
							}else {
								int g1 = node->parent->G;
								int g2 = p->G;

								if ((abs(i - node->parent->x) + abs(j - node->parent->y)) == 2) {
									g1 += 14;
								}
								else {
									g1 += 10;
								}

								if ((abs(i - p->x) + abs(j - p->y)) == 2) {
									g2 += 14;
								}
								else {
									g2 += 10;
								}

								if (g1 > g2) {
									openlist.Delet(i, j);
									node->parent = p;
									node->G = g2;
									openlist.AddOne(node);
								}
							}
						}
					}
				}
			}
		}

		p = openlist.FindMin();
		if (p == NULL) {
			printf("Errow\n");
			goto end;
		}
		else {
			openlist.Delet(p->x, p->y);
			closelist.AddOne(p);

			printf("process:%d,%d\n", p->x, p->y);
		}
	}

	p = closelist.Find(End.x, End.y);
	while (p != NULL) {
		printf("x:%d,y:%d\n", p->x, p->y);
		b[p->x][p->y] = R;
		p = p->parent;
	}

	DrewPic(a);
	DrewPic(b);

end:
	openlist.DestroyList();
	closelist.DestroyList();
	system("pause");
}
