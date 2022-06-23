Hãy biến đổi mảng bằng cách thay các giá trị lớn nhất bằng các giá trị nhỏ nhất và ngược lại .

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
void NhapMang(int a[], int n){
	for(int i=0;i<n;i++){
		printf("a[%d]= ");
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n){
	for(int i=0;i<n;i++){
		printf("%d ", a[i]);
	}
}
void TimMinMax(int a[], int n, int &max, int &min){
	max = a[0];
	min = a[0];
	for(int i = 1; i < n; i++){
		max = (a[i] > max) ? a[i] : max;
		min = (a[i] < min) ? a[i] : min;
	}
}

void DoiMaxBangMinVaNguocLai(int a[], int n, int max, int min){
	for(int i = 0; i < n; i++){
		if(a[i] == max){
			a[i] = min;
		}
		else if(a[i] == min){
			a[i] = max;
		}
	}
}
int main(){
	int n, a[Max];
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);
	printf("\n");
	DoiMaxBangMinVaNguocLai(a,n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
