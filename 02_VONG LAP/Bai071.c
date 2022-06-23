Tính S(n) = 1 + 1/1+2 + 1/1+2+3 + … + 1/1+2+3+⋯+𝑛
/*
n = 4
s = s + 1 / n  = 0 + 1/1 = 1
 	       = 1 + 1/1+2 = 1.333
	       = 1.333 + 1/1+2+3 = 1.5
	       = 1.5 + 1/1+2+3+4 = 1.6
*/

#include <stdio.h>
#include <conio.h>
int main(){
hoang:
	int n;
	do{
		printf("Nhap n= ");
		scanf("%d", &n);
		if(n<=0){
			printf("n > 0, xin hay kiem tra lai!\n");
		}
	} while(n<=0);
	float s = 0, s1 = 0;
	for(int i=1;i<=n;i++)
	{
		 s+=i;
		s1+=1.0/s;
	}
	printf("Tong = %.3f", s1);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
