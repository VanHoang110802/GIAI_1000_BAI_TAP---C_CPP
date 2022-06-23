Tính S(n) = 1^3 + 2^3 + 3^3 + … + n^3.
/*
n = 5 -> s = s + n = 1 + 2^3 + 3^3 + 4^3 + 5^3 = 225.
*/
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main(){
hoang:
	int n;
	do{
		printf("Nhap n= ");
		scanf("%d",&n);
		if(n<=0){
			printf("n > 0, xin hay kiem tra lai!\n");
		}
	}while(n<=0);
	float s = 0;
	for(int i =1; i<=n;i++){
		s += pow(i, 3);
	}
	printf("S(n) = %.2f", s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
