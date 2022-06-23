Hãy liệt kê các vị trí chẵn lớn nhất trong mảng một chiều các số nguyên

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
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
int TimSoChanDauTien(int a[], int n) {
	for (int i = 0; i<n; i++) {
		if (a[i] % 2 == 0) return a[i];
	}
	 return -1;
}
float TimGiaTriChanMax(int a[], int n) {
	float ChanMax = TimSoChanDauTien(a, n);
	for (int i = 0; i < n; i++) {
		if (a[i] > ChanMax && a[i] % 2 == 0) {
			ChanMax = a[i];
		}
	}
	return ChanMax;
}
void LietKe(int a[], int n) {
	printf("\nCac vi tri thoa man de bai: ");
	int max = TimGiaTriChanMax(a, n);
	for (int i = 1; i < n; i++) {
		if (a[i] == max) {
			printf("%d ", i);
		}
	}
	
}
int main() {
	int a[Max], n;
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\n");
	LietKe(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
