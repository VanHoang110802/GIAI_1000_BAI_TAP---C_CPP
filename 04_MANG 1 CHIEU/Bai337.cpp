Tính trung bình cộng các số nguyên tố trong mảng một chiều các số nguyên

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
void NhapMang(float a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("a[%d]= ", i);
		scanf("%f", &a[i]);
	}
}
void XuatMang(float a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%.f  ", a[i]);
	}
}
int KiemTraSoNT(int n) {
	int temp = n;
	if (temp < 2) {
		return 0;
	}
	else {
		if (temp > 2 && temp % 2 == 0) {
			return 0;
		}
		else {
			for (int i = 2; i * i <= temp; i++) {
				if (temp % i == 0) {
					return 0;
				}
			}
		}
	}
	return 1;
}
float TinhTBCSoNT(float a[], int n) {
	int dem = 0;
	float s1 = 0,s2;
	for (int i = 0; i < n; i++) {
		if (KiemTraSoNT(a[i])) {
			dem++;
			s1 += a[i];
		}
	}
	return s2 = s1/dem;
}

int main(){
	float a[Max]; int n;
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\n");
	float tinh = TinhTBCSoNT(a, n);
	printf("Trung binh cong cua cac so nguyen to: %.3f",tinh);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
