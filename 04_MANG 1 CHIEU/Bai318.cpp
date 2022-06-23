Hãy liệt kê các vị trí mà giá trị tại các vị trí đó là giá trị dương nhỏ nhất trong mảng một chiều các số thực .
/*
mang:  -1 -3 1 6 9 8 1 7 2 4 1
vi tri  0  1 2 3 4 5 6 7 8 9 10 
-> vi tri can tim: 2 6 10
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(int& n) {
	do {
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if (n<1||n>Max) {
			printf("So luong phan tu nhap khong hop le!\n");
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
int TimDuongDauTien(float a[], int n) {
	for (int i = 0; i<n; i++) {
		if (a[i] > 0) return a[i];
		
	}
	 return -1;
}
float TimGiaTriDuongMin(float a[], int n) {
	float DuongMin = TimDuongDauTien(a, n);
	for (int i = 0; i < n; i++) {
		if (a[i] > 0 && a[i] < DuongMin) {
			DuongMin = a[i];
		}
	}
	return DuongMin;
}
void LietKe(float a[], int n) {
	printf("\nCac vi tri thoa man de bai: ");
	float min = TimGiaTriDuongMin(a, n);
	for (int i = 1; i < n; i++) {
		if (a[i] == min) {
			printf("%d ", i);
		}
	}
	
}
int main() {
	float a[Max];
	int n;
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\n");
	LietKe(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
