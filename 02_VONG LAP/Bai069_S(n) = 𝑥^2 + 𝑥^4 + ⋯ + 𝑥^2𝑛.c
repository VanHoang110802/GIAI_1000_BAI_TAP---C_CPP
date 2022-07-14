Tính S(n) = 𝑥^2 + 𝑥^4 + ⋯ + 𝑥^2𝑛
/*
x = 4
n = 4
s = 0

s = s + pow(a, 2 * n) = 0 + pow(4,2*1) = 16
		 = 16 + pow(4,2*2) = 16 + 256 = 272
		 = 272 + pow(4,2*3) = 272 + 4096 = 4368
		 = 4368 + pow(4,2*4) = 4368 + 65536 = 69904
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
	float s = 0;
	for(int i = 1; i<= n; i++){
		s+= pow(x, 2 * i);
	}
	printf("Tong = %.3f", s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
