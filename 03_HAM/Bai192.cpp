Viết hàm tính S = n√x (n là số nguyên dương).

#include <stdio.h>
#include<conio.h>
#include <math.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
float TinhCan(int n, int x){
	float S;
	n = 1/n;
	S = pow(x,n);
	return S;
}
int main(){
hoang:
	float x,n;
	NhapDuLieu(x);
	do{
	NhapDuLieu(n);
	if(n<= 0){
		printf("n > 0. Xin hay nhap lai!\n");
	}
	}while(n<= 0);
	float tinh = TinhCan(n,x);
	printf("Can bac %.1f cua %.1f la %.3f.",n,x,tinh);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
