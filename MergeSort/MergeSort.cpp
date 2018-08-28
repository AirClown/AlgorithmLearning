#include"stdafx.h"

static const int L = 100;
static const int R = 200;

int count = 0;
//void MergeSort(int *a,int *b,int start,int end) {
//	if (start >= end) {
//		return;
//	}
//
//	int mid = (start + end) / 2;
//
//	MergeSort(a, b, start, mid);
//	MergeSort(a, b, mid + 1, end);
//
//	int i = start;
//	int j = mid + 1;
//	int n = start;
//	while (n <= end) {
//		if ((a[i] <= a[j]&&i<=mid )|| j > end) {
//			b[n++] = a[i++];
//		}
//
//		if ((a[j] <= a[i]&&j<=end) || i > mid) {
//			b[n++] = a[j++];
//		}
//	}
//
//	for (int i = start; i <= end; i++) {
//		a[i] = b[i];
//	}
//
//	/*for (int i = 0; i < L; i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");*/
//}

////num -- 待排序的数组
////start -- 排序的起点
////end -- 排序数组最后一位
//void MergeSort(int *num, int start, int end) {
//
//	//判断起点是否小于终点
//	if (start >= end) {
//		return;
//	}
//
//	//进行分割操作
//	int mid = (start + end) / 2;
//	MergeSort(num, start, mid);
//	MergeSort(num, mid+1, end);
//
//	// 对分割数列进行归并
//	int i = start;
//	int j = mid+1;
//	int index = 0;
//
//	//需要一个临时数组来存放排序好的数据
//	int *temp = (int *)malloc(sizeof(int)*(end - start+1));
//
//	while (index + start<=end) {
//		//从两个子序列中取出数据放入临时数组
//		if ((i<=mid) && (j > end || num[i]<num[j])) {
//			temp[index++] = num[i++];
//		}
//		else {
//			temp[index++] = num[j++];
//		}
//	}
//
//	//将临时数组的值重现赋给数组
//	for (int i = start; i<=end; i++) {
//		num[i] = temp[i - start];
//	}
//
//	//释放临时数组
//	free(temp);
//}
void Merge(int *nums, int start, int mid, int end) {
	//需要一个临时数组来存放排序好的数据
	int *temp = (int *)malloc(sizeof(int)*(end - start));

	// 对分割数列进行归并
	int i = start;
	int j = mid;
	int index = 0;

	while (index + start < end) {
		//从两个子序列中取出数据放入临时数组
		if (i < mid && (j == end || nums[i] < nums[j])) {
			temp[index++] = nums[i++];
		}
		else {
			temp[index++] = nums[j++];
		}
	}

	//将临时数组的值重现赋给数组
	for (int i = start; i < end; i++) {
		nums[i] = temp[i - start];
	}

	//释放临时数组
	free(temp);
}

//nums -- 待排序数组
//length -- 数组长度
void MergeSort(int *nums, int length) {

	//i每次乘2，是因为每次合并以后小组元素也变成两倍了
	for (int i = 1; i < length; i *= 2) {

		//对拥有2的幂次方个数值的小组进行两两合并
		int index = 0;
		while (2 * i + index <= length) {
			index += 2 * i;
			Merge(nums, index - 2 * i, index - i, index);
		}

		//index+i<length 说明剩余两个小组，但其中一个小组值得数量不满足2的幂次个，对两个小组进行合并
		if (index + i <length) {
			Merge(nums, index, index + i, length);
		}
	}
}

//num -- 待排序的数组
//start -- 排序的起点
//end -- 排序数组最后一位
void MergeSort(int *nums, int start, int end) {

	//判断起点是否小于终点
	if (end-start<2) {
		return;
	}

	//进行分割操作
	int mid = (start + end) / 2;
	MergeSort(nums, start, mid);
	MergeSort(nums, mid , end);

	//归并两个子列
	Merge(nums, start, mid, end);
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
	MergeSort(a,0, L);


	for (int i = 0; i < L; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	system("pause");
    return 0;
}

