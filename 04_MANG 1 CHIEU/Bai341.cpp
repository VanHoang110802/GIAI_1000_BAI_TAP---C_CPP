Tính khoảng cách trung bình giữa các giá trị trong mảng
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define max 100

void nhapdulieu(int& n) {
	do {
		printf("nhap so luong phan tu: ");
		scanf("%d", &n);
		if (n<1||n>Max) {
			printf("so luong phan tu nhap khong hop le!\n");
		}
	} while (n<1||n>Max);
}
void nhapmang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("a[%d]= ", i);
		scanf("%d", &a[i]);
	}
}
void xuatmang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d  ", a[i]);
	}
}

float TinhKCTBGiuaCacGiaTriTrongMang(int a[], int n){
	float s = 0;
	int dem = 0;
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			s += fabs(a[i] - a[i + 1]);
			dem++;
		}
	}
	return pow(s, 1.0 / dem);
}
int main(){
	int n, a[max];
hoang:
	nhapdulieu(n);
	nhapmang(a, n);
	xuatmang(a, n);
	float tong = TinhKCTBGiuaCacGiaTriTrongMang(a, n);
	printf("\nKhoang cach trung binh cua cac gia tri: %f", tong);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
