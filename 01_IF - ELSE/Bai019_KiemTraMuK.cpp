Kiểm tra số nguyên 4 byte có dạng a^k hay không ? với a là số nhập vào từ bàn phím (2 <= a <= 9). Biết k sẽ là 1 số bất kỳ nào đó bắt đầu từ 0 -->
vd1: Nhập số 4 và a = 3 => không thỏa
vd2: Nhập số 4 và a = 2 => thỏa

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main() {
	int k,a;
	printf( "nhap k = ");
	scanf("%d",&k);
	printf("nhap so ngu a = ");
	scanf_s("%d", &a);
	double kq = log10((double)k) / log10(a);
	if (kq == (int)kq)
	{
		printf( "\nCo dang %d^%d",a,(int)kq);
	}
	else
	{
		printf("\nKhong co dang a^k");
	}
	return 0;
}
