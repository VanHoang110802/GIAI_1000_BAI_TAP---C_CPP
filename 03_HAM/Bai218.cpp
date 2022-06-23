Tính S(n) = √(2 + √(2 + √(2 + ⋯ +√(2 + √(2)))) có n dấu căn.
#include<stdio.h>
#include<conio.h>
#include <math.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
float TinhTongCan(int n){
	float S;
    	S = sqrt((float)2);
    	for(int i = 2; i <= n; i++) {
    	    S = sqrt(2 + S);
    	}
	return S;
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
	float tong = TinhTongCan(n);
	printf("%f", tong);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
