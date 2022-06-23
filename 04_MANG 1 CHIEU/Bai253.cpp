Hệ thập phân (cơ số 10) là hệ cơ số mà con người chúng ta sử dụng hàng ngày trong cuộc sống. Thế nhưng, chiếc máy tính của chúng ta lại chỉ có thể làm việc với hệ nhị phân (cơ số 2).
Ví dụ: 8_10 = 1000_2
Yêu cầu:
Cho một số nguyên dương trong hệ cơ số 10, hãy viết số đó trong hệ cơ số 2(hệ nhị phân).
input: 	5	-> ouput: 101
	7		  111
	10		  1010

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <conio.h>
#include<math.h>
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
		printf("%d\t", a[i]);
	}
}
int QuyDoiSangNhiPhan(int n) {
	int temp, i = 1, s = 0;
	if (n <= 0) {
		return 0;
	}
	while (n > 0) {
		temp = n % 2;       // biến phụ lưu lại số dư
		n /= 2;
		s += (i * temp);
		i *= 10;
	}
	return s;
}

void LietKe(int a[], int n, int luachon) {
	for (int i = 0; i < n; i++) {
		if (luachon == 1) {
			int qdnp = QuyDoiSangNhiPhan(a[i]);
			printf("%d\t", qdnp);
		}
	}
}
int main() {
	int n, a[Max];
hoangdeptrai:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\nMang sau khi doi sang nhi phan: \n");
	LietKe(a, n, 1);
	printf("\nBan co muon tiep tuc chuong trinh hay khong?Neu co xin hay bam c, neu khong bat phim bat ki de thoat\n");
	char lc = getch();
	if(lc == 'c' || lc =='C'){
		goto hoangdeptrai;
	}
	return 0;
}
