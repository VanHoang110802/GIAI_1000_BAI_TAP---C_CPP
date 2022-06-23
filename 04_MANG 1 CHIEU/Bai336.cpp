Tính tổng các giá trị có chữ số đầu tiên là chữ số chẵn trong mảng các số nguyên .

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
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
int KiemTraChuSoDauChan(int n){
	while (n >= 10){
		n /= 10;
	}
	if (n % 2 == 0){
		return 1;
	}
	return 0;
}

int TinhTongCacSoChuSoDauChan(int a[], int n){
	int s = 0;
	for (int i = 0; i < n; i++){
		if (KiemTraChuSoDauChan(a[i])){
			s += a[i];
		}
	}
	return s;
}
int main(){
	int n, a[max];
hoang:
	nhapdulieu(n);
	nhapmang(a, n);
	xuatmang(a, n);
	int tong = TinhTongCacSoChuSoDauChan(a, n);
	printf("\nTong = %d", tong);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
