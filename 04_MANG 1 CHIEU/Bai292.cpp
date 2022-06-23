Cho mảng một chiều các số nguyên hãy tìm giá trị đầu tiên trong mảng nằm trong khoảng (x,y) cho trước.Nếu mảng không có giá trị thỏa điều kiện trên thì hàm trả về giá trị là x.
/*
-> Ý là ta sẽ có mảng : 3 -10 5 7 12, x= 4, y = 10 -> cần tìm là 5,7
*/
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

int TimNhungGiaTriThoa(int a[], int n, int x, int y) {
	for (int i = 0; i < n; i++) {
		if (a[i] > x && a[i] < y) {
			return a[i];
		}
	}
	return x;
}
int main() {
	int a[Max], n,x,y;
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\n");
	printf("Nhap so x= ");
	scanf("%d", &x);
	printf("Nhap so y= ");
	scanf("%d", &y);
	int tim = TimNhungGiaTriThoa(a, n,x,y);
	printf("\n->Gia tri dau tien thuoc trong (%d, %d) la: %d",x,y, tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
