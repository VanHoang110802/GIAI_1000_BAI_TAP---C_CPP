Lập chương trình in ra hình chữ nhật có kích thước m x n.
1. Hình chữ nhật đặc
Ví dụ: Hình chữ nhật có kích thước 7 x 4

	* * * * * * *
	* * * * * * *
	* * * * * * *
	* * * * * * *

#include<stdio.h>
#include<conio.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
void VeHcnDac(int n, int m){
	printf("\n");
   	printf("\n");
   	for(int i = 1; i <= n; ++i){
    		printf("\t");
        	for(int j = 1; j <= m; ++j){
            		printf("*");
        	}
        	printf("\n");
    	}
}
int main(){
hoang:
    int n,m;
	do{
	NhapDuLieu(n);
	if(n< 4){
		printf("n > 3. Xin hay nhap lai!\n");
	}
	}while(n< 4);
	do{
	NhapDuLieu(m);
	if(m <= n){
		printf("m > n. Xin hay nhap lai!\n");
	}
	}while(m <= n);
	VeHcnDac(m,n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
    return 0;
}
---------------------------------------------------------------------------------------------------
b) Hình chữ nhật rỗng
Ví dụ: Hình chữ nhật có kích thước 7 x 4

	* * * * * * *
	*           *
	*           *
	* * * * * * *
#include<stdio.h>
#include<conio.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
void VeHcnRong(int n, int m){
	printf("\n");
   	for(int i = 1; i <= n; ++i){
    		printf("\t");
        	for(int j = 1; j <= m; ++j){
        		if((i == n || i == 1|| j == 1 || j == m)){
        			printf("*");
			} else printf(" ");
        	}
        	printf("\n");
    	}
}
int main()
{
hoang:
    	int n,m;
	do{
	NhapDuLieu(n);
	if(n< 4){
		printf("n > 3. Xin hay nhap lai!\n");
	}
	}while(n< 4);
	do{
	NhapDuLieu(m);
	if(m<= n){
		printf("m > n. Xin hay nhap lai!\n");
	}
	}while(m<= n);
	VeHcnRong(m,n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
    return 0;
}
