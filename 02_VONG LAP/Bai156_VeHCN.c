Lập chương trình in ra hình chữ nhật có kích thước m x n.
1. Hình chữ nhật đặc
Ví dụ: Hình chữ nhật có kích thước 7 x 4

	* * * * * * *
	* * * * * * *
	* * * * * * *
	* * * * * * *

#include<stdio.h>
#include<conio.h>
int main()
{
hoang:
    int m,n;
	do{
		printf("\nNhap n = ");
    	scanf("%d", &n);
    	if(n <= 3){
    		printf("n phai > 3, xin hay kiem tra lai!\n");
		}
	}while(n<=3);
	do{
		printf("Nhap m = ");
    	scanf("%d", &m);
    	if(m <= n){
    		printf("m phai > 3, xin hay kiem tra lai!\n");
		}
	}while(m<=n);
	printf("\n");
   for(int i = 1; i <= n; ++i)
    {
    	printf("\t");
        for(int j = 1; j <= m; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
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
int main()
{
hoang:
    int m,n;
	do{
		printf("\nNhap n = ");
    	scanf("%d", &n);
    	if(n <= 3){
    		printf("n phai > 3, xin hay kiem tra lai!\n");
		}
	}while(n<=3);
	do{
		printf("Nhap m = ");
    	scanf("%d", &m);
    	if(m <= n){
    		printf("m phai > 3, xin hay kiem tra lai!\n");
		}
	}while(m<=n);
	printf("\n");
   for(int i = 1; i <= n; ++i)
    {
    	printf("\t");
        for(int j = 1; j <= m; ++j)
        {
        	if((i == n || i == 1|| j == 1 || j == m)){
        		printf("*");
			} else printf(" ");
        }
        printf("\n");
    }
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    return 0;
}
