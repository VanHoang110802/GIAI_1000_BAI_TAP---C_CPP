Các thao tác tính toán
a. Có bao nhiêu số chia hết cho 4 nhưng không chia hết cho 5

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
int DemSoLuong(int a[], int n){
	int dem = 0;
	for(int i =0;i<n;i++){
		if(a[i] % 4 == 0 && a[i] % 5 != 0){
			dem++;
		}
	}
	return dem;
}
int main(){
	int n;
	int a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);
	int dem = DemSoLuong(a,n);
	printf("\nMang co %d so chia het cho 4 va khong chia het cho 5!", dem);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}

b. Tổng các số nguyên tố có trong mảng

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
int TongSoNTTrongMang(int a[], int n){
	int tong = 0;
	for(int i =0;i<n;i++){
		if(KiemTraSoNT(a[i])){
			tong += a[i];
		}
	}
	return tong;					
}
int main(){
	int n;
	int a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);
	int tong = TongSoNTTrongMang(a,n);
	printf("\nTong cac so nguyen to co trong mang: %d", tong);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
