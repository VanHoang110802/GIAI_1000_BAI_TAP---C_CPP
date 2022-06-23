Hãy tìm "giá trị chẵn nhỏ nhất" trong mảng một chiều các số nguyên.Nếu mảng không có giá trị chẵn thì trả về giá trị không chẵn là -1.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>
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
		printf("%d  ", a[i]);
	}
}
int TimGiaTriChanMin(int a[], int n) {
	int min;
	int dem = 0, i;
	for ( i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			dem++;
			break;
		}
	}
	if (dem == 0) {
		return -1;
	}
	else {
		min = a[i];
		for (int i = 0; i < n; i++) {
			if (a[i] % 2 == 0 && a[i] < min) {
				min = a[i];
			}
		}
	}
	return min;
}

int main() {
	int a[Max], n;
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\n");
	int tim = TimGiaTriChanMin(a, n);
	printf("So chan nho nhat: %d", tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
