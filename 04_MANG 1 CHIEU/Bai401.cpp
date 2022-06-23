Hãy xóa tất cả số lớn nhất trong mảng các số thực .

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
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
		printf("%.3f ", a[i]);
	}
}
void Xoa1PhanTu(float a[], int &n, int vitrixoa) {
	for (int i = vitrixoa; i < n; i++) {
		a[i] = a[i + 1];
	}
	n--;
}
float TimMax(float a[], int n) {
	float max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}
void XoaSoLonNhat(float a[], int &n) {
	float max = TimMax(a, n);
	for (int i = 0; i < n; i++) {
		if (a[i] == max) {
			Xoa1PhanTu(a, n, i);
			i--;
		}
	}
}
int main() {
	int n;
	float a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	XoaSoLonNhat(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
