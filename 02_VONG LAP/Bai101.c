Hãy tính tích các chữ số của số nguyên dương n.
/*
n = 2346816
-> s = 2 * 3 * 4 * 6 * 8 * 1 * 6 = 6912
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
	int temp = n,s = 1;
	while(temp != 0){
		int cs = temp % 10;
		temp /=10;
		s*=cs;
	}
	printf("Tich = %d",s);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
