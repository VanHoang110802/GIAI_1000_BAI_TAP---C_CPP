Tính S(n) = √1 + √2 + √3 + ⋯ √𝑛 − 1 + √𝑛 có n dấu căn.
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
hoang:
    	 int n;
   	 do{
        	printf("Nhap n= ");
        	scanf("%d", &n);
        	if(n < 1){
            		printf("\nn phai >= 1. Xin nhap lai !\n");
        	}
    	}while(n < 1);
    	float s=sqrt(1.0*n);
	for(int i=n-1;i>=1;i--)
	{
		s=sqrt(i+s);
	}
    	printf("Tong = %.3f", s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    	return 0;
}
