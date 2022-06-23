Hãy tính tích các chữ số lẻ của số nguyên dương n.
/*
n = 1234567890
-> các chữ số lẻ: 1,3,5,7,9. -> s = 945.
*/
#include <stdio.h>
#include <conio.h>
int main(){
hoang:
	int n;
	do{
		printf("Nhap n= ");
		scanf("%d",&n);
		if(n<=0){
			printf("n > 0, xin hay kiem tra lai!\n");
		}
	}while(n<=0);
	int temp = n,tich = 1;
	while(temp != 0){
		int cs = temp %10;
		temp /= 10;
		if(cs % 2 != 0){
			tich *= cs;
		}
	}
	printf("Tich cac chu so le la: %d", tich);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
