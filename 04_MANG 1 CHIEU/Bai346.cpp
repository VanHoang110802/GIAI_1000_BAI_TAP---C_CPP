Hãy kiểm tra mảng số nguyên có tồn tại số nguyên tố hay không ? Nếu có trả về 1,nếu không trả về 0 .

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(int& n) {
	do {
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if (n<1||n>Max {
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
		printf("%d  ", a[i]);
	}
}
int KiemTraSoNT(int n) {
	int temp = n, check = 1;
	if (temp < 2) {
		check = 0;
	}
	else {
		if (temp > 2 && temp % 2 == 0) {
			check = 0;
		}
		else {
			for (int i = 2; i * i <= temp; i++) {
				if (n % i == 0) {
					check = 0;
					break;
				}
			}
		}
	}
	if (check == 1 && n >= 2) {
		return 1;
	}
	else return 0;
}
int KiemTraMangCoSoNT(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (KiemTraSoNT(a[i])) {
			return 0;
		}
	}
	return 1;
}
int main(){
	int n,a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\nKiem tra mang co gia tri nguyen to hay khong?\n1-CO\n0-KHONG CO\n");
	int kt = KiemTraMangCoSoNT(a, n);
	printf("\n%d", kt);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
