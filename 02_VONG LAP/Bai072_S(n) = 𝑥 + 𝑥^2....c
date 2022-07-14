Tính S(n) = 𝑥 + 𝑥^2/1+2 + 𝑥^3/1+2+3 + … + 𝑥^𝑛/1+2+3+⋯+𝑛

/*
x = 3
n = 4
s1= 0
s2 = 0
s1 = s1 + n = 0 + 1 = 1
	    = 1 + 2 = 3
	    = 3 + 3 = 6
	    = 6 + 4 = 10

s2 = s2 + pow(x, n) /s1 = 0 + pow(3,1) / 1 = 3
			= 3 + pow(3,2) / 3 = 6
			= 6 + pow(3,3) / 6 = 10.5
			= 10.5 + pow(3,4) / 10 = 18.6
 
*/
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main(){
hoang:
	int x,n;
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
	float s = 0, s1 = 0;
	for(int i=1;i<=n;i++)
	{
		 s+=i;
		s1+=pow(x,i)/s;
	}
	printf("Tong = %.3f", s1);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
