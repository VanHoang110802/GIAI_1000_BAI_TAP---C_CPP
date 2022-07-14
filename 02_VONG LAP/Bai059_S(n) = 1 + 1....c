Tính S(n) = 1 + 1/2 + 1/3 + … + 1/𝑛
/*
n = 5
s = 0
i = 1

s = s + (1/i) = 0 + 1/1 =1
	      =	1 + 1/2 = 1.5
	      =	1.5 + 1/3 = 1.833
	      =	1.833 + 1/4 = 2.083
	      =	2.083 + 1/5 = 2.283
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
			printf("n>0, xin hay kiem tra lai!\n");
		}
	}while(n<=0);
	float s = 0;
	for(int i = 1; i<=n;i++){
		s += 1.0/i;
	}
	printf("Tong = %.3f", s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
