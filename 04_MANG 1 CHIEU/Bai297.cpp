Cho mảng một chiều các số nguyên.Hãy viết hàm tìm giá trị đầu tiên trong mảng có dạng 2^k.Nếu mảng không tồn tại giá trị có dạng 2^k thì hàm sẽ trả về giá trị 0.

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
int KiemTraDang2MuK(int n) {
	double kq = log10((double)n) / log10(2);
	if (kq == (int)kq)
	{
		return 1;
	}
	else return 0;
}
int TimSoDauCoDang2MuK(int a[], int n) {
	int dem = 0, i;
	for (i = 0; i < n; i++) {
		if (KiemTraDang2MuK(a[i])) {
			dem++;
			break;
		}
	}
	if (dem == 0) {
		return 0;
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			if (KiemTraDang2MuK(a[i]))
			{
				return a[i];
			}
		}
	}
	return 0;
}
int main() {
	int a[Max], n;
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	int tim = TimSoDauCoDang2MuK(a,n);
	printf("\nGia tri dau tien co dang 2^k: %d",tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
