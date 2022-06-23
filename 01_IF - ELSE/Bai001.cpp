Nhập vào 2 số nguyên a, b. In ra màn hình kết quả số lớn nhất, nhỏ nhất

#define _CRT_SECURE_NO_WARNINGS // visual studio thì dùng cái này để tránh lỗi. 
#include <stdio.h>
#include <conio.h>
int main() {
	int a, b;
	printf("nhap a= ");
	scanf("%d", &a);
	printf("nhap b= ");
	scanf("%d", &b);
	int min, max;
	min = a < b ? a : b;
	max = a > b ? a : b;
	printf("\nmax = %d, min = %d", max, min);
	return 0;
}
