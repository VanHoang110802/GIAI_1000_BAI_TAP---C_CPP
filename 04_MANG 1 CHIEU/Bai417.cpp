Hãy xuất các phần tử trong mảng theo yêu cầu:Các phần tử chẵn có màu vàng,các phần tử lẻ có màu trắng .

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include <Windows.h>
#define Max 100

void textcolor(int x){
	HANDLE mau;
	mau = GetStdHandle
	(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void NhapDuLieu(int& n){
	do {
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if (n<1||n>Max) {
			printf("So luong phan tu nhap khong hop le, xin hay kiem tra lai!\n");
		}
	} while (n<1||n>Max);
}
void NhapMang(int a[], int n){
	for (int i = 0; i < n; ++i) {
		printf("a[%d]= ", i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n){
	for (int i = 0; i < n; i++) {
		printf("%d  ", a[i]);
	}
}
void XuatChanVangLeTrang(int a[], int n){
	for (int i = 0; i < n; i++){
		if (a[i] % 2 == 0){
			textcolor(14);
			printf("%d ", a[i]);
		}
		else{
			textcolor(7);
			printf("%d ", a[i]);
		}
	}
}
int main(){
	int n, a[Max];
hoang:
	printf("\n");
	NhapDuLieu(n);
	NhapMang(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\n");
	XuatChanVangLeTrang(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
