Tính S(n) = 1 + 2 + 3 + … + n
/*
n = 2
s = s + i = 0 + 0 = 0
	  = 0 + 1 = 1
	  = 1 + 2 = 3
->s = 3
*/
#include <stdio.h>
#include <conio.h>
int main(){
hoang:
	int n;
	do{
		printf("Nhap n= ");
		scanf_s("%d", &n);
		if(n<=0){
			printf("n >0, xin vui long kiem tra lai!\n");
		}
	}while(n<=0);
	int tong =0;
	for(int i = 0;i <= n;i++){
		tong +=i;
	}
	printf("Tong = %d", tong);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
