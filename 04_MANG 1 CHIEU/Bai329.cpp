Tính tổng các giá trị có chữ số hàng chục là chữ số 5 có trong mảng một chiều các số nguyên.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<math.h>
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

int TimSoHangChucLa5(int n){
	n = abs(n);			// nếu n âm :vv
	n = n / 10;
	int hangchuc = n % 10;
	if (hangchuc == 5){
		return 1;
	}
	return 0;
}

int TinhTongSoHangChucLa5(int a[], int n){
	int Tong = 0;
	for (int i = 0; i < n; i++){
		if (TimSoHangChucLa5(a[i]) == 1){
			Tong += a[i];
		}
	}
	return Tong;
}
int main(){
	int a[Max], n;
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	int tinh = TinhTongSoHangChucLa5(a, n);
	printf("\nTong = %d", tinh);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
