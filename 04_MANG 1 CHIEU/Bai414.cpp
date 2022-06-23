Hãy đảo ngược thứ tự các số dương có trong mảng
/*
mảng : 1 -2 3 -4 5 -6 7 -8
->đảo: 7 -2 5 -4 3 -6 1 -8
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
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
void HoanVi(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void DaoMang(int a[], int n) {
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (a[j] > 0 && a[i] > 0){
				HoanVi(a[i], a[j]);
			}
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
	DaoMang(a, n);
	XuatMang(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if (lc == 'c' || lc == 'C') {
		goto hoang;
	}
	return 0;
}
