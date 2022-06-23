Hãy đếm số lượng các giá trị phân biệt có trong mảng .

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
int DemSoLuongCacGiaTriPhanBiet(int a[], int n){
	int dem = 0, check;
	for (int i = 0; i < n; i++){
		check = 1;
		for (int j = i + 1; j < n; j++){
			if (a[i] == a[j]){
				check = 0;
				break;
			}
		}
		if (check == 1){
			dem++;
		}
	}
	return dem;
}
int main(){
	int n, a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	int dem = DemSoLuongCacGiaTriPhanBiet(a, n);
	printf("\nCo %d so luong thoa man.", dem);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
