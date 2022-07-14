Tính S(n) = 1/2+ 3/4+ 5/6 +…+ 2𝑛+1/2𝑛+2

/*
n = 5
s = 0
i = 0 

s = s+ ((2*i+1)/(2*i+2)) = 0 + ((2*0+1) / (2*0+2)) = 0.5
			 = 0.5 + ((2 * 1 +1)/(2 * 1 +2) = 1.25
			 = 1.25 + ((2*2+1)/(2*2+2)) = 2.083
			 = 2.083 + ((2*3+1) / (2*3+2)) = 2.958
			 = 2.958 + ((2*4+1) / (2*4+2)) = 3.858 
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
	float s =0;
	for(int i =0;i< n;i++){
		s+= (float)(2*i+1)/(2*i+2);
	}
	printf("Tong = %.3f", s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
