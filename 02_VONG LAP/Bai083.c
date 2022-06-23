Đếm số lượng “ước số chẵn” của số nguyên dương n.
/*
n = 20 -> ước : 1,2,4,5,10,20 -> có 4 ước chẵn.
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
	int dem = 0;
	for(int i =1; i <= n;i++){
		if(n % i == 0){
			if(i % 2 == 0){
				dem++;
			}
		}
	}
	printf("So %d co %d uoc chan",n, dem);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
