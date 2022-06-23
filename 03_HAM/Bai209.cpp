Tính S(n) = 1 + 𝑥 + 𝑥^3/3! + 𝑥^5/5! + … + 𝑥^2𝑛+1/(2𝑛+1)!.
#include<stdio.h>
#include<conio.h>
#include <math.h>
void NhapDuLieu(float &n){
	printf("Nhap so: ");
	scanf("%f", &n);
}
float TinhTong(float n,float x){
	float S = 1, T;
    	int M, N = 1;
    	int i = 1;
	while(i <= n)
   	{
		T = pow(x, (2 * i + 1));
        	M = 2 * i + 1;
       	 	N = N * M * (M - 1);
  		S = S + x + T/N;
       		i++;
    	}
	return S;
}
int main(){
hoang:
	float n,x;
	do{
	NhapDuLieu(x);
	if(x<= 0){
		printf("x > 0. Xin hay nhap lai!\n");
	}
	}while(x<= 0);
	do{
	NhapDuLieu(n);
	if(n<= 0){
		printf("n > 0. Xin hay nhap lai!\n");
	}
	}while(n<= 0);
	float tong = TinhTong(n,x);
	printf("%f",tong);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
