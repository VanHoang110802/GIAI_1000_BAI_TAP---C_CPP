Cho mảng một chiều các số thực.Hãy viết hàm liệt kê tất cả các giá trị trong mảng có ít nhất một lân cận trái dấu với nó .

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(int& n) {
	do {
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if (n<1||n>Max) {
			printf("Phan tu nhap khong hop le, xin hay kiem tra lai!\n");
		}
	} while (n<1||n>Max);
}
void NhapMang(float a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("a[%d]= ", i);
		scanf("%f", &a[i]);
	}
}
void XuatMang(float a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%.3f  ", a[i]);
	}
}

void LietKe(float a[], int n){
	printf("\nCac gia tri trong mang co it nhat 1 phan tu lan can trai dau voi no la: ");
	for (int i = 1; i < n - 1; i++){
		int b = a[i] * a[i - 1];
		int c = a[i] * a[i + 1];
		if (b < 0 || c < 0)
			printf("%.3f  ", a[i]);
		else printf("\n0"); break;
	}
}
int main() {
	int n;
	float a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\n");
	LietKe(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
