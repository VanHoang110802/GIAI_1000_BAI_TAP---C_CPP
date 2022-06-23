Hãy xóa tất cả các phần tử có giá trị trùng với x .

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

void Xoa1PhanTu(int a[], int& n, int ViTriXoa) {
	for (int i = ViTriXoa; i < n; i++) {
		a[i] = a[i + 1];
	}
	n--;
}
void XoaCacPhanTuTrungVoiX(int a[], int& n, int x){
	for (int i = 0; i < n; i++){
		if ((a[i]) == x){
			Xoa1PhanTu(a, n, i);
			i--;
		}
	}
}
int main() {
	int n, a[Max],x;
hoang:
	printf("\n");
	NhapDuLieu(n);
	NhapMang(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\nNhap x= ");
	scanf("%d", &x);
	XoaCacPhanTuTrungVoiX(a, n,x);
	printf("\n");
	XuatMang(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
