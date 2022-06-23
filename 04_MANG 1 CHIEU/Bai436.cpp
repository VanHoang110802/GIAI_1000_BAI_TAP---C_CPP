//Cho mảng một chiều các số nguyên và một số nguyên M.Hãy tìm một mảng con sao cho tổng các phần tử trong mảng bằng M 

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
void TongMangConBangM(int a[], int n, int M){
	for (int vitrigoc = 0; vitrigoc < n; vitrigoc++)
	{
		for (int chieudaimangcon = vitrigoc + 1; chieudaimangcon < n; chieudaimangcon++)
		{
			int tong = 0;
			for (int vitriptu = vitrigoc; vitriptu < chieudaimangcon; vitriptu++)
			{
				tong += a[vitriptu];
			}
			if (tong == M)
			{
				//Xuất cái mảng vừa tìm được.
				for (int k = vitrigoc; k < chieudaimangcon; k++)
				{
					printf("%d ", a[k]);
				}
				printf("\n\n");
			}
		}
	}
}
int main() {
	int n, a[Max],m;
hoang:
	printf("\n");
	NhapDuLieu(n);
	NhapMang(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\nNhap m = \n(m phai la 1 so co tong bang cac phan tu co mat o trong mang) ");
	scanf("%d", &m);
	TongMangConBangM(a, n,m);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
