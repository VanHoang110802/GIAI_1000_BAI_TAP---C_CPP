Tính S(n) = 1/2 + 1/4 +…+ 1/2𝑛 
/*
n = 4
s = 0
i = 1
s = s + 1.0 / 2 * i = 0 + 1 /2 * 1 = 0 + 1/2 = 0.5
		    = 0.5 + 1/ 2 *2 = 1/2 + 1/4 = 0.75 
		    = 0.75 + 1/ 2*3 = 0.75 + 1/6 = 0.916
		    = 0.916 + 1/2*4 = 0.916 + 1/8 = 1.041
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
	float s = 0;
	for(int i = 1;i <= n;i++){
		s += 1.0/(2*i);
	}
	printf("Tong = %.3f", s");
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
