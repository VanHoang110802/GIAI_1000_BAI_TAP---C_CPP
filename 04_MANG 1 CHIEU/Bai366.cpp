Hãy đếm số lượng "số hoàn thiện" có trong mảng một chiều các số nguyên .

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
int KiemTraHoanThien(int n){
	int s = 0;
	for (int i = 1; i < n; i++){
		if (n % i == 0){
			s += i;
		}
	}
	if (s == n){
		return 1;
	}
	return 0;
}

int DemSoLuongSoHoanThien(int a[], int n){
	int dem = 0;
	for (int i = 0; i < n; i++){
		if (KiemTraHoanThien(a[i])){
			dem++;
		}
	}
	return dem;
}
int main(){
	int n, a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	int dem = DemSoLuongSoHoanThien(a, n);
	printf("\nCo %d so luong thoa man.", dem);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
