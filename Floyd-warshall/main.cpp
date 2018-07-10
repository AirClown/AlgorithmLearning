#include<stdio.h>
#include<Windows.h>
static const int L =5;

void main(){
	int a[L][L] = {
		{0,6,3,0,0},
		{0,0,4,2,0},
		{0,2,0,3,5},
		{0,0,0,0,1},
		{0,1,0,5,0}
	};

	int b[L][L];
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			

			if (a[i][j] == 0) {
				a[i][j] = 1000;
			}

			b[i][j] = a[i][j];
		}
	}

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			for (int k = 0; k < L; k++) {
				if (j != i&&k != i&&b[j][k] > a[j][i] + a[i][k]) {
					b[j][k] = a[j][i] + a[i][k];
				}
			}
		}

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < L; j++) {
				printf("%d ", b[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	system("pause");
}