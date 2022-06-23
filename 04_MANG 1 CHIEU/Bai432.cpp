Tìm dãy con toàn dương dài nhất trong mảng các số thực .

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
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
void NhapMang(float a[], int n) {
	for (int i = 0; i < n; ++i) {
		printf("a[%d]= ", i);
		scanf("%f", &a[i]);
	}
}
void XuatMang(float a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%.3f  ", a[i]);
	}
}
void DayConToanDuongDaiNhat(float a[], int n){
	int i, l, k, test, vt, pt = 0;
	for (i = 0; i < n; i++){
		for (l = i; l <= n; l++){
			for (test = 1, k = 0; k < l; k++){
				if (a[k] < 0){
					test = 0; 
					break;
				}
			}
			if (test == 1){
				if (pt < k){
					pt = k;
					vt = i;
				}
			}
		}
	}
	for (vt; vt < pt; vt++) {
		printf("%.3f ", a[vt]);
	}
}

int main(){
	int n;
	float a[Max];
hoang:
	printf("\n");
	NhapDuLieu(n);
	NhapMang(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\n");
	DayConToanDuongDaiNhat(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
