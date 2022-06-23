Giải phương trình bậc 1 có dạng: ax + b = 0.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
int main() {
	int a, b;
	printf("nhap a= ");
	scanf("%d", &a);
	printf("nhap b= ");
	scanf("%d", &b);
	if (a == 0) {
		if (b == 0) {
			printf("phuong trinh co vo so nghiem");
		}
		else {
			printf("phuong trinh vo nghiem");
		}
	}
	else {
		printf("phuong trinh co nghiem = %d", -b / a);
	}
	return 0;
}
