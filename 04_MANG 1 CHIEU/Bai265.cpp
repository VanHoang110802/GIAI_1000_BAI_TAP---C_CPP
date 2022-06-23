Viết hàm liệt kê các vị trí mà giá trị tại đó là giá trị âm trong mảng một chiều các số thực.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(float &n){
	do{
    printf("nhap so luong:");
    scanf("%f",&n);
	if(n<1||n>Max){
		printf("So luong phan tu nhap khong hop le, xin hay kiem tra lai!\n");
	}
	}while(n<1||n>Max);
}
void NhapMang(float a[],float n){
    for(int i=0;i<n;++i){
        printf("a[%d]= ",i);
        scanf("%f",&a[i]);
    }
}
void XuatMang(float a[],float n){
    for(int i=0;i<n;++i){
        printf("%.2f ",a[i]);
    }
}
void LietKeSoAmThuc(float a[],float n){
    for(int i=0;i<n;++i){
        if(a[i] < 0){
            printf("%d ", i+ 1);
        }
    }
}
int main(){
    float n, a[Max];
hoang:
    NhapDuLieu(n);
    NhapMang(a,n);
    XuatMang(a,n);
    printf("\nMang co nhung so am tai nhung vi tri la:");
    LietKeSoAmThuc(a,n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    return 0;
}
