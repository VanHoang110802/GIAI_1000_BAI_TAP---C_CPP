Hãy liệt kê các số giá trị chẵn trong mảng một chiều các số nguyên thuộc đoạn [x,y] cho trước (x,y là các số nguyên ).

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
			printf("Phan tu nhap khong hop le, xin hay kiem tra lai!\n");
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
void LietKeChanTrongDoanXY(int a[], int n, int x, int y) {
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0 && x <= a[i] && a[i] <= y) {
			printf("\n%d  ", a[i]);
		}
	}
}
int main() {
	int n, a[Max], x, y;
hoang:
	printf("\nNhap x: ");
	scanf("%d", &x);
	printf("\nNhap y: ");
	scanf("%d", &y);
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\nCac so trong mang thuoc [%d, %d] la: ", x, y);
	LietKeChanTrongDoanXY(a, n, x, y);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
