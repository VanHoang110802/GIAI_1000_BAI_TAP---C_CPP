Cho mảng một chiều các số thực a.Hãy tạo mảng b từ mảng a,với b[i]=tổng các phần tử lân cận với a[i] trong mảng a .

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
void TaoMangBSaoChoBiBangTongCacPhanTuLanCanTrongMangA(int a[], int n){
	int b[Max], nb = 0;
	for (int i = 0; i < n; i++){
		if (i == 0){
			b[nb] = a[i + 1];
		}
		else if (i == n - 1){
			b[nb] = a[i - 1];
		}
		else{
			b[nb] = a[i - 1] + a[i + 1];
		}
		nb++;
	}
	XuatMang(b, nb);
}
int main(){
	int n, a[Max];
hoang:
	printf("\n");
	NhapDuLieu(n);
	NhapMang(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\n");
	TaoMangBSaoChoBiBangTongCacPhanTuLanCanTrongMangA(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
