Liệt kê tất cả các mảng con có độ dài lớn hơn 2 trong mảng một chiều các số nguyên .
/*
Như bài 168 nhưng không được liệt kê các mảng có số lượng phần tử mảng < 3.
*/
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
void LietKeTatCaMangConDoDaiLonHon2PhanTu(int a[], int n){
	int ChieuDai;  // độ dài mảng con
	for (int i = 0; i < n; i++){
		for (ChieuDai = 3 + i; ChieuDai <= n; ChieuDai++){// nếu bỏ vòng for này thì sao ?
			for (int j = i; j < ChieuDai; j++){
				printf("%d ", a[j]);
			}
			printf("\n");
		}
	}
}
int main() {
	int n, a[Max];
hoang:
	printf("\n");
	NhapDuLieu(n);
	NhapMang(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\n\n");
	LietKeTatCaMangConDoDaiLonHon2PhanTu(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
