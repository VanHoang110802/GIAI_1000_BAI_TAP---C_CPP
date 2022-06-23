Ta định nghĩa một mảng có tính chất lẻ,khi tổng của hai phần tử liên tiếp trong mảng luôn luôn là số lẻ.Hãy viết hàm kiểm tra mảng a có tính chất lẻ hay không ?
/*
mảng: 1 2 3 4 5 -> return 1 
(1-có , 0-không)
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
int KiemTraTinhChatLe(int a[], int n){
	int check = 1;
	for (int i = 0; i < n; i++){
		if ((a[i] + a[i + 1] % 2) == 0){
			check = 0;
			break;
		}
	}
	return check;
}
int main(){
	int n, a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\nKiem tra mang co tinh chat le hay khong?\n1-CO\n0-KHONG CO\n");
	int kt = KiemTraTinhChatLe(a, n);
	printf("\n%d", kt);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
