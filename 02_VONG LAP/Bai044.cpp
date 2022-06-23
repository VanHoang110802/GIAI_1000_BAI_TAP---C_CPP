Nhập một số nguyên dương n. Tính: S= 1^2 + 2^2 + … + n^2

#include <stdio.h>
#include <conio.h>
int main(){
	int n;
	printf("Nhap so n= ");
	scanf("%d", &n);
	int i, S = 0;
	for(i = 1;i<=n;i++){
		S += (i*i);
	} 
	printf("Tong: %d", S);
	return 0;
}
