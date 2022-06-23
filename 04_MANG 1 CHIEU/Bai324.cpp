Cho mảng một chiều các số nguyên.Hãy viết hàm liệt kê các giá trị trong mảng có dạng 3^k.
Nếu mảng không tồn tại giá trị có dạng 3^k thì hàm sẽ trả về giá trị 0.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>
#include <math.h>
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
		printf("%d ", a[i]);
	}
}
int KiemTraDang3MuK(int n) {
	double kq = log10((double)n) / log10(3);
	if (kq == (int)kq)
	{
		return 1;
	}
	else return 0;
}
void TimSoDauCoDang3MuK(int a[], int n) {
	printf("\nCac gia tri thoa man de bai: ");
	int dem = 0, i;
	for (i = 0; i < n; i++) {
		if (KiemTraDang3MuK(a[i])) {
			dem++;
			break;
		}
	}
	if (dem == 0) {
		printf("0");
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			if (KiemTraDang3MuK(a[i]))
			{
				printf("%d ",a[i]);
			}
		}
	}

}
int main() {
	int a[Max], n;
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\n");
	TimSoDauCoDang3MuK(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
