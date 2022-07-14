Tính S(n) = √(2 + √(2 + √(2 + ⋯ +√(2 + √(2)))) có n dấu căn.

#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
hoang:
   	int n;
    	do
    	{
       	 	printf("\nNhap n= ");
       		 scanf("%d", &n);
        	if(n <= 0)
        	{
            	printf("n phai > 0. Xin nhap lai !\n");
        	}
    	}while(n <= 0);
	float S;
    	S = sqrt((float)2);
    	for(int i = 2; i <= n; i++) {
    	    S = sqrt(2 + S);
    	}
    	printf("\nTong S = %.3f", S);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
   	return 0;
}
