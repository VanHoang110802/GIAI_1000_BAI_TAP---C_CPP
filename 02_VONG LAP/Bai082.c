Tính tích tất cả “ước số lẻ” của số nguyên dương n.
/*
n = 15 -> ước lẻ: 1,3,5,15 -> s = 225.
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
	printf("So %d co uoc le la: ", n);
	for(int i =1; i <= n;i++){
		if(n % i == 0){
			if(i % 2 != 0){
				s*=i;
			}
		}
	}
	printf("Tich cac so le = %d", s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
