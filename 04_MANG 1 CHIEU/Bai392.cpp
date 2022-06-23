Hãy tạo mảng b từ mảng a các giá trị 0,1 để mảng có tính " tính chẵn lẻ " .

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
void TaoMangB(int a[], int b[], int n){
	int j = 0;
	for (int i = 0; i < n; i++){
		if (a[i] % 2 != 0){
			b[j++] = 1;
		} else{
			b[j++] = 0;
		}
	}
	// Xuất mảng b .
	for (int j = 0; j < n; j++) {		// Số lượng phần tử của mảng b cũng bằng đúng n .
		printf("%d  ", b[j]);
	}
}
int main(){
	int n,m, a[Max],b[Max];
hoang:
	printf("\n");
	NhapDuLieu(n);
	NhapMang(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\n");
	TaoMangB(a,b,n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
