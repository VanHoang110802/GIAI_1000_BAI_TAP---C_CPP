Tính S(n)  = 1^2 + 2^2 + 3^2 + … + n^2.
/*
n = 3
s = 0;
i = 1;
s = s + i * i = 0 + 1 * 1 = 1
	      =	1 + 2 * 2 = 5
	      =	5 + 3 * 3 = 14
	      =	14 + 4 * 4 = 30
	      = 30 + 5 * 5 = 55
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
	}while(n<=0);
	int s = 0;
	for(int i = 1;i <= n; i++){
		s += i*i;
	}
	printf("Tong = %d", s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
