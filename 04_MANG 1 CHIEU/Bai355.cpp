Người ta định nghĩa một mảng được gọi là "dạng sóng" khi phần tử có chỉ số i lớn hơn hoặc nhỏ hơn hai phần tử xung quanh nó.Hãy viết hàm kiểm tra mảng có dạng sóng hay không ?
/*
mảng: 1  3  2  4  5
-> return 0
mảng: 77 12 45 6 99
-> return 1
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
int KiemTraHoanThien(int n){
	int s = 0, temp = n;
	for (int i = 1; i < temp; i++){
		if (temp % i == 0){
			s += i;
		}
	}
	if (s == n){
		return 1;
	}
	else return 0;
}
int KiemTraDangSong(int a[], int n){
	int check = 1;
	for (int i = 1; i < n - 1; i++){
		if ((a[i] < a[i - 1] && a[i] > a[i + 1]) || (a[i] > a[i - 1] && a[i] < a[i + 1])){
			check = 0;
			break;
		}
	}
	return check;
}
int main(){
	int n,a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\nKiem tra mang co la dang song hay khong?\n1-CO\n0-KHONG CO\n");
	int kt = KiemTraDangSong(a, n);
	printf("\n%d", kt);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
