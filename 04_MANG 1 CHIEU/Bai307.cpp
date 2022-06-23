Hãy liệt kê các giá trị trong mảng một chiều các số thực thuộc đoạn [x,y] cho trước

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define Max 100
void NhapDuLieu(int& n) {
	do {
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if (n<1||n>Max) {
			printf("Phan tu nhap khong hop le, xin hay kiem tra lai!\n");
		}
	} while (n<1||n>Max);
}
void NhapMang(float a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("a[%d]= ", i);
		scanf("%f", &a[i]);
	}
}
void XuatMang(float a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%.2f  ", a[i]);
	}
}

void LietKeTrongDoanXY(float a[], int n, float x, float y) {
	for (int i = 0; i < n; i++) {
		if (x <= a[i] && a[i] <= y) {
			printf("\n%.2f  ", a[i]);
		}
	}
}
int main() {
	int n;
	float a[Max];
	float x, y;
hoang:
	printf("\nNhap x: ");
	scanf("%f", &x);
	printf("\nNhap y: ");
	scanf("%f", &y);
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\nCac so trong mang thuoc [%.3f, %.3f] la: ", x, y);
	LietKeTrongDoanXY(a, n, x, y);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
