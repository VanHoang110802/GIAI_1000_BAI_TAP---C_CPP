TÃ­nh S(n) = 1 - ð¥ + ð¥^3/3! â ð¥^5/5! + â¦ + (â1)^ð+1*ð¥^2ð+1/(2ð+1)!.

#include<stdio.h>
#include<conio.h>
#include<math.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
float TinhTongSoMu(int x, int n){
	float s = 1,s1, s2 = 0;
	for(int i=1;i<=n;i++)
	{
		int temp = 2 * i + 1;		
		s *= temp * (temp - 1);		
		s1 = pow(x,2 * i + 1);		
		s2+= pow(-1,i + 1)*s1 /s;	
	}
	return s2 - x;
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
	float tinh = TinhTongSoMu(x,n);
	printf("%.3f", tinh);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
