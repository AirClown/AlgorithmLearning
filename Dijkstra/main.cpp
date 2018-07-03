#include<stdio.h>
#include<windows.h>

static const int L = 6;

//a为邻接矩阵，start和end为起点和终点
int fun(int a[][L],  int start,int end) {
	int index = 0;
	int b[L] = { 0 };
	int length[L] = { 0 };

	b[index] = start;

	while (index < (L-1)) {
		int min = 1000;
		int sign = 0;

		for (int i = 0; i <= index; i++) {
			for (int j = 0; j < L; j++) {
				if (a[b[i]][j]>0) {
					for (int k = 0; k <= index; k++) {
						if (b[k] == j) {
							goto out;
						}
					}

					if (min > a[b[i]][j]) {
						min = a[b[i]][j];
						sign = j;
					}
				}

			out:
				continue;
			}
		}

		b[++index] = sign;
		length[sign] = 1000;
		for (int i = 0; i < index; i++) {
			if (a[b[i]][sign] > 0) {
				int x = a[b[i]][sign] + length[b[i]];

				if (length[sign]> x) {
					length[sign]= x;
				}
			}
		}

		printf("%d,%d\n",sign,length[sign]);
	}

	return length[end];
}

void main() {
	int a[L][L] = {
		{0,0,10,0,30,100},
		{0,0,5,0,0,0},
		{10,5,0,50,0,0},
		{0,0,50,0,20,10},
		{30,0,0,20,0,60},
		{100,0,0,10,60,0} 
	};

	int min = fun(a,2,5);

	printf("%d\n", min);

	system("pause");
}