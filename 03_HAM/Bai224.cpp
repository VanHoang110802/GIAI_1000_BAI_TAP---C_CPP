Hãy tìm số đảo ngược của số nguyên dương n.
/*
n = 24689
sodaonguoc = 9 * 10000 + 8 * 1000 + 6 * 100 + 4 * 10 + 2 *1
-> 98642.

*/
#include <stdio.h>
#include<conio.h>
#include <math.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
int SoDaoNguoc(int n){
	int temp = n;
	int dem = log10((double)temp);
	int sodao = 0;
	while (temp !=0)
	{
		int chuso = temp % 10;
		temp /= 10;
		printf("%d ", chuso);
		sodao += chuso * pow(10.0, dem--);
		
	}
    	return sodao ;
}
int main() {
hoang:
	int n;
	do{
	NhapDuLieu(n);
	if(n<= 0){
		printf("n > 0. Xin hay nhap lai!\n");
	}
	}while(n<= 0);
	int csdao = SoDaoNguoc(n);
	printf("%d",csdao);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
