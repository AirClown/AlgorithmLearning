#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

static const int L = 9;
static const int R = 10;

int Fun1(int *a,int k) {
	int start = 0;
	int Remind = L;

	while (Remind > 1) {
		int x = (start + k - 1) % Remind;

		for (int i = x + 1; i < Remind; i++) {
			a[i - 1] = a[i];
		}

		start = x == Remind ? 0 : x;
		Remind--;
	}

	return a[0];
}

int Fun2(int k,int n) {
	int x = 0;
	for (int i = 0; i < n; i++) {
		x = (x + k) % (i+1);
	}

	return x;
}

int Fun3(int n, int k) {
	if (k < n) {
		int res = Fun3(n - n / k, k);

		if (res < n%k) {
			res = res + n - n%k;
		}
		else {
			res = res + (res - n%k) / (k - 1) +k*(int)(n/k)-n;
		}

		//res%=n;

		return res;
	}
	else {
		return Fun2( k,n);
	}
}

void main() {
	srand((unsigned)time(NULL));

	int x[L];

	for (int i = 0; i < L; i++) {
		x[i] = i;
		printf("%d ", x[i]);
	}
	printf("\n");

	printf("the last one is:%d\n",Fun3(L,2));

	system("pause");
}