Cho mảng một chiều các số thực a.Hãy tạo mảng b từ mảng a,sao cho mảng b chỉ chứa các giá trị âm.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <conio.h>
#include<math.h>
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
void TaoMangBChiChuaGiaTriAmTuMangA(int a[], int n){
	int b[Max], nb = 0;
	for (int i = 0; i < n; i++){	
		if (a[i] <  0){
			b[nb] = a[i];
			nb++;
		}
	}
	XuatMang(b, nb);
}
int main() {
	int n, a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\n");
	TaoMangBChiChuaGiaTriAmTuMangA(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
