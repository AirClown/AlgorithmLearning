#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

static const int L = 7;

struct Edge {
	int start;
	int end;
	int length;
};

void main() {
	const int a[L][L] = {
		{ 0,12, 0, 0, 0,16,14},
		{12, 0,10, 0, 0, 7, 0},
		{ 0,10, 0, 3, 5, 6, 0},
		{ 0, 0, 3, 0, 4, 0, 0},
		{ 0, 0, 5, 4, 0 ,2, 8},
		{16, 7, 6, 0, 2, 0, 9},
		{14, 0, 0, 0, 8, 9, 0}
	};
	int b[L][L];
	memcpy(b,a,L*L*sizeof(int));
	int c[L] = { 0 };
	Edge d[L - 1];

	for (int i = 1,n=0; i < L;) {
		int min = 100;
		int x = 0;
		int y = 0;

		for (int j = 0; j < i; j++) {
			int index = c[j];
			for (int k = 0; k < L; k++) {
				if (b[index][k] > 0 && b[index][k] < min) {
					min = b[index][k];
					x = index;
					y = k;
				}
			}
		}

		for (int j = 0; j < i; j++) {
			if (c[j] == y) {
				printf("Hello:%d,%d,%d\n", x, y, min);
				goto con;
			}
		}

		c[i++] = y;
		d[n].start = x;
		d[n].end = y;
		d[n].length = a[x][y];
		n++;
	con:
		b[x][y] = 100;
		continue;
	}

	for (int i = 0; i < L - 1; i++) {
		printf("%d->%d:%d\n",d[i].start,d[i].end,d[i].length);
	}

	system("pause");
}