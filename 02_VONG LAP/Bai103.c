Hãy tính tổng các chữ số chẵn của số nguyên dương n.
/*
n = 1234567890
-> s = 2 + 4 + 6 + 8 = 20
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
	int temp = n,tong = 0;
	while(temp != 0){
		int cs = temp %10;
		temp /= 10;
		if(cs % 2 == 0){
			tong+=cs;
		}
	}
	printf("Tong cac chu so chan co trong %d la %d .",n,tong);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
