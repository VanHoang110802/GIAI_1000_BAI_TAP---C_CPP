In ra n phần tử của dãy Fibonacy.

#include<stdio.h>
#include<conio.h>
void NhapDuLieu(int &x){
	printf("Nhap so = ");
	scanf("%d", &x);
}
void Fibonancci(int n){
	int a0,a1;
	a0= a1 = 1;
	if(n == 1){
		printf("%d", a0);
	}
	else if(n == 2){
		printf("%d %d", a0, a1);
	} else {	
		printf("%d %d", a0, a1);
		for(int i = 1; i<= n - 2 ;i++){
			int an = a0 + a1;
			a0 = a1;
			a1 = an;
		}
		printf(" %d", an);
	}
}
int main(){
	int n;
	NhapDuLieu(n);
	Fibonancci(n);
	return 0;
}
