Phát sinh ngẫu nhiên mảng các số nguyên và sau đó sắp xếp mảng các số nguyên này tăng dần .

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#define Max 20

void PhatSinhNgauNhien(int a[]){
	srand(time(0));
	for (int i = 0; i < Max; i++) a[i] = (rand() % 61) - 10;

	for (int i = 0; i < Max; i++) printf("%d ", a[i]);
}
void XuatMang(int a[]) {
	for (int i = 0; i < Max; i++) {
		printf("%d  ", a[i]);
	}
}
void HoanVi(int& x, int& y){
	int temp = x;
	x = y;
	y = temp;
}

void SapXepTangDan(int a[]){
	for (int i = 0; i < Max - 1; i++){
		for (int j = i + 1; j < Max; j++){
			if (a[i] > a[j]){
				HoanVi(a[i], a[j]);
			}
		}
	}
}
int main() {
	int a[Max];
hoang:
	PhatSinhNgauNhien(a);
	printf("\n");
	SapXepTangDan(a);
	printf("\n\3Mang Phat Sinh Ngau Nhien Duoc Sap Theo Thu Tu Tang Dan:\3\n");
	XuatMang(a);
	printf("\n");
	printf("\nBan co muon tiep tuc nua voi chuong trinh khong? Neu co bam c de tiep tuc, bam phim bat ki de thoat!\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		system("cls");
		goto hoang;
	}
	return 0;
}
