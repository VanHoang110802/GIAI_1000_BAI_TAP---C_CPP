Tính tích tất cả “ước số” của số nguyên dương n.
/*
n = 10 -> ước số là những số nó có thể chia hết được: 1,2,5,10.
s = 1
s = s * n = 1 * 1 = 1
	  = 1 * 2 = 2
	  = 2 * 5 = 10
	  = 10 * 10 = 100
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
	int s = 1;
	for(int i =1; i <= n;i++){
		if(n % i == 0){
			s*=i;
		}
	}
	printf("Tich cua cac uoc so = %d", s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
