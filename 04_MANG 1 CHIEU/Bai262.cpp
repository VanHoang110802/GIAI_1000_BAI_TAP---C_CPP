Viết hàm liệt kê các giá trị chẵn trong mảng một chiều các số nguyên.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(int &n){
	do{
    printf("nhap so luong:");
    scanf("%d",&n);
		if(n<1||n>Max){
			printf("So luong phan tu nhap khong hop le, xin hay kiem tra lai!\n");
		}
	}while(n<1||n>Max);
}
void NhapMang(int a[],int n){
    for(int i=0;i<n;++i){
        printf("a[%d]= ",i);
        scanf("%d",&a[i]);
    }
}
void XuatMang(int a[],int n){
    for(int i=0;i<n;++i){
        printf("%d ",a[i]);
    }
}
void LietKeSoChan(int a[],int n){
    for(int i=0;i<n;++i){
        if(a[i] % 2 == 0){
            printf("%d ", a[i]);
        }
    }
}
int main(){
    int n, a[Max];
hoang:
    NhapDuLieu(n);
    NhapMang(a,n);
    XuatMang(a,n);
    printf("\nMang toan so chan la:");
    LietKeSoChan(a,n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    return 0;
}
