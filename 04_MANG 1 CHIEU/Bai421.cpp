Hãy biến đổi mảng bằng cách thay tất cả các phần tử trong mảng bằng số nguyên gần nó nhất .

/*
n = 6.9
phannguyen = (int)(6.9) = 6
phan le = 6.9 - 6 = 0.9

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
			printf("So luong phan tu nhap khong hop le, xin hay kiem tra lai\n");
		}
	}while(n<1||n>Max);
}
void NhapMang(float a[], int n){
	for(int i=0;i<n;i++){
		printf("a[%d]= ");
		scanf("%f", &a[i]);
	}
}
void XuatMang(float a[], int n){
	for(int i=0;i<n;i++){
		printf("%.3f ", a[i]);
	}
}
void ThaySoGanNhat(float &n){
	int phannguyen = (int)(n);
	float phanle = n - phannguyen;
	// làm tròn
	if(phanle <= 0.5){
		n = (float)phannguyen;
	}
	else{
		n = (float)phannguyen + 1;
	}
}

// Giống như làm tròn
void ThayCacPhanTuTrongMangBangSoNguyenGanNoNhat(float a[], int n){
	for(int i = 0; i < n; i++){
		ThaySoGanNhat(a[i]);
	}
}
int main(){
	int n;
	float a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);
	printf("\n");
	ThayCacPhanTuTrongMangBangSoNguyenGanNoNhat(a,n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
