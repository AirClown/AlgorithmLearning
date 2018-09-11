#include<stdio.h>
#include<math.h>
#include<Windows.h>

//a fucking function
float Q_rsqrt(float number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;
	x2 = number * 0.5F;
	y = number;
	i = *(long *)&y;   // evil floating point bit level hacking
	i = 0x5f3759df - (i >> 1); // what the fuck?
	y = *(float *)&i;
	y = y * (threehalfs - (x2 * y * y)); // 1st iteration
										 // y   = y * ( threehalfs - ( x2 * y * y ) ); // 2nd iteration, this can be removed

#ifndef Q3_VM
#ifdef __linux__
	assert(!isnan(y)); // bk010122 - FPE?
#endif
#endif
	return y;
}

double mySqrt(double a,int k) {
	if (k == 1) {
		return a;
	}

	double x = a;

	while ( pow(x, k) > a) {
		x = (x*(k - 1) + a / pow(x, k - 1)) / k;
	}

	return x;
}

double mySqrt(double a) {
	double x = a;

	while (x*x > a) {
		x = (x + a / x) / 2;
	}

	return x;
}

int main(int a) {

	printf("%f\n", mySqrt(12345));

	printf("%f\n", mySqrt(64,6));

	printf("%f\n", 1/Q_rsqrt(12345));

	system("pause");
	return 0;
}