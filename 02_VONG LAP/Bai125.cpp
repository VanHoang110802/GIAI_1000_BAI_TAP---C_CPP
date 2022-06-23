Tính S(x, n) = 𝑥 − 𝑥^3 + 𝑥^5 + ⋯ + (−1)^n*𝑥^2𝑛+1 .

#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
hoang:
	int n,x;
	do{
		printf("Nhap x= ");
		scanf("%d", &x);
		if(x<=0){
			printf("X nhap khong hop le, xin hay kiem tra lai!\n");
		}
	}while(x<=0);
	do{
		printf("Nhap n= ");
		scanf("%d", &n);
		if(n<=0){
			printf("N nhap khong hop le, xin hay kiem tra lai!\n");
		}
	}while(n<=0);
	int s = 0;
	for(int i=0;i<=n;i++){
		s+= pow(-1,i)*pow(x,2*i+1);
	}
	printf("%d", s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
