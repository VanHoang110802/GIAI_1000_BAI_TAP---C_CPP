Tìm "số hoàn thiện cuối cùng" trong mảng một chiều các số nguyên.Nếu mảng không có số hoàn thiện thì trả về giá trị -1.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
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
int KiemTraSoHT(int n) {
	int temp = n;
	int s = 0;
	for (int i = 1; i < temp; i++) {
		if (n % i == 0) {
			s += i;
		}
	}
	if (s == n) {
		return 1;
	}
	else return 0;
}
int TimSoHTCuoi(int a[], int n) {
	for (int i = n - 1; i >= 0; i--) {
		if (KiemTraSoHT(a[i])) return a[i];
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
	int tim = TimSoHTCuoi(a, n);
	printf("So hoan thien cuoi cung: %d", tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
