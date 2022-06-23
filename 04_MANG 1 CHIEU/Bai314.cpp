Hãy liệt kê các vị trí mà giá trị tại vị trí đó là giá trị lớn nhất trong mảng một chiều các số thực .
/*
mảng  : 1 3 5 7 9 8 9 5 3 9
vị trí: 0 1 2 3 4 5 6 7 8 9
vị trí mà có giá trị là max: 4,6,9
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
void NhapMang(float a[], int n){
	for(int i=0;i<n;i++){
		printf("a[%d]= ",i);
		scanf("%f", &a[i]);
	}
}
void XuatMang(float a[], int n){
	for(int i=0;i<n;i++){
		printf("%.2f  ", a[i]);
	}
}
void LietKe(float a[], int n){
	printf("\nCac vi tri la gia tri lon nhat: ");
	float max = a[0];
	for(int i =0;i<n;i++){
		if(a[i] > max){
			max = a[i];
		}
	}
	for(int i =0;i<n;i++){
		if(a[i] == max){
			printf("%d ", i);
		}
	}
}
int main(){
	float a[Max];
	int n;
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
