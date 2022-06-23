Tính S(n) = 1 + 1/1+2 + 1/1+2+3 + … + 1/1+2+3+⋯+𝑛
#include<stdio.h>
#include<conio.h>
void NhapDuLieu(float &n){
	printf("Nhap so: ");
	scanf("%f", &n);
}
float TinhTong(float n){
	float s = 0, s1 = 0;
	for(int i=1;i<=n;i++)
	{
		 s+=i;
		s1+=1.0/s;
	}
	return s1;
}
int main(){
hoang:
	float n;
	do{
	NhapDuLieu(n);
	if(n<= 0){
		printf("n > 0. Xin hay nhap lai!\n");
	}
	}while(n<= 0);
	float tong = TinhTong(n);
	printf("%f",tong);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim space de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if( lc == 32){
		goto hoang;
	}
	return 0;
}
