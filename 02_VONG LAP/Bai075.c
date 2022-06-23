Tính S(n) = 1 + 𝑥^2/2! + 𝑥^4/4! + … + 𝑥^2𝑛/(2𝑛)!
/*
x = 3
n = 5
s = 1

s = s + pow(x, 2*n)/(2 * n)! = 1 + pow(3, 2*1) / 2*1! = 5.5
			     = 5.5 + pow(3, 2*2)/ 2*2! = 8.875
			     = 8.875 + pow(3,2*3)/2*3! = 9.8875
			     = 9.8875 + pow(3,2*4)/2*4! = 10.050
			     = 10.050 + pow(3,2*5)/2*5! = 10.066
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
		T = pow(x, (2 * i));
        	M = i * 2;
       	 	N = N * M * (M - 1);
        	S = S + T/N;
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
