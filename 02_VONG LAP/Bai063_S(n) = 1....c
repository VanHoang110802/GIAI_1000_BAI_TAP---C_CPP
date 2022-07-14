Tính S(n) = 1/2+ 2/3+ 3/4 +…+ 𝑛/𝑛+1
/*
n = 5
s = 0
i = 1

s = s + i/(i+1) = 0 + 1/1+1 = 0.5
		= 0.5 + 2/2+1 = 1.166
		= 1.166 + 3/3+1 = 1.916
		= 1.916 + 4/4+1 = 2.716
		= 2.716 + 5/5+1 = 3.549
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
	}while(n <= 0);
	float s = 0;
	for(int i = 1; i<=n;i++){
		s += (float)i/(i+1);	

	}
	printf("%.3f", s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
