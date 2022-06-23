Tìm "số nguyên tố cuối cùng" trong mảng một chiều các số nguyên.Nếu mảng không có số nguyên tố thì trả về giá trị -1.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
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
int KiemTraSoNT(int n) {
	int temp = n, check = 1;
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
				}
			}
		}
	}
	if (check == 1 && n>= 2) {
		return 1;
	}
	else return 0;
}
int TimSoNTCuoi(int a[], int n) {
	for (int i = n - 1; i >= 0; i--) {
		if (KiemTraSoNT(a[i])) return a[i];
	}
	return -1;
}
int main() {
	int a[Max], n;
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\n");
	int tim = TimSoNTCuoi(a, n);
	printf("So nguyen to cuoi cung: %d", tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
