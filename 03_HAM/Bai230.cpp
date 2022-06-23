Hãy đếm số lượng chữ số lớn nhất của số nguyên dương n.

/*
n = 219076594
-> có tất cả 2 số lớn nhất và số lớn nhất là 9.
*/

#include <stdio.h>
#include<conio.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
int DemChuSoMax(int n){
	int temp = n, dem = 0;
	int max = temp % 10;	 // là 1 số bất kì
	if(temp == 0){
		dem = 1;
	}
	while (temp !=0)
	{
		int chuso = temp % 10;
		temp /= 10;
		if(chuso == max){
			dem++;
		}
		if(chuso > max){
			max = chuso;
		}
	}
    	return dem;
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
	int dem = DemChuSoMax(n);
	printf("%d",dem);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
