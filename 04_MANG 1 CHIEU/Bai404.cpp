Hãy xóa tất cả "số chính phương" trong mảng một chiều các số nguyên .

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include <math.h>
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
void NhapMang(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		printf("a[%d]= ", i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d  ", a[i]);
	}
}
int KiemTraSoCP(int n) {
	double kq = sqrt((double)n);
	if (kq == (int)kq) {
		return 1;
	}
	return 0;
}
void Xoa1PhanTu(int a[], int& n, int ViTriXoa) {
	for (int i = ViTriXoa; i < n; i++) {
		a[i] = a[i + 1];
	}
	n--;
}
void XoaPhanTuCP(int a[], int& n) {
	for (int i = 0; i < n; i++) {
		if (KiemTraSoCP(a[i])) {
			Xoa1PhanTu(a, n, i);
			i--;
		}
	}
}
int main() {
	int n, a[Max];
hoang:
	printf("\n");
	NhapDuLieu(n);
	NhapMang(a, n);
	printf("\n");
	XuatMang(a, n);
	XoaPhanTuCP(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
