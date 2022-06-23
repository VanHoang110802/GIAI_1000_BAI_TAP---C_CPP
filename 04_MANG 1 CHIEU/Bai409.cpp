Hãy đưa số một về đầu mảng .
/*
Ta sẽ xét duyệt từ vị trí có phần tử cần đưa về đầu mảng về vị trí đầu tiên, ngay tại vị trí đầu tiên đó, hoán đổi giá trị phần tử đầu tiên đó cho phần tử cần đưa về đầu.
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
			printf("So luong phan tu nhap khong hop le, xin hay kiem tra lai!\n");
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
		printf("%d ", a[i]);
	}
}
void DoiChoVeViTriBanDau(int a[], int n, int vitridoi, int socandoi) {
	for (int i = vitridoi; i >= 0; i--) {
		a[i] = a[i - 1];
	}
	a[0] = socandoi;
}
void Dua1VeDau(int a[], int n, int x) {		// x là số cần đưa về đầu
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			DoiChoVeViTriBanDau(a, n, i,a[i]);
		}
	}
}
int main() {
	int n,a[Max],x;
	hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("Nhap x can dua ve dau: \n(x phai la so thuoc o trong mang) ");
	scanf("%d", &x);
	Dua1VeDau(a, n,x);
	printf("\n");
	XuatMang(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if (lc == 'c' || lc == 'C') {
		goto hoang;
	}
	return 0;
}
