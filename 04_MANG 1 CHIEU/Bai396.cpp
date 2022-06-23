Nhập vào 1 mảng A các số nguyên và tìm ra phần tử lớn thứ 3 trong mảng .

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
void HoanVi(int& x, int& y){
	int temp = x;
	x = y;
	y = temp;
}

void SapTangDan(int a[], int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (a[i] > a[j]){
				HoanVi(a[i], a[j]);
			}
		}
	}
}

void TimSoLonThuBa(int a[], int n){
	int vt1 = 0, vt2 = 0, max1, max2, max3, dem = 0;
	for (int i = 0; i < n; i++){
		if (a[i] != a[i + 1]){
			dem++;
		}
	}
	if (dem >= 3){
		for (int i = 0; i < n; i++){	// tìm số lớn nhất
			max1 = a[n - 1];
			if (max1 == a[i]){
				vt1 = i;
				break;
			}
		}
		for (int i = 0; i < vt1; i++){	// tìm số lớn nhất nhưng là lớn thứ 2
			max2 = a[vt1 - 1];
			if (max2 == a[i]){
				vt2 = i;
				break;
			}
		}
		max3 = a[vt2 - 1];
		printf("\nPhan tu lon thu 3 trong mang la: %d", max3);
	}
	else printf("\nMang nay khong ton tai it nhat 3 phan tu khac nhau nen khong the tinh duoc!");
}

int main() {
	int n, a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\n");
	TimSoLonThuBa(a, n);
	printf("\nBan co muon tiep tuc nua voi chuong trinh khong? Neu co bam c de tiep tuc, bam phim bat ki de thoat!\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		system("cls");
		goto hoang;
	}
	return 0;
}
