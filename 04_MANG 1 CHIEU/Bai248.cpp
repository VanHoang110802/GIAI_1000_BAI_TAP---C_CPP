Các thao tác kiểm tra
a. Mảng có phải là mảng toàn chẵn

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
		printf("%2d", a[i]);
	}
}
int MangToanChan(int a[], int n){
	for(int i =0;i<n;i++){
		if(a[i] % 2 != 0){
			return 0;
		}
	}
	return 1;
}
int main(){
	int n;
	int a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);
	//printf("\nMang toan chan: ");
	int kt = MangToanChan(a,n);
	if(kt == 1){
		printf("\nMang toan so chan!");
	} else printf("\nMang co so le!");
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}

b. Mảng có phải là mảng toàn số nguyên tố

#include <stdio.h>
#include <conio.h>
#include <math.h>
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
int MangToanNT(int a[], int n){
	for(int i =0;i<n;i++){
		if(KiemTraSoNT(a[i]) == 0){
			return 0;
		}
	}
	return 1;
}
int main(){
	int n;
	int a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);
	int kt = MangToanNT(a,n);
	if(kt == 1){
		printf("\nMang toan so nguyen to!");
	} else printf("\nMang khong toan so nguyen to!");
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}

c. Mảng có phải là mảng tăng dần

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
		printf("%2d", a[i]);
	}
}
int MangTangDan(int a[], int n){
	for(int i =1;i<n;i++){
		if(a[i- 1] > a[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	int n;
	int a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);
	int kt = MangTangDan(a,n);
	if(kt == 1){
		printf("\nMang toan so tang dan!");
	} else printf("\nMang khong tang dan!");
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
