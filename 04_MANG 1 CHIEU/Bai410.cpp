Hãy đưa các số chẵn trong mảng về đầu mảng,số lẻ về cuối mảng và các phần tử 0 nằm ở giữa .

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
void DoiChoDuaChanVeDau(int a[], int ViTriDoi){
	int tam = a[ViTriDoi];           // biến tạm lưu tất cả các giá trị thỏa ĐK đổi
	for (int i = ViTriDoi; i > 0; i--){
		a[i] = a[i - 1];
	}
	a[0] = tam;
}

void Dua0VaoGiua(int a[], int ViTriDoi, int ViTriChanCuoi){
	// Do 0 nằm giữa mảng nên 0 sẽ là giá trị chẵn cuối để thỏa yêu cầu bài toán
	for (int i = ViTriDoi; i > ViTriChanCuoi; i--){
		a[i] = a[i - 1];
	}
	a[ViTriChanCuoi] = 0;
}

void DuaChanVeDauLeVeCuoi(int a[], int n){
	int i, dem;
	int ViTriChanCuoi = 0;
	for (i = 0; i < n; i++){
		if (a[i] % 2 == 0 && a[i] != 0){
			DoiChoDuaChanVeDau(a, i);
		}
	}
	for (i = 0; i < n; i++){
		if (a[i] % 2 != 0){
			ViTriChanCuoi = i;
			break;
		}
	}
	for (i; i < n; i++){	// bỏ khởi tạo i để tránh dư 1 số 0 
		if (a[i] == 0){
			Dua0VaoGiua(a, i, ViTriChanCuoi);
		}
	}
}
int main() {
	int n, a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	DuaChanVeDauLeVeCuoi(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if (lc == 'c' || lc == 'C') {
		goto hoang;
	}
	return 0;
}
