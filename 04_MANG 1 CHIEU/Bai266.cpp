Tìm "giá trị dương đầu tiên" trong mảng một chiều các số thực. Nếu mảng không có giá trị dương thì trả về giá trị -1.

/*
Tìm "giá trị dương đầu tiên" trong mảng một chiều các số thực. Nếu mảng không có giá trị dương thì trả về giá trị -1.
vd: -1.2 -2.9 1.1 7.0 9.6
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#define Max 100
void NhapDuLieu(int& n) {
	do {
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if (n<1||n>Max) {
			printf("So luong phan tu nhap khong hop le, xin hay kiem tra lai!\n");
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
		printf("%.2f ", a[i]);
	}
}
float TimGiaTriDuongDau(float a[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] >= 0) {
			return a[i];
		}
	}
	return -1;
}
int main() {
	int n;
	float a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	float tim = TimGiaTriDuongDau(a, n);
	printf("\nPhan tu duong dau trong mang: %.1f", tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
