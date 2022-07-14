Tính S(n) = 1 + 𝑥 + 𝑥^3/3! + 𝑥^5/5! + … + 𝑥^2𝑛+1/(2𝑛+1)!.
/*
x = 4
n = 2
s = 1

s = s + x + pow(x, 2*n+1) / (2*n+1) = 1 + 4 + pow(4, 2*1+1) /(2*1+1)! = 1 + 21.333 = 15.666
				= 15.666 + 4 + pow(4, 2*2+1) /(2*2+1)! = 19.666 + 8.533 = 28.199

*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
hoang:
    	int  n,x;
   	float S, T;
    	int M, N;
   	do{
		printf("Nhap x= ");
		scanf("%d", &x);
		if(x<=0){
			printf("x > 0, xin hay kiem tra lai!\n");
		}
	} while(x<=0);
    	do{
		printf("Nhap mu n= ");
		scanf("%d", &n);
		if(n<=0){
			printf("n > 0, xin hay kiem tra lai!\n");
		}
	} while(n<=0);

	int i = 1;
    	S = 1;
   	N = 1;

   	while(i <= n)
   	{
		T = pow(x, (2 * i + 1));
        	M = 2 * i + 1;
       	 	N = N * M * (M - 1);
  		S = S + x + T/N;
       		i++;
    	}
    	printf("\nTong la %.3f", S);
    	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    	return 0;
}
