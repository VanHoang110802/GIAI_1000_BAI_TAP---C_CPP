Hãy sắp xếp các giá trị tại các vị trí lẻ trong mảng tăng dần.Các giá trị khác giữ nguyên giá trị và vị trí .

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
// Hàm Hoán Vị .
void HoanVi(int& x, int& y){
	int temp = x;
	x = y;
	y = temp;
}

void SapXepLeTangDan(int a[], int n){
	for (int i = 0; i < n - 1; i++){
		if (a[i] % 2 != 0){
			for (int j = i + 1; j < n; j++){
				if (a[j] % 2 != 0 && a[i] > a[j]){
					HoanVi(a[i], a[j]);
				}
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
	XuatMang(a, n);
	printf("\n");
	SapXepLeTangDan(a,n);
	XuatMang(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
