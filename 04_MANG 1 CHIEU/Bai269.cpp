Tìm "vị trí của giá trị chẵn đầu tiên" trong mảng một chiều các số nguyên.Nếu mảng không có giá trị chẵn thì hàm sẽ trả về -1.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
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
int TimViTriChanDauTien(int a[], int n) {
	int vitri = 0;
	for (int i = 0; i <n; i++) {
		if (a[i] % 2 ==0) {
			vitri = i;
			return vitri;
		}
	}
	return -1;
}
int main() {
	int n, a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	int tim = TimViTriChanDauTien(a, n);
	printf("\nGia tri chan dau tien nam o vi tri %d", tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
