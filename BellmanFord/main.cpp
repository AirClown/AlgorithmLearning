#include<stdio.h>
#include<Windows.h>

static const int L = 5;

void main() {

	const int a[L][L] = {
		{ 0,-1, 4, 0, 0},
		{ 0, 0, 3, 2, 2},
		{ 0, 0, 0, 0, 0},
		{ 0, 1, 5, 0, 0},
		{ 0, 0, 0,-3, 0}
	};

	int b[L] = { 0 };
	for (int i = 1; i < L; i++) {
		b[i] = 1000;
	}

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			for (int k = 0; k < L; k++) {
				if (a[j][k] != 0 && b[j] + a[j][k] < b[k]) {
					b[k] = b[j] + a[j][k];
				}
			}
		}
	}

	for (int j = 0; j < L; j++) {
		for (int k = 0; k < L; k++) {
			if (a[j][k] > 0 && b[j] + a[j][k] < b[k]) {
				printf("Impossible!\n");
				goto end;
			}
		}
	}

	for (int i = 0; i < L; i++) {
		printf("%d,,,,,,%d\n",i,b[i] );
	}

end:
	system("pause");
}