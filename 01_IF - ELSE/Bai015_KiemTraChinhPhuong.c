Kiểm tra 1 số nguyên dương x có phải là số chính phương hay không ?
Định nghĩa số chính phương : Là số mà kết quả khai căn bậc 2 của nó là 1 số nguyên.
vd : 0, 1, 4, 9, 16, 25, 36 ...

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main() {
	int n;
	printf("nhap so n = ");
	scanf("%d", &n);
	double kq = sqrt((double)n);
	if (n > 0) {
		if (kq == (int)kq) {
			printf("Day la so chinh phuong");
		}
		else {
			printf("Day khong la so chinh phuong");
		}
	}
	else {
		printf("So nhap khong hop le, n > 0");
	}
	
	return 0;
}
