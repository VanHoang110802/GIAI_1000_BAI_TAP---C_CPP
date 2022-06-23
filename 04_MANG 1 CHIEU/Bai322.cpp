Hãy liệt kê các giá trị cực đại trong mảng một chiều các số thực, 1 phàn tử cực đại khi lớn hơn các phần tử lân cận
(số lân cận đầu là số ở giữa đứng trước 1 số và đứng sau nó cũng là 1 số)
/*
mảng: 1 2 6 4 3 5
-> cực max: 6
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
void NhapMang(float a[], int n) {
	for (int i = 0; i < n; ++i) {
		printf("a[%d]= ", i);
		scanf("%f", &a[i]);
	}
}
void XuatMang(float a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%.3f  ", a[i]);
	}
}
void LietKeCacGiaTriCucDai(float a[], int n){
	printf("\nCac gia tri thoa man de bai: ");
	for (int i = 0; i < n - 1; i++){
		if (a[i] > a[i + 1] && a[i - 1] < a[i]){
			printf("%.3f ", a[i]);
		}
	}
}
int main(){
	int n;
	float a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	LietKeCacGiaTriCucDai(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
