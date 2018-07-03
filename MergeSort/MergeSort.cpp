#include"stdafx.h"

static const int L = 200;
static const int R = 200;

int count = 0;
void MergeSort(int *a,int *b,int start,int end) {
	if (start >= end) {
		return;
	}

	int mid = (start + end) / 2;

	MergeSort(a, b, start, mid);
	MergeSort(a, b, mid + 1, end);

	int i = start;
	int j = mid + 1;
	int n = start;
	while (n <= end) {
		if ((a[i] <= a[j]&&i<=mid )|| j > end) {
			b[n++] = a[i++];
		}

		if ((a[j] <= a[i]&&j<=end) || i > mid) {
			b[n++] = a[j++];
		}
	}

	for (int i = start; i <= end; i++) {
		a[i] = b[i];
	}

	/*for (int i = 0; i < L; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");*/
}

int main()
{
	srand((unsigned)time(NULL));
	int a[L] = { 0 };

	for (int i = 0; i < L; i++) {
		a[i] = rand() % R;
	}

	for (int i = 0; i < L; i++) {
		printf("%d ", a[i]);
	}
	printf("\n\n");

	int b[L] = { 0 };
	MergeSort(a, b, 0, L - 1);


	for (int i = 0; i < L; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	system("pause");
    return 0;
}

