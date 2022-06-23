Tính S(x, n) = −1 + 𝑥^2/2! − 𝑥^4/4!+ … + (−1)^𝑛+1*𝑥^2𝑛/(2𝑛)!.

#include<stdio.h>
#include <conio.h>
#include<math.h>
int main(){
hoang:
	int n,x;
		printf("Nhap x= ");
		scanf("%d", &x);
	do{
		printf("Nhap n= ");
		scanf("%d", &n);
		if(n<=0){
			printf("N nhap khong hop le, xin hay kiem tra lai!\n");
		}
	}while(n<=0);
	
	float s = 1,s1, s2 = 1;
	for(int i=1;i<=n;i++)
	{
		int temp = 2 * i;		// gán lưu giá trị của 2n để chuẩn bị tính giai thừa
		s *= temp * (temp - 1);		// tinh giai thừa của 2n
		s1 = pow(x,2 * i);		// tính x mũ 2n
		s2+= pow(-1,i)*s1 /s;		// tinh tổng cần tìm
	}
	//printf("%f", s);
	//printf("\n%f", s1);
	printf("\n%f", -s2);	
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}	
	return 0;
}
