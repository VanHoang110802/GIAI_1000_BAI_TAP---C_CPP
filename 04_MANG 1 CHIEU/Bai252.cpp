Các thao tác thêm/xóa/sửa
a. Sửa các số nguyên tố có trong mảng thành số 0

#include<stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(int &n){
	do{
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if(n< 1 || n > Max){
			printf("So luong phan tu khong hop le!\n");
		}
	}while(n< 1 || n > Max);
}
void NhapMang(int a[], int n){
	for(int i =0;i<n;i++){
		printf("a[%d]= ",i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n){
	for(int i=0;i<n;i++){
		printf("%d ", a[i]);
	}
}
int KiemTraSoNT(int n){
	int check = 1, temp = n;
	if(temp < 2){
		check = 0;
	} else {
		if(temp > 2 && temp % 2 == 0){
			check = 0;
		} else {
			for(int i =2;i*i<=temp;i++){
				if(temp % i == 0){
					check = 0;
					break;
				}
			}
		}
	}
	if(check == 1 ) {
		return 1;
	}
	return 0;
}

void SuaNguyenToThanhSo0(int a[], int n){
	for(int i =0;i<n;i++){
		if(KiemTraSoNT(a[i]) == 1){
			a[i] = 0;
		}
	}
}
int main(){
	int n, a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);
	SuaNguyenToThanhSo0(a,n);
	printf("\nMang sau khi sua cac so nguyen to: ");
	XuatMang(a,n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}

b. Chèn số 0 đằng sau các số nguyên tố
trong mảng

#include<stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(int &n){
	do{
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if(n< 1 || n > Max){
			printf("So luong phan tu khong hop le!\n");
		}
	}while(n< 1 || n > Max);
}
void NhapMang(int a[], int n){
	for(int i =0;i<n;i++){
		printf("a[%d]= ",i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n){
	for(int i=0;i<n;i++){
		printf("%d ", a[i]);
	}
}
int KiemTraSoNT(int n){
	int check = 1, temp = n;
	if(temp < 2){
		check = 0;
	} else {
		if(temp > 2 && temp % 2 == 0){
			check = 0;
		} else {
			for(int i =2;i*i<=temp;i++){
				if(temp % i == 0){
					check = 0;
					break;
				}
			}
		}
	}
	if(check == 1 ) {
		return 1;
	}
	return 0;
}

void ThemPhanTu(int a[], int &n, int vitrithem, int phantuthem){
	for(int i = n - 1; i>= vitrithem;i--){
		a[i+1] = a[i];
	}
	a[vitrithem] = phantuthem;
	n++;
}
void ChenVaoSauNT(int a[], int &n, int socanchen){
	for(int i =0;i<n;i++){
		if(KiemTraSoNT(a[i])){
			ThemPhanTu(a,n,i+1,socanchen);
			i++;
		}
	}
}
int main(){
	int n, a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);
	ChenVaoSauNT(a,n,0);
	printf("\nMang sau khi chen vao sau cac so nguyen to: ");
	XuatMang(a,n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}

c. Xóa tất cả số nguyên tố có trong mảng

#include<stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(int &n){
	do{
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if(n< 1 || n > Max){
			printf("So luong phan tu khong hop le!\n");
		}
	}while(n< 1 || n > Max);
}
void NhapMang(int a[], int n){
	for(int i =0;i<n;i++){
		printf("a[%d]= ",i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n){
	for(int i=0;i<n;i++){
		printf("%d ", a[i]);
	}
}
int KiemTraSoNT(int n){
	int check = 1, temp = n;
	if(temp < 2){
		check = 0;
	} else {
		if(temp > 2 && temp % 2 == 0){
			check = 0;
		} else {
			for(int i =2;i*i<=temp;i++){
				if(temp % i == 0){
					check = 0;
					break;
				}
			}
		}
	}
	if(check == 1 ) {
		return 1;
	}
	return 0;
}
void XoaPhanTu(int a[], int &n, int vitrixoa){
	for(int i = vitrixoa + 1;i<n;i++){
		a[i - 1] = a[i];
	}
	n--;
}
void XoaTatCaSoNT(int a[], int &n){
	for(int i =0;i<n;i++){
		if(KiemTraSoNT(a[i])){
			XoaPhanTu(a,n,i);
			i--;
		}
	}
}
int main(){
	int n, a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);
	XoaTatCaSoNT(a,n);
	printf("\nMang sau khi xoa cac so nguyen to: ");
	XuatMang(a,n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
