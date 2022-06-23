Cho số nguyên dương n. Tính tổng các ước số nhỏ hơn chính nó.
/*
n = 20 -> ước : 1,2,4,5,10,20 -> có s = 1 + 2 + 4 + 5 + 10 = 22.
*/
#include <stdio.h>
#include <conio.h>
int main(){
hoang:
	int n;
	do{
		printf("Nhap n= ");
		scanf("%d", &n);
		if(n <=0){
			printf("n > 0, xin hay nhap lai!\n");
		}
	}while(n<=0);
	int s = 0;
	for(int i =1; i < n;i++){
		if(n % i == 0){
			s+=i;
		}
	}
	printf("tong cac uoc = %d",s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
