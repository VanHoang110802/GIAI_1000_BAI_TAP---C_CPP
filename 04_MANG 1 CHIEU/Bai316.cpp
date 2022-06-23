Hãy liệt kê các vị trí mà giá trị tại vị trí đó là số chính phương trong mảng một chiều các số nguyên .
/*
mang  : 1 2 3 4 5 6 7 8 9 10
vi tri: 0 1 2 3 4 5 6 7 8 9
-> vi tri chinh phuong: 0 3 8
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define Max 100
void NhapDuLieu(int &n){
	do{
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if(n<1||n>Max){
			printf("So luong phan tu nhap khong hop le!\n");
		}
	}while(n<1||n>Max);
}
void NhapMang(int a[], int n){
	for(int i=0;i<n;i++){
		printf("a[%d]= ",i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n){
	for(int i=0;i<n;i++){
		printf("%d  ", a[i]);
	}
}
int KiemTraSoCP(int n){
	int temp = n;
	double kq = sqrt((double)temp);
	if(kq == (int)kq){
		return 1;
	}
	else return 0;
}
void LietKe(int a[], int n){
	printf("\nCac vi tri ma tai do la so chinh phuong: ");
	for(int i=0;i<n;i++){
		if(KiemTraSoCP(a[i])){
			printf("%d  ", i);
		}
	}
}
int main(){
	int a[Max], n;
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);
	printf("\n");
	LietKe(a,n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
