Nhập vào 4 số nguyên a, b, c, d. In ra màn hình kết quả số lớn nhất, nhỏ nhất

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
int main() {
	int a, b, c, d;
	printf("nhap a, b, c, d: ");
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int min, max;
	min = a < b ? a : b;
	min = min < c ? min : c;
	min = min < d ? min : d;
	max = a > b ? a : b;
	max = max > c ? max : c;
	max = max > d ? max : d;
	printf("min = %d", min);
	printf("\nmax = %d", max);
	return 0;
}
