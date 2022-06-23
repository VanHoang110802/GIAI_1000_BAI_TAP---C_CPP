Tính S(x, n) = −𝑥 + 𝑥^2/1+2 − 𝑥^3/1+2+3 + … + (−1)𝑛*𝑥^𝑛/1+2+3+⋯+𝑛.

#include<stdio.h>
#include<conio.h>
#include<math.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
int TinhTongSoMu(int x, int n){
	int s = 0, s1 = 0;
	for(int i=1;i<=n;i++)
	{
		s+=i;
		s1+=pow(-1,i)*(pow(x,i)/s);
	}
	return s1;
}
int main(){
hoang:
	int n,x;
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
	int tinh = TinhTongSoMu(x,n);
	printf("%d", tinh);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
