#include<stdio.h>
#include<conio.h>

int main(){
hoang:
    	int n;
	do{
    		printf("\nNhap n: ");
    		scanf("%d", &n);
		if(n<=0){
			printf("n > 0, xin hay kiem tra lai!\n");
		}
	}while(n<= 0);
	float s=(1+1.0/(1+1));
	for(int i=2;i<=n;i++)
	{
		s=(i/i+((i/i)/s));
	}
	printf("\nKet qua la: %.3f",s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    	return 0;
}
