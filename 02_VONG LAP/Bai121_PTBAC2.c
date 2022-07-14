Giải phương trình 𝑎𝑥^2 + 𝑏𝑥 + 𝑐 = 0.
/*
phương trình: x^2+x-6=0
->x1 = 2
->x2 = -3
 - không được do-while ở chỗ nhập xuất các phần tử của phương trình vì phương trình sẽ có số âm.
*/

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main() {
hoang:
	int a, b, c;
	float x1, x2, denta;
	printf("nhap a, b, c = ");
	scanf("%d%d%d", &a, &b, &c);
	if (a == 0) {				// ---- phương trình có dạnh bx+c=0 -----
		if (b == 0) {
			if (c == 0) {
				printf("phuong co vo so ngiem");
			}
			else {
				printf("phuong trinh vo nghiem");
			}
		}
		else {
			printf("x= %.3f", -b / c);
		}
	}
	else {
		denta = b * b - 4 * a * c;
		if (denta < 0) {
			printf("\nphuong trinh vo nghiem");
		}
		else if (denta == 0) {
			printf("\nphuong trinh co nghiem kep, x1=x2= %.3f", -b / (2 * a));
		}
		else {
			x1 = (-b + sqrt(denta)) / (2 * a);
			x2 = (-b - sqrt(denta)) / (2 * a);
			printf("x1= %.3f\nx2= %.3f", x1, x2);
		}
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
