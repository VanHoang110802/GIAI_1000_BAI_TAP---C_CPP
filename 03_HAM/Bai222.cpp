TΓ­nh S(n) = πβπ + πβ1βπ β 1 + 3β3 + β2 cΓ³ n β 1 dαΊ₯u cΔn.
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
