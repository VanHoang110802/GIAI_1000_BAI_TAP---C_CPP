Hãy liệt kê các số âm trong mảng một chiều các số thực .

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
	printf("\nCac gia tri thoa man de bai: ");
	for(int i=0;i<n;i++){
		if(a[i] < 0){
			printf("%.2f  ", a[i]);
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
