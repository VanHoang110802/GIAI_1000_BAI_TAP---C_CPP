Tính tổng các phần tử "cực trị" trong mảng.Một phần tử được gọi là cực trị khi nó lớn hơn hoặc nhỏ hơn các phần tử xung quanh nó

#define _CRT_SECURE_NO_WARNINGS
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
float TinhTongCacPhanTuCucTri(float a[], int n){
	float Tong = 0;
	for (int i = 0; i < n; i++){
		if (i == 0 && a[i] != a[i + 1]){			// xét số ở đầu
			Tong += a[i];
		}
		else if (i == n - 1 && a[i] != a[i - 1]) {		// xét số đuôi
			Tong += a[i];
		}
		else if ((a[i] < a[i + 1] && a[i] < a[i - 1]) || (a[i] > a[i + 1] && a[i] > a[i - 1])){
			Tong += a[i];
		}
	}
	return Tong;
}
int main(){
	int n;
	float a[max];
hoang:
	nhapdulieu(n);
	nhapmang(a, n);
	xuatmang(a, n);
	float tong = TinhTongCacPhanTuCucTri(a, n);
	printf("\nTong = %.2f", tong);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
