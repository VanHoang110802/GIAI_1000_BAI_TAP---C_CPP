sắp xếp các số dương tăng dần, các số âm giảm dần trong mảng 1 chiều các số thực
#define _CRT_SECURE_NO_WARNINGS
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
void HoanVi(float &a, float &b){
    int tenp = a;
    a = b;
    b = tenp;
}
void SapXep(float a[], float n){
    for(int i = 0;i<n- 1;i++){
        for(int j = i+1; j<n;j++){
            if(a[i] >= 0 && a[j]>=0){
                if(a[i] > a[j]){
                    HoanVi(a[i],a[j]);
                }
            }
            if(a[i] < 0 && a[j] < 0){
                if(a[i] < a[j]){
                    HoanVi(a[i],a[j]);
                }
            }
        }
    }
}
int main(){
	float a[Max], n;
hoang:
	NhapDuLieu(n);
	NhapMang(a,n);
	XuatMang(a,n);
	SapXep(a,n);
	printf("\n\nSap xep -> ");
	XuatMang(a,n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
