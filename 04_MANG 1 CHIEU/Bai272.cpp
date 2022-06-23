Hãy tìm "giá trị dương nhỏ nhất và vị trí của nó" trong mảng một chiều các số thực.Nếu mảng không có giá trị dương thì trả về -1.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(float& n) {
	do {
		printf("Nhap so luong phan tu: ");
		scanf("%f", &n);
		if (n<1||n>Max) {
			printf("So luong phan tu nhap khong hop le!\n");
		}
	} while (n<1||n>Max);
}
void NhapMang(float a[], float n) {
	for (int i = 0; i < n; i++) {
		printf("a[%d]= ", i);
		scanf("%f", &a[i]);
	}
}
void XuatMang(float a[], float n) {
	for (int i = 0; i < n; i++) {
		printf("%.2f  ", a[i]);
	}
}
void TimGiaTriDuongMin(float a[], float n) {
	float min;
	int dem = 0, i, vitri = 0;
	for (i = 0; i < n; i++) {
		if (a[i] > 0) {
			dem++;
			break;
		}
	}
	if (dem != 0) {
		min = a[i];
		for (i = i + 1; i < n; i++) {
			if ((a[i] > 0) && (min > a[i])) {
				min = a[i];
				vitri = i;
			}
		}
		printf("\nMin = %.2f", min);
		printf("\nVi tri cua min = %d", vitri);
	}
	else printf("\nKhong tim thay gia tri duong nho nhat!");
}
int main() {
	float a[Max], n;
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\n");
	TimGiaTriDuongMin(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
