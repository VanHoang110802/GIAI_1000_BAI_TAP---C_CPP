Tính tổng các giá trị có chữ số đầu tiên là chữ số lẻ trong mảng một chiều các số nguyên .

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
			printf("So luong phan tu nhap khong hop le!\n");
		}
	} while (n<1||n>Max);
}
void NhapMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("a[%d]= ", i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d  ", a[i]);
	}
}
int TachSo(int n) {
	int temp = n;
	int chuso1 = temp / 10;
	if (chuso1 % 2 == 0) {
		return 0;
	}
	else return 1;
}
void LietKe(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (TachSo(a[i])) {
			printf("%d ", a[i]);
		}
	}
}
int TinhTong(int a[], int n) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		if (TachSo(a[i])) {
			s += a[i];
		}
	}
	return s;
}
int main() {
	int a[Max], n;
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\n");
	LietKe(a, n);
	printf("\n");
	int tinh = TinhTong(a, n);
	printf("Tong = %d", tinh);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
