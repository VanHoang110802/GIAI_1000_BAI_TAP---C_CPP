Tính S(x, n) = −𝑥 + 𝑥^2/2! − 𝑥^3/3! + … + (−1)^𝑛*𝑥𝑛/𝑛!.

#include<stdio.h>
#include <conio.h>
#include<math.h>
int main(){
hoang:
	int n,x;
	do{
		printf("Nhap x= ");
		scanf("%d", &x);
		if(x<=0){
			printf("X nhap khong hop le, xin hay kiem tra lai!\n");
		}
	}while(x<=0);
	do{
		printf("Nhap n= ");
		scanf("%d", &n);
		if(n<=0){
			printf("N nhap khong hop le, xin hay kiem tra lai!\n");
		}
	}while(n<=0);
	float s = 1, s1 = 0;
	for(int i=1;i<=n;i++)
	{
		s*=i;
		s1+=pow(-1.0,i)*(pow(x,i)/s);
	}
	printf("%f", s1);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
