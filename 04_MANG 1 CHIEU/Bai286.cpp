Hãy tìm giá trị trong mảng các số thực "xa giá trị x nhất".

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define Max 100
void NhapDuLieu(float &n){
	do{
		printf("Nhap so luong phan tu: ");
		scanf("%f", &n);
		if(n<1||n>Max){
			printf("So luong phan tu nhap khong hop le!\n");
		}
	}while(n<1||n>Max);
}
void NhapMang(float a[], float n){
	for(int i =0;i<n;i++){
		printf("a[%d]= ",i);
		scanf("%f", &a[i]);
	}
}
void XuatMang(float a[], float n){
	for(int i=0;i<n;i++){
		printf("%.3f  ", a[i]);
	}
}
float TimGiaTriXaNhat(float a[], float n, float x){
	float max = fabs(a[0] - x);
	int vitri = 0;
	for(int i =1;i<n;i++){
		if(fabs(a[i] - x) > max){
			max = fabs(a[i] - x);
			vitri = i;
		}
	}
	return a[vitri];
}
int main(){
	float a[Max], n,x;
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);
	printf("\n");
	printf("\nNhap gia tri x= ");
	scanf("%f", &x);
	float tim = TimGiaTriXaNhat(a,n,x);
	printf("\nGia tri co khoang cach xa voi %.2f nhat la: %.3f",x,tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
