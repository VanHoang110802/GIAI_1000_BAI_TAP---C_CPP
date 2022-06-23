Tính S(x, n) = −1 + 𝑥^2/2! − 𝑥^4/4!+ … + (−1)^𝑛+1*𝑥^2𝑛/(2𝑛)!.

#include<stdio.h>
#include<conio.h>
#include<math.h>
void NhapDuLieu(int &n){
	printf("Nhap so: ");
	scanf("%d", &n);
}
float TinhTongSoMu(int x, int n){
	float s = 1,s1, s2 = 1;
	for(int i=1;i<=n;i++)
	{
		int temp = 2 * i;		// gán lưu giá trị của 2n để chuẩn bị tính giai thừa
		s *= temp * (temp - 1);		// tinh giai thừa của 2n
		s1 = pow(x,2 * i);		// tính x mũ 2n
		s2+= pow(-1,i)*s1 /s;		// tinh tổng cần tìm
	}
	return -s2;
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
