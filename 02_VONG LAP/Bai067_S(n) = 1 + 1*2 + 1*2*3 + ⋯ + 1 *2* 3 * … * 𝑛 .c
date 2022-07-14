Tính S(n) = 1 + 1*2 + 1*2*3 + ⋯ + 1 *2* 3 * … * 𝑛 

/*
n = 5
tong = 0
tich = 1
i = 1
j = 1
tich = tich * j = 1 * 1 = 1
		= 1 * 2 = 2
		= 2 * 3 = 6
		= 6 * 4 = 24
		= 24 * 5 = 120

tong = tong + tich = 0 + 1 = 1
		   = 1 + 2 = 3
		   = 3 + 6 = 9
		   = 9 + 24 = 33
		   = 33 + 120 = 153
*/

#include <stdio.h>
#include <conio.h>
int main(){
hoang:
	int n;
	do{
		printf("Nhap n= ");
		scanf("%d", &n);
		if(n <=0){
			printf("n > 0, xin hay kiem tra lai!\n");
		}
	}while(n<=0);
	int tong = 0;
	for(int i = 1; i <= n;i++){
		int tich = 1;
		for(int j = 1;j <= i;j++){
			tich *= j;
		}
		tong += tich;
	}
	printf("Tong = %d", tong);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
