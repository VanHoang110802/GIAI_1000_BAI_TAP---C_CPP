Kiểm tra số nguyên 4 byte có dạng 2^𝑘 hay không?
/*
n = 4 -> có dạng 2^k (4 = 2^2)
n = 6 -> không có dạng 2^k (6 = 2.44)
*/
#include <stdio.h>
#include<conio.h>
#include <math.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
void KiemTraDangMuK(int n){
	double kq = log10((double)n) / log10(2);
	if (kq == (int)kq){
		printf( "\nCo dang 2^k, 2^%d", (int)kq);
	}
	else{
		printf("\nKhong co dang 2^k");
	}
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
	KiemTraDangMuK(n);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
