Hãy đêm số lượng chữ số đầu tiên của số nguyên dương n.
/*
n = 225827942 -> chữ số đầu tiên n = 2.
-> số lượng 4
*/
#include <stdio.h>
#include<conio.h>
#include <math.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
int DemChuSoDau(int n){
	int temp = n,soluongchuso =0, dem = 0;
	while(temp !=0){
		int cs = temp % 10;
		temp /= 10;
		soluongchuso++;
	}
	temp = n;
	int csd = temp/ pow(10.0, --soluongchuso);
	while(temp !=0){
		int cs = temp % 10;
		temp /= 10;
		if(csd == cs){
			dem++;
		}
	}
    	return dem;
}
int main(){
hoang:
	int n;
	do{
	NhapDuLieu(n);
	if(n<= 0){
		printf("n > 0. Xin hay nhap lai!\n");
	}
	}while(n<= 0);
	int dem = DemChuSoDau(n);
	printf("%d",dem);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
