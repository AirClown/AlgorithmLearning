#include<stdio.h>
#include<stdlib.h>
#include<time.h>

static const int L = 100;
static const int Max = 10;

//void FastSort(int *a) {
//
//	int b[L] = { Max };
//	int index = 0;
//	while (index < L) {
//		int down = 0;
//		int up = index;
//		int mid = index / 2;
//		while (mid!=down) {
//			if (b[mid] > a[index]) {
//				up = mid;
//				mid = (up + down) / 2;
//			}else {
//				down = mid;
//				mid = (down + up) / 2;
//			}
//		}
//
//		if (a[index] > b[mid]) {
//			for (int i = index; i > mid; i--) {
//				b[i + 1] = b[i];
//			}
//			b[mid + 1] = a[index];
//		}
//		else {
//			for (int i = index; i >= mid; i--) {
//				b[i + 1] = b[i];
//			}
//			b[mid] = a[index];
//		}
//
//		index++;
//
//		for (int i = 0; i < index; i++) {
//			printf("%d ", b[i]);
//		}
//		printf("\n");
//	}
//
//	for (int i = 0; i < L; i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//
//	/*for (int i = 0; i < L; i++) {
//		printf("%d ", b[i]);
//	}
//	printf("\n");*/
//}
//
//void swap(int &x, int &y) {
//	x += y;
//	y = x - y;
//	x = x - y;
//}
//
//void Partition(int *a) {
//	printf("mid:%d\n",a[0]);
//
//	int j = 0;
//	int key = a[0];
//	for (int i = j + 1; i < L; i++) {
//		if (a[i] < key) {
//			swap(a[++j], a[i]);
//		}
//	}
//	swap(a[0], a[j]);
//}

//����x��y��ֵ
void swap(int &x, int &y) {
	int temp=x;
	x = y;
	y = temp;
}

//aΪ���У����start���յ�end
void FastSort(int *a, int start, int end) {
	if (start >= end) {
		return;
	}

	//Patition��������key�ŵ����ʵ�λ�ã�ʹ������ߵ����������������ұߵ�������С����
	int key = a[start];
	int j = start;
	for (int i = start + 1; i <= end; i++) {
		if (a[i] < key) {         //��a[i]<keyʱ������a[++j]��a[i]
			swap(a[++j],a[i]);
		}
	}
	swap(a[start], a[j]);

	//��key���ߵ���������������
	FastSort(a,start, j - 1);
	FastSort(a,j + 1, end);
}

void FastSort2(int *a, int start, int end) {
	if (start >= end) {
		return;
	}

	int key = a[start];
	int i = start;
	int j = start;
	int k = end;

	while (i <= k) {
		if (a[i] < key) {
			swap(a[i++], a[j++]);
		}
		else if (a[i] > key) {
			swap(a[i], a[k--]);
		}
		else {
			i++;
		}
	}

	FastSort2(a, start, j);
	FastSort(a, k + 1, end);
}

void main() {
	srand((unsigned)time(NULL));
	int a[L] = { 0 };

	for (int i = 0; i < L; i++) {
		a[i] = rand() % Max;
	}


	for (int i = 0; i < L; i++) {
		printf("%d,", a[i]);
	}
	printf("\n");

	FastSort2(a, 0, L - 1);

	for (int i = 0; i < L; i++) {
		printf("%d,", a[i]);
	}

	system("pause");
}