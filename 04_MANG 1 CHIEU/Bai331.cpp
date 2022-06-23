Tính tổng các giá trị lớn hơn trị tuyệt đối của giá trị đứng liền sau nó trong mảng một chiều các số thực
/*
mảng: 1 -3 2 -5 -4 7 9 6 
-> tổng: 15
*/

#define _crt_secure_no_warnings
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define max 100

void nhapdulieu(int& n) {
	do {
		printf("nhap so luong phan tu: ");
		scanf("%d", &n);
		if (n<1||n>Max) {
			printf("so luong phan tu nhap khong hop le!\n");
		}
	} while (n<1||n>Max);
}
void nhapmang(float a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("a[%d]= ", i);
		scanf("%f", &a[i]);
	}
}
void xuatmang(float a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%.3f  ", a[i]);
	}
}
float tongcacphantulonhonphantudunglientruocno(float a[], int n) {
	float s = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > fabs(a[i + 1])) {
			s += a[i];
		}
	}
	return s;
}
int main()
{
	int n;
	float a[max];
hoang:
	nhapdulieu(n);
	nhapmang(a, n);
	xuatmang(a, n);
	float tong = tongcacphantulonhonphantudunglientruocno(a, n);
	printf("\nTong = %.2f", tong);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
