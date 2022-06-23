Kiểm tra số nguyên 4 byte có dạng 2^𝑘 hay không?
/*
n = 4 -> có dạng 2^k (4 = 2^2)
n = 6 -> không có dạng 2^k (6 = 2.44)
*/
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main() {
hoang:
	int n;
	do{
		printf( "nhap n = ");
		scanf("%d",&n);
		if(n<=0){
			printf("n > 0, xin hay kiem tra lai!\n");
		}
	}while(n <= 0);
	double kq = log10((double)n) / log10(2);
	if (kq == (int)kq)
	{
		printf( "\nCo dang 2^k, 2^%d", (int)kq);
	}
	else
	{
		printf("\nKhong co dang 2^k");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
