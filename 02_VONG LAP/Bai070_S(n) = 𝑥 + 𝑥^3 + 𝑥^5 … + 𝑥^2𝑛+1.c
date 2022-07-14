Tính S(n) = 𝑥 + 𝑥^3 + 𝑥^5 … + 𝑥^2𝑛+1
/*
n = 5
x = 3
s = 0

s = s + pow(a,2*n + 1) = 0 + pow(3,2*1+1) = 27
		 = 27 + pow(3,2*2+1) = 27 + 243 = 270
		 = 270 + pow(3,2*3+1) = 270 + 2187 = 2457
		 = 2457 + pow(3,2*4+1) = 2457 + 19683 = 22140
		 = 22140 + pow(3,2*5+1) = 22140 + 177147 = 199287
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
		s+= pow(x, 2 *i + 1);
	}
	printf("Tong = %.3f", s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
