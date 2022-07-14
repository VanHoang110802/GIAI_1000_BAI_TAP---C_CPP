Tính T(x, n) = 𝑥^𝑛
/*
áp dụng công thức pow(x,n).
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
		if(n<=0){
		
			printf("x > 0, xin hay kiem tra lai!\n");
		}
	}while(x <=0);

	do{
		printf("Nhap n= ");
		scanf("%d", &n);
		if(n<=0){
		
			printf("n > 0, xin hay kiem tra lai!\n");
		}
	}while(n <=0);
	float s = pow(x,n);
	printf("%.3f", s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
