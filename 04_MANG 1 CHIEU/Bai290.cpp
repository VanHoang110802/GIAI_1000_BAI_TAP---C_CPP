Cho mảng 1 chiều các số thực, tìm giá trị đầu tiên lớn hơn giá trị 2003, nếu mảng không có giá trị thỏa mãn điều kiện tren thì hàm sẽ trả về giá trị là 0.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
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
float TimSo(float a[], float n) {
	int dem = 0, i;
	float max = 2003;
	for ( i= 0; i < n; i++) {
		if (a[i] > max) {
			dem++;
			break;
		}
	}
	if (dem == 0) {
		return 0;
	}
	else {
		return a[i];
	}
}

int main() {
	float a[Max], n;
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\n");
	//float tim = 
	float tim = TimSo(a, n);
	printf("\nGia tri dau > 2003 la: %.3f", tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
