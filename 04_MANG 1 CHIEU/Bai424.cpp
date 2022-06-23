Liệt kê các dãy con tăng trong mảng .

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
		printf("%d  ", a[i]);
	}
}
int KiemTraTangDan(int b[], int nb){
	for (int i = 0; i < nb - 1; i++){
		if (b[i] > b[i + 1]){
			return 0;
		}
	}
	return 1;
}

void XuatMangCon(int b[], int nb){
	for (int i = 0; i < nb; i++){
		printf("%d ", b[i]);
	}
	printf("\n");
}

void LietKeDayConTangDan(int a[], int n){
	int ChieuDai;
	int b[Max], nb;
	for (int i = 0; i < n; i++){
		for (ChieuDai = 1; ChieuDai <= n; ChieuDai++){
			nb = 0;
			for (int j = i; j < ChieuDai; j++){
				b[nb] = a[j];
				nb++;
			}
			if (KiemTraTangDan(b, nb) == 1){
				XuatMangCon(b, nb);
			}
		}
	}
}
int main() {
	int n, a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\n");
	LietKeDayConTangDan(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
