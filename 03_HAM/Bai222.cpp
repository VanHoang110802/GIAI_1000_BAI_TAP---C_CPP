Tính S(n) = 𝑛√𝑛 + 𝑛−1√𝑛 − 1 + 3√3 + √2 có n – 1 dấu căn.
#include<stdio.h>
#include <math.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
float TinhTongCan(int n){
	int i = 3;
    	float S = pow(2.0, 1.0/2);
    	while(i <= n){
        	S = pow((i + S) * 1.0, 1.0/i);
        	i++;
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
