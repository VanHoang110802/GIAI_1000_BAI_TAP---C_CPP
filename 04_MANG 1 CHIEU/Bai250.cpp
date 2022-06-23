Các thao tác tìm kiếm
a. Vị trí cuối cùng của phần tử x trong mảng

#include <stdio.h>
#include <conio.h>
#define Max 50
// nhap so luong phan tu: 
void NhapDuLieu(int &n){
	do{
		printf("Nhap so luong: ");
		scanf("%d",&n);
		if(n< 1 || n > Max){
			printf("Nhap so luong khong hop le! Xin kiem tra lai !\n");
		}
	}while(n< 1 || n > Max);
}
// nhap mang
void NhapMang(int a[], int n){
	for(int i=0;i<n;i++){
		printf("[%d]= ", i);
		scanf("%d",&a[i]);	
	}
}
// xuat mang
void XuatMang(int a[], int n){
	printf("\nMang la: \n");
	for(int i=0;i<n;i++){
		printf("%d ", a[i]);
	}
}
int TimViTriCuoiCung(int a[], int n, int x){
	for(int i = n - 1;i>= 0;i--){
		if(a[i] == x){
			return i;
		}
	}
	return 0;	
}
int main(){
	int n,x;
	int a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);
	printf("\nNhap so can tim: ");
	scanf("%d", &x);
	int vt = TimViTriCuoiCung(a,n,x);
	printf("Vi tri tim duoc(tu ben trai qua): %d", vt);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
b. Vị trí số nguyên tố đầu tiên trong mảng nếu có

#include <stdio.h>
#include <conio.h>
#define Max 50
// nhap so luong phan tu: 
void NhapDuLieu(int &n){
	do{
		printf("Nhap so luong: ");
		scanf("%d",&n);
		if(n< 1 || n > Max){
			printf("Nhap so luong khong hop le! Xin kiem tra lai !\n");
		}
	}while(n< 1 || n > Max);
}
// nhap mang
void NhapMang(int a[], int n){
	for(int i=0;i<n;i++){
		printf("[%d]= ", i);
		scanf("%d",&a[i]);	
	}
}
// xuat mang
void XuatMang(int a[], int n){
	printf("\nMang la: \n");
	for(int i=0;i<n;i++){
		printf("%d ", a[i]);
	}
}
int KiemTraSoNT(int n){
	if(n < 2){
		return 0;
	}
	else {
		if(n!= 2 && n % 2 == 0){
			return 0;
		}
		for(int i =3;i<= (int)sqrt((double)n);i+=2){
			if(n%i == 0){
				return 0;
			}
		}
	}
	return 1;
}
int TimViTriNTDauTien(int a[], int n){
	for(int i = 0;i < n ;i++){
		if(KiemTraSoNT(a[i])){
			return i;
		}
	}
	return 0;	
}
int main(){
	int n,x;
	int a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);
	int vt = TimViTriNTDauTien(a,n);
	printf("So nguyen to dau tien tim duoc: %d", vt);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}

c. Tìm số nhỏ nhất trong mảng

#include <stdio.h>
#include <conio.h>
#define Max 50
// nhap so luong phan tu: 
void NhapDuLieu(int &n){
	do{
		printf("Nhap so luong: ");
		scanf("%d",&n);
		if(n< 1 || n > Max){
			printf("Nhap so luong khong hop le! Xin kiem tra lai !\n");
		}
	}while(n< 1 || n > Max);
}
// nhap mang
void NhapMang(int a[], int n){
	for(int i=0;i<n;i++){
		printf("[%d]= ", i);
		scanf("%d",&a[i]);	
	}
}
// xuat mang
void XuatMang(int a[], int n){
	printf("\nMang la: \n");
	for(int i=0;i<n;i++){
		printf("%d ", a[i]);
	}
}
int TimMin(int a[], int n){
	int min = a[0];
	for(int i = 1;i < n ;i++){
		if(a[i] < min ){
			min = a[i];
		}
	}
	return min;	
}
int main(){
	int n,x;
	int a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);
	int min = TimMin(a,n);
	printf("Min =  %d", min);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}

d. Tìm số dương nhỏ nhất trong mảng

#include <stdio.h>
#include <conio.h>
#define Max 50
// nhap so luong phan tu: 
void NhapDuLieu(int &n){
	do{
		printf("Nhap so luong: ");
		scanf("%d",&n);
		if(n< 1 || n > Max){
			printf("Nhap so luong khong hop le! Xin kiem tra lai !\n");
		}
	}while(n< 1 || n > Max);
}
// nhap mang
void NhapMang(int a[], int n){
	for(int i=0;i<n;i++){
		printf("[%d]= ", i);
		scanf("%d",&a[i]);	
	}
}
// xuat mang
void XuatMang(int a[], int n){
	printf("\nMang la: \n");
	for(int i=0;i<n;i++){
		printf("%d ", a[i]);
	}
}
int TimMinDuong(int a[], int n){
	int vitriduongdautien = -1;
	for(int i = 1;i < n ;i++){
		if(a[i] >= 0 ){
			vitriduongdautien = i;
			break;
		}
	}
	if(vitriduongdautien = -1){
		return vitriduongdautien;
	}
	int min = a[vitriduongdautien];
	for(int i = vitriduongdautien + 1; i< n ;i++){
		if(a[i] >= 0 && a[i] < min){
			min = a[i];
		}
	}
	return min;	
}
int main(){
	int n,x;
	int a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);
	int min = TimMin(a,n);
	printf("Min =  %d", min);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
