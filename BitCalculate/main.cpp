#include<stdio.h>
#include<Windows.h>

int Addition(int num1, int num2);
int Subtraction(int num1, int num2);

void printfBit(int num) {
	if (num > 0) {
		printf(" ");
	}
	printf("%d:", num);
	int bit[32] = { 0 };
	for (int i = 0; i < 32; i++) {
		bit[i] = num & 1;
		num = num >> 1;
	}

	for (int i = 31; i >= 0; i--) {
		printf("%d", bit[i]);
	}
	printf("\n");
}

int Opposite(int num) {
	return Addition(~num,1);
}

int Addition(int num1, int num2) {
	int x = num1 ^ num2;
	int y = num1 & num2;

	while (y != 0) {
		y = y << 1;
		int temp = x;
		x = x ^ y;
		y = temp & y;
	}

	return x;
}

int Subtraction(int num1, int num2) {
	int x = num1 ^ num2;
	int y = x & num2;

	while (y != 0) {
		y = y << 1;
		x = x ^ y;
		y = x & y;
	}

	return x;
}

int main() {
	int num1 = -2;
	int num2 = 2;

	printfBit(num1);
	printfBit(num2);

	printf("Addition:\nsys:%d\nmy:%d\n",num1+num2,Addition(num1, num2));

	printf("\nSubtraction:\nsys:%d\nmy:%d\n", num1 - num2, Subtraction(num1, num2));

	system("pause");
	return 0;
}