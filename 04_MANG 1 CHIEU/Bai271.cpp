Viết hàm tìm "giá trị lớn nhất" trong mảng một chiều các số thực.

#include<stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(float &n){
	do{
		printf("Nhap so luong phan tu: ");
		scanf("%f", &n);
		if(n<1||n>Max){
			printf("Xin hay kiem tra lai!\n");
		}
	}while(n<1||n>Max);
}
void NhapMang(float a[], float n){
	for(int i=0;i<n;i++){
		printf("a[%d]= ", i);
		scanf("%f", &a[i]);
	}
}
void XuatMang(float a[], float n){
	for(int i =0;i<n;i++){
		printf("%.2f ", a[i]);
	}
}
// tim gia tri max trong mang so thuc.
float TimGiaTriMax(float a[], float n){
	int max = a[0];
	for(int i =0;i<n;i++){
		if(a[i] > max){
			max = a[i];
		}
	}
	return max;
}
int main(){
	float a[Max],n;
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);	float max = TimGiaTriMax(a,n);
	printf("\n-> MAX = %.2f", max);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
