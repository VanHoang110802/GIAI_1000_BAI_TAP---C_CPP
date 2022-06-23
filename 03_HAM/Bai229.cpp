Cho số nguyên dương n. Hãy tìm chữ số đầu tiên của n.
/*
n = 23587 -> chữ số đầu tiên n = 2.
*/
#include <stdio.h>
#include<conio.h>
#include <math.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
int ChuSoDauTien(int n){
	int temp = n,soluongchuso =0;
	while(temp !=0){
		int cs = temp % 10;
		temp /= 10;
		soluongchuso++;
	}
	temp = n;
	int cs = temp/ pow(10.0, --soluongchuso);
    	return cs ;
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
	int csdau = ChuSoDauTien(n);
	printf("%d",csdau);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
