Tính tổng tất cả “ước số chẵn” của số nguyên dương n.
/*
n = 20 -> ước lẻ: 1,2,4,5,10,20 -> s = 36.
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
			printf("n > 0, xin hay nhap lai!\n");
		}
	}while(n<=0);
	int s =0;
	for(int i =1; i <= n;i++){
		if(n % i == 0){
			if(i % 2 == 0){
				s+=i;
			}
		}
	}
	printf("Tong cac so chan = %d", s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
