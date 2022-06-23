Hãy thêm một phần tử có giá trị x vào mảng tại vị trí k .

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
void Them1PhanTu(int a[], int& n, int ViTriThem, int PhanTuThem)
{
	for (int i = n; i > ViTriThem; i--)
	{
		a[i] = a[i - 1];
	}
	a[ViTriThem] = PhanTuThem;
	n++;
}
int main(){
	int n, a[Max],k, vitri;
hoang:
	printf("\n");
	NhapDuLieu(n);
	NhapMang(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\nNhap vi tri can them: ");
	scanf("%d", &vitri);
	printf("Nhap k= ");
	scanf("%d", &k);
	Them1PhanTu(a,n,vitri,k);
	XuatMang(a, n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
