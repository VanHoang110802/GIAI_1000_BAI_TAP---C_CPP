Hãy xóa tất cả các "số nguyên tố" có trong mảng số nguyên .

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
int KiemTraSoNT(int n) {
	int check = 1, temp = n;
	if (temp < 2) {
		check = 0;
	}
	else {
		if (temp > 2 && temp % 2 == 0) {
			check = 0;
		}
		else {
			for (int i = 2; i * i <= temp; i++) {
				if (temp % i == 0) {
					check = 0;
					break;
				}
			}
		}
	}
	if (check == 1) {
		return 1;
	}
	return 0;
}
void Xoa1PhanTu(int a[], int& n, int ViTriXoa) {
	for (int i = ViTriXoa; i < n; i++) {
		a[i] = a[i + 1];
	}
	n--;
}
void XoaPhanTuNT(int a[], int& n) {
	for (int i = 0; i < n; i++) {
		if (KiemTraSoNT(a[i])) {
			Xoa1PhanTu(a, n, i);
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
	XoaPhanTuNT(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
