Hãy liệt kê các vị trí mà giá trị tại đó là số nguyên tố trong mảng một chiều các số nguyên .
/*
mang  : 1 2 3 4 5 6 7 8 9
vi tri: 0 1 2 3 4 5 6 7 8
-> vi tri can tim: 1 2 4 6
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
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
int KiemTraSoNT(int n){
	int temp = n;
	if(temp < 2){
		return 0;
	} else {
		if(temp > 2 && temp % 2 == 0){
			return 0;
		} else {
			for(int i=2;i*i<=temp; i++){
				if(temp % i ==0){
					return 0;
				}
			}
		}
	}
	return 1;
}
void LietKe(int a[], int n){
	printf("\nCac vi tri ma tai do la so nguyen to: ");
	for(int i=0;i<n;i++){
		if(KiemTraSoNT(a[i])){
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
