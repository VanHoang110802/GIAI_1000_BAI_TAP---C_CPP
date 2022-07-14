Tính S(n) = √𝑛 + √𝑛 − 1 + √𝑛 − 2 + ⋯ √2 + √1 có n dấu căn.

#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
hoang:
    	int n;
    	do
    	{
        	printf("Nhap n= ");
        	scanf("%d", &n);
        	if(n <= 0){
            		printf("n phai > 0. Xin nhap lai !\n");
       	 	}
    	}while(n <= 0);
	//for(int i = 1; i<= n ;i++){
	//}
    	float S = 0;
	int i = 1;
    	while(i <= n){
       		S = sqrt(i + S);
        	i++;
    	}
    	printf("\nTong = %.3f", S);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    	return 0;
}
