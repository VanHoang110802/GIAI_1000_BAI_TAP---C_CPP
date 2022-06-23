Tính T(n) = 1 𝑥 2 𝑥 3 𝑥 … . 𝑥 𝑛.

#include <stdio.h>
#include <conio.h>
int main(){
hoang:
	int n;
	do{
		printf("Nhap n= ");
		scanf("%d", &n);
		if(n<=0){
			printf("n > 0 , xin hay kiem tra lai!\n");
		}	
	}while(n<= 0);
	int s = 1;
	for(int i = 1;i<=n;i++){
		s *=i;	
	}
	printf("Tich = %d", s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}

/*
n = 5
i = 1
s = 1

s = s * i = 1 * 1 = 1
	 = 1 * 2 = 2
	 = 2 * 3 = 6
	 = 6 * 4 = 24
	 = 24 * 5 = 120 
*/
