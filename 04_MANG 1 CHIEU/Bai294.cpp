Tìm số chính phương đầu tiên trong mảng một chiều các số nguyên

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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
		printf("%d ", a[i]);
	}
}
int KiemTraSoCP(int n) {
	double kq = sqrt((double)n);
	if (kq == (int)kq) {
		return 1;
	}
	else return 0;
}
int TimSoCPDau(int a[], int n) {
	int dem = 0, i;
	for (i = 0; i < n; i++) {
		if (KiemTraSoCP(a[i])) {
			dem++;
			break;
		}
	}
	if (dem == 0) {
		return 0;
	}
	else
	{
		for (i = 1; i < n; i++)
		{
			if (KiemTraSoCP(a[i]))
			{
				return a[i];
			}
		}
	}
	
}
int main() {
	int a[Max], n;
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	int tim = TimSoCPDau(a,n);
	printf("\nSo chinh phuong dau tien: %d",tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
