Tính S(x, n) = 1 - 1/1+ 2 + 1/1+2+3 + … + (−1)^𝑛+1*1/1+2+3+⋯+𝑛.

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
	int s = 0, s1 = 0;
	for(int i=1;i<=n;i++)
	{
		s+=i;
		s1+=pow(-1,i+1)*(1.0/s);
	}
	printf("%d", s1);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
