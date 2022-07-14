Tính S(n) = 1/1 𝑥 2 + 1/2 𝑥 3+…+ 1/𝑛 𝑥 (𝑛+1).

/*
Gỉa sử : n = 4
s = 0
i = 1

s = s + 1 / (1* i *(i+1) = s + 1 / (i *(i + 1))
			 = 0 + 1 / (1 *(1 + 1)) = 0.5
			 = 0.5 + 1 /(2 *(2 + 1)) = 0.666
			 = 0.666 + 1 / (3 *(3 + 1)) = 0.749
			 = 0.749 + 1 / (4 *(4 + 1)) = 0.799  
*/

#include <stdio.h>
#include <conio.h>
int main(){
hoang:
	int n;
	do{
		printf("Nhap n= ");
		scanf("%d", &n);
		if(n <= 0){
			printf("n >0, xin hay kiem tra lai !\n");
		}
		
	}while(n<=0);
	float s =0;
	for(int i = 1;i <= n; i++){
		s += 1.0/(i*(i+1));
	}
	printf("Tong = %.3f", s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
