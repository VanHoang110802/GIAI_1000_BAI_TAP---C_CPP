Tính trung bình nhân các số dương trong mảng một chiều các số thực .
/*
trung bình tích của số = cănN(a*b*c...);
mảng: 1 2 3 4 5
-> tích = 2.605
*/
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
float TinhTBNCacSoDuong(int a[], int n){
	int tich = 1;
	float dem = 0;
	for (int i = 0; i < n; i++){
		if (a[i] > 0){
			tich *= a[i];
			dem++;
		}
	}
	if (dem == 0){
		printf("\nMang khong co so thoa yeu cau");
		return 0;
	}
	return pow(tich, 1.0 / dem);
}
int main(){
	int n, a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	float kt = TinhTBNCacSoDuong(a, n);
	printf("\nTrung binh tich cua cac so duong la: %.3f", kt);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
