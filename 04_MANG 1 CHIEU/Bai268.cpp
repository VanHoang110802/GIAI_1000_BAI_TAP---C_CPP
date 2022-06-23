Tìm "một vị trí mà giá trị tại vị trí đó là giá trị nhỏ nhất" trong mảng một chiều các số thực.

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
void TimViTriGiaTriNhoNhat(float a[], int n) {
	float min = a[0];
	int vitri = 0;
	for (int i = 0; i <n; i++) {
		if (a[i] < min) {
			min = a[i];
			vitri = i;
		}
	}
	printf("\nGia tri nho nhat trong mang la %.2f tai vi tri %d", min, vitri+1);
}
int main() {
	int n;
	float a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	TimViTriGiaTriNhoNhat(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
