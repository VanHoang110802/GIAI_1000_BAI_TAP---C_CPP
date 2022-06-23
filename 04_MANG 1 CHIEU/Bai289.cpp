Cho mảng một chiều các số thực,hãy tìm giá trị x sao cho đoạn [-x,x] chứa tất cả các giá trị trong mảng.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<math.h>
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
void TimKhoang(float a[], float n) {
	float max = a[0];
	for (int i= 0; i < n; i++) {
		if (fabs(a[i]) > max) {
			max = fabs(a[i]);
		}
	}
	printf("\n-> Cac phan tu co trong mang nam trong [- %.1f, %.1f]",max, max);
}

int main() {
	float a[Max], n;
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\n");
	//float tim = 
	TimKhoang(a, n);
	//printf("\n%.3f", tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
