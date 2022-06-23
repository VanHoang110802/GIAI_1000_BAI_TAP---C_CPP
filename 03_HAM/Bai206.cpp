Tính S(n) = 𝑥 + 𝑥^2/1+2 + 𝑥^3/1+2+3 + … + 𝑥^𝑛/1+2+3+⋯+𝑛
#include<stdio.h>
#include<conio.h>
#include <math.h>
void NhapDuLieu(float &n){
	printf("Nhap so: ");
	scanf("%f", &n);
}
float TinhTong(float n,float x){
	float s = 0, s1 = 0;
	for(int i=1;i<=n;i++)
	{
		 s+=i;
		s1+=pow(x,i)/s;
	}
	return s;
}
int main(){
hoang:
	float n,x;
	do{
	NhapDuLieu(x);
	if(x<= 0){
		printf("x > 0. Xin hay nhap lai!\n");
	}
	}while(n<= 0);
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
