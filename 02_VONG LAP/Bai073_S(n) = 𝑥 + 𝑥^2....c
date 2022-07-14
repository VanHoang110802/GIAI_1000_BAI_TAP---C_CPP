Tính S(n) = 𝑥 + 𝑥^2/2! + 𝑥^3/3! + … + 𝑥^𝑛/𝑛!
/*
n = 4
x = 4
s = 0
s = s + x^n / n! = 0 + 4^1 / 1! = 4
	         = 4 + 4^2 / 2! = 12
		 = 12 + 4^3 / 3! = 22.666
		 = 22.666 + 4^4/ 4! = 33.332
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
int main(){
	int x,n;
	do{
		printf("Nhap x= ");
		scanf("%d", &x);
		if(x<=0){
			printf("x > 0, xin hay kiem tra lai!\n");
		}
	} while(x<=0);
	do{
		printf("Nhap mu n= ");
		scanf("%d", &n);
		if(n<=0){
			printf("n > 0, xin hay kiem tra lai!\n");
		}
	} while(n<=0);
	float s = 0;
	for(int i = 1; i <= n;i++){
		int tich = 1;
		for(int j = 1;j <= i;j++){
			tich *= j;
		}
		s+=pow(x,i)/tich;
	}
	printf("Tong = %.3f", s);
	return 0;
}
