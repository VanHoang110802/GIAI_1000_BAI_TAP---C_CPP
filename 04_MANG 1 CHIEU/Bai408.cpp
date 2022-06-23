Hãy xóa tất cả các phần tử có tần suất xuất hiện trong mảng nhiều hơn một lần .
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

void Xoa1PhanTu(int a[], int& n, int ViTriXoa) {
	for (int i = ViTriXoa; i < n; i++) {
		a[i] = a[i + 1];
	}
	n--;
}
void XoaCacPhanTuXuatHienNhieuHon1Lan(int a[], int& n){
	for (int i = 0; i < n - 1; i++){
		int check = 0;
		for (int j = i + 1; j < n; j++){
			if (a[i] == a[j]){
				Xoa1PhanTu(a, n, j);
				j--;
				check = 1;
			}
		}
		if (check == 1){
			Xoa1PhanTu(a, n, i); // Xóa luôn chính nó
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
	XoaCacPhanTuXuatHienNhieuHon1Lan(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
