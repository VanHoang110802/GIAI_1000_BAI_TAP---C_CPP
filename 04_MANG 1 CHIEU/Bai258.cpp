Viết hàm tìm một vị trí mà giá trị tại vị trí đó là một giá trị nhỏ nhất trong mảng một chiều các số nguyên.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
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
int TimViTriMin(int a[], int n){
	int min = 0;
	for (int i = 0; i < n; i++){
		if (a[i] < a[min]){
			min = i;
		}
	}
	return min;
}
int main() {
	int n,a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	int tim = TimViTriMin(a, n);
	printf("\nVi tri co gia tri min la: %d", tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
