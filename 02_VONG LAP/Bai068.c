Tính S(n) = 𝑥 + 𝑥^2 + 𝑥^3 + ⋯ + 𝑥^𝑛 

/*
x = 2
n = 4
s = 0

s = s + pow(a,n) = 0 + pow(2,1) = 2
		 = 2 + pow(2,2) = 2 + 4 = 6
		 = 6 + pow(2,3) = 6 + 8 = 14
		 = 14 + pow(2,4) = 14 + 16 = 30
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
		s+= pow(x,i);
	}
	printf("Tong = %.3f", s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
