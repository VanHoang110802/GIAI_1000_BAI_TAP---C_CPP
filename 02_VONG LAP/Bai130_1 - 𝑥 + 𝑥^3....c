TÃ­nh S(n) = 1 - ð¥ + ð¥^3/3! â ð¥^5/5! + â¦ + (â1)^ð+1*ð¥^2ð+1/(2ð+1)!.

#include<stdio.h>
#include <conio.h>
#include<math.h>
int main(){
hoang:
	int n,x;
		printf("Nhap x= ");
		scanf("%d", &x);
	do{
		printf("Nhap n= ");
		scanf("%d", &n);
		if(n<=0){
			printf("N nhap khong hop le, xin hay kiem tra lai!\n");
		}
	}while(n<=0);
	
	float s = 1,s1, s2 = 0;
	for(int i=1;i<=n;i++)
	{
		int temp = 2 * i + 1;		
		s *= temp * (temp - 1);		
		s1 = pow(x,2 * i + 1);		
		s2+= pow(-1,i + 1)*s1 /s;	
	}
	//printf("%f", s);
	//printf("\n%f", s1);
	printf("\n%f", s2 - x);		
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
