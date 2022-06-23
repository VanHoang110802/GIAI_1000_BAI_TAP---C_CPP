Tính tổng các giá trị lớn hơn giá trị đứng liền trước nó trong mảng một chiều các số thực
/*
mảng:  1 2 3 4 5 6 7 8 9
-> tổng : 44
mảng: 1 3 2 4 3 2 1 6 9
-> tổng: 22
ý tưởng: xét tiến lên, nếu só đó so sánh với số đằng trước mà nó lớn hơn thì đi tính tổng, nếu nó nhỏ hơn thì bỏ qua, xét sang số khác
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
			printf("So luong phan tu nhap khong hop le!\n");
		}
	} while (n<1||n>Max);
}
void NhapMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("a[%d]= ", i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d  ", a[i]);
	}
}
int TongCacPhanTuLonHonPhanTuDungLienTruocNo(int a[], int n){
	int s = 0;
	for (int i = 1; i < n; i++){
		if (a[i] > a[i - 1]){
			s += a[i];
		}
	}
	return s;
}
int main()
{
	int n, a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	int tong = TongCacPhanTuLonHonPhanTuDungLienTruocNo(a, n);
	printf("\nTong = %d", tong);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
