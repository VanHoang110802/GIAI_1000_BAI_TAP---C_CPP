Viết hàm đếm số lượng số nguyên tố nhỏ hơn 100 trong mảng.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include <math.h>
#define Max 100
void NhapDuLieu(int& n) {
	do {
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if (n< 1 || n > Max) {
			printf("So luong phan tu nhap khong hop le, xin hay kiem tra lai!\n");
		}
	} while (n< 1 || n > Max);
}
void NhapMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("a[%d]= ",i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}
int KiemTraNguyenTo(int n){
	if (n < 2){
		return 0;
	}
	else if (n > 2){
		if (n % 2 == 0){
			return 0;
		}
		for (int i = 3; i <= sqrt((float)n); i += 2){
			if (n % i == 0){
				return 0;
			}
		}
	}
	return 1;
}

int demnguyento(int a[], int n){
	int dem = 0;
	for (int i = 0; i < n; i++){
		if (KiemTraNguyenTo(a[i]) == 1&& a[i] < 100){
			dem++;
		}
	}
	return dem;
}
int main() {
	int n,a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	int dem = demnguyento(a, n);
	printf("\nSo luong so nguyen to co trong mang la: %d", dem);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
