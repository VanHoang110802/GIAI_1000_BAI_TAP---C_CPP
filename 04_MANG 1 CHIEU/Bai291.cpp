Cho mảng một chiều các số thực hãy viết hàm tìm giá trị âm cuối cùng lớn hơn giá trị -1 . Nếu mảng không có giá trị thỏa điều kiện trên thì hàm sẽ trả về giá trị không chẵn là 0 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(float& n) {
	do {
		printf("Nhap so luong phan tu: ");
		scanf("%f", &n);
		if (n<1||n>Max) {
			printf("So luong phan tu nhap khong hop le!\n");
		}
	} while (n<1||n>Max);
}
void NhapMang(float a[], float n) {
	for (int i = 0; i < n; i++) {
		printf("a[%d]= ", i);
		scanf("%f", &a[i]);
	}
}
void XuatMang(float a[], float n) {
	for (int i = 0; i < n; i++) {
		printf("%.3f  ", a[i]);
	}
}

float TimViTriSoAmMax(float a[], float n) {
	float max = -1;
	int dem = 0, i;
	for (i = n - 1; i >= 0; i--)
	{
		if ((a[i] < 0) && (a[i] > max))
		{
			dem++;
			break;
		}
	}
	if (dem == 0)
	{
		return 0;
	}
	else return a[i];
}
int main() {
	float a[Max], n;
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\n");
	float tim = TimViTriSoAmMax(a, n);
	printf("Gia tri am cuoi cung ma no > -1 la: %.2f", tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
