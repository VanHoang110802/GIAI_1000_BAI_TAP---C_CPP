Tính S(n) = 1 + 1/3+ 1/5+ … + 1/2𝑛+1.

/*
n = 5
s = 0
i = 0	

s = s+1.0/(2*i+1) = 0 + 1/(2 * 0 + 1) = 1 
		  = 1 + 1/(2 * 1 + 1) = 1 +1/3 = 1.333
		  = 1.333 + 1/(2 * 2 + 1) = 1.333 + 1/5 = 1.533
		  = 1.533 + 1/(2 * 3 + 1) = 1.533 + 1/7 = 1.676
		  = 1.676 + 1/(2 * 4 + 1) = 1.676 + 1/9 = 1.787
*/

#include <stdio.h>
#include <conio.h>
int main(){
hoang:
	int n;
	do{
		printf("Nhap n= ");
		scanf("%d",&n);
		if(n<=0){
			printf("n>0, xin hay kiem tra lai!\n");	
		}	

	}while(n<=0);
	float s = 0;
	for(int i = 0;i < n; i++){
		s+= 1.0/(2 *i +1);
	}	
	printf("%.3f", s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;	
}
