Đếm số lần xuất hiện của giá trị x trong mảng một chiều các số thực .

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(int &n){
    do{
        printf("Nhap so luong phan tu: ");
        scanf("%d",&n);
        if(n<1||n>Max){
            printf("So luong phan tu nhap khong hop le, xin hay kiem tra lai!\n");
        }
    }while(n<1||n>Max);
}
void NhapMang(float a[], int n){
    for(int i=0;i<n;++i){
        printf("a[%d]= ",i);
        scanf("%f",&a[i]);
    }
}
void XuatMang(float a[], int n){
    for(int i=0;i<n;i++){
        printf("%.2f  ", a[i]);
    }
}

float DemSoLanXuatHienX(float a[], int n, int x){
    int dem = 0;
    for(int i=0;i<n;i++){
        if(a[i] == x){
            dem++;
        }
    }
    return dem;
}
int main(){
    float a[Max],x; int n;
hoang:
    NhapDuLieu(n);
    NhapMang(a,n );
    XuatMang(a,n);
    printf("\nNhap vao gia tri x= ");
    scanf("%f", &x);
    float dem = DemSoLanXuatHienX(a,n,x);
    printf("\nCo %.f so luong thoa man", dem);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    return 0;
}
