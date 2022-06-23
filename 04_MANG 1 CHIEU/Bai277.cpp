Tìm "giá trị âm đầu tiên" trong mảng một chiều các số thực.Nếu mảng không có giá trị âm thì trả về giá trị -1. 

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(float& n) {
	do {
		printf("Nhap so luong phan tu: ");
		scanf("%f", &n);
		if (n<1||n>Max) {
			printf("So luong phan tu nhap khong hop le!\n");
		}
	} while (n<1||n>Max);
}
void NhapMang(float a[], float n) {
	for (int i = 0; i < n; i++) {
		printf("a[%d]= ", i);
		scanf("%f", &a[i]);
	}
}
void XuatMang(float a[], float n) {
	for (int i = 0; i < n; i++) {
		printf("%.2f  ", a[i]);
	}
}
float TimSoAmDau(float a[], float n) {
	for (int i = 0; i < n; i++) {
		if (a[i]< 0) return a[i];
	}
	return -1;
}
int main() {
	float a[Max], n;
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\n");
	float tim = TimSoAmDau(a, n);
	printf("So am dau tien: %.2f", tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
