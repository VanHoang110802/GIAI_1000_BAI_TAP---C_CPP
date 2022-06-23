Nhập vào 1 mảng A các số nguyên và sắp xếp mảng A trên theo quy luật: 
	+ Các số chẵn (nếu có) ở đầu mảng và có thứ tự tăng dần. 
	+ Các số lẻ (nếu có) ở cuối mảng và có thứ tự giảm dần .

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <conio.h>
#include<Windows.h>
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
// Hàm hoán vị.
void HoanVi(int& x, int& y){
	int temp = x;
	x = y;
	y = temp;
}
// Hàm tách ra phần tử chẵn lưu vào mảng C,phần tử lẻ lưu vào mảng D
void TachChanVaLe(int a[], int c[], int d[], int n){
	int j = 0, k = 0;
	for (int i = 0; i < n; i++){
		if (a[i] % 2 == 0){
			c[j++] = a[i];
		}
		else{
			d[k++] = a[i];
		}
	}
}
// Hàm trả về số lượng các phần tử chẵn trong mảng C .
int SoLuongPhanTuMangC(int a[], int n){
	int dem = 0;
	for (int i = 0; i < n; i++){
		if (a[i] % 2 == 0){
			dem++;
		}
	}
	return dem;
}
// Hàm trả về số lượng các phần tử lẻ trong mảng D .
int SoLuongPhanTuMangD(int a[], int n){
	int dem1 = 0;
	for (int i = 0; i < n; i++){
		if (a[i] % 2 != 0){
			dem1++;
		}
	}
	return dem1;
}
// Hàm sắp mảng C chứa các phần tử chẵn tăng dần .
void SapMangCTangDan(int c[], int dem){
	for (int i = 0; i < dem - 1; i++){
		for (int j = i + 1; j < dem; j++){
			if (c[i] > c[j]){
				HoanVi(c[i], c[j]);
			}
		}
	}
}
// Hàm sắp mảng D chứa các phần tử lẻ giảm dần .
void SapMangDGiamDan(int d[], int dem1){
	for (int i = 0; i < dem1 - 1; i++){
		for (int j = i + 1; j < dem1; j++){
			if (d[i] < d[j]){
				HoanVi(d[i], d[j]);
			}
		}
	}
}
// Hàm ghép chung 2 mảng C & D vào chung 1 mảng F theo đúng trình tự thì ghép mảng C vào trước & mảng D vào sau .
void MangF(int f[], int c[], int d[], int dem, int dem1){
	int l = 0;
	for (int j = 0; j < dem; j++){
		f[l++] = c[j];
	}
	for (int k = 0; k < dem1; k++){
		f[l++] = d[k];
	}
}
int main() {
	int n, a[Max], c[Max], d[Max], f[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\n");
	int s = SoLuongPhanTuMangC(a, n);
	int s1 = SoLuongPhanTuMangD(a, n);
	TachChanVaLe(a, c, d, n);
	SapMangCTangDan(c, s);
	printf("\nMang C chua cac phan tu duong cua mang A va sap giam dan :\n");
	XuatMang(c, s);
	printf("\n");
	SapMangDGiamDan(d, s1);
	printf("\nMang D chua cac phan tu am cua mang A va sap tang dan :\n");
	XuatMang(d, s1);
	printf("\n");
	MangF(f, c, d, s, s1);
	printf("\nMang F ghep cac phan tu cua 2 mang C & D :\n");
	XuatMang(f, n);
	printf("\nBan co muon tiep tuc nua voi chuong trinh khong? Neu co bam c de tiep tuc, bam phim bat ki de thoat!\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		system("cls");
		goto hoang;
	}
	return 0;
}
