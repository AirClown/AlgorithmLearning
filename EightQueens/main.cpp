#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<math.h>

enum MyEnum
{
	Q = 1,
	W = 2
};

static const int L = 8;

int Queens(int a[][L], int num) {

	if (num == L) {
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < L; j++) {
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		return 1;
	}

	int b[L][L];
	int count = 0;

	for (int i = 0; i < L; i++) {
		if (a[num][i] == 0) {
			memcpy(b, a, sizeof(int)*L*L);

			b[num][i] = Q;

			for (int j = 0; j < L; j++) {
				if (b[num][j] == 0) {
					b[num][j] = W;
				}

				if (b[j][i] == 0) {
					b[j][i] = W;
				}
			}

			for (int j = 0, k = num, m = i; j < L; j++) {
				if (--k < 0) {
					break;
				}

				if (--m < 0) {
					break;
				}

				b[k][m] = W;
			}

			for (int j = 0, k = num, m = i; j < L; j++) {
				if (++k >= L) {
					break;
				}

				if (++m >= L) {
					break;
				}

				b[k][m] = W;
			}

			for (int j = 0, k = num, m = i; j < L; j++) {
				if (--k <0) {
					break;
				}

				if (++m >= L) {
					break;
				}

				b[k][m] = W;
			}

			for (int j = 0, k = num, m = i; j < L; j++) {
				if (++k >=L) {
					break;
				}

				if (--m <0) {
					break;
				}

				b[k][m] = W;
			}
		
			count+=Queens(b, num + 1);
		}
	}

	return count;
}

int Queens2(int *b, int num) {
	int count = 0;

	if (num == L) {
		return 1;
	}
	else {
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < num; j++) {
				if (b[j] == i||abs(num-j)==abs(i-b[j])) {
					goto next;
				}
			}
			b[num] = i;
			count += Queens2(b, num + 1);
		next:
			continue;
		}
	}

	return count;
}

int Queens3(int *b, int num) {
	int count = 0;
	if (num == L) return 1;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < num; j++)
			if (b[j] == i || abs(num - j) == abs(i - b[j])) goto next;
		b[num] = i;
		count += Queens2(b, num + 1);
	next:continue;
	}
	return count;
}

void main() {

	int a[L][L] = { 0 };
	int b[L];

	int count = Queens3(b,0); //Queens(a, 0);

	printf("Queen sum:%d\n", count);

	system("pause");
}