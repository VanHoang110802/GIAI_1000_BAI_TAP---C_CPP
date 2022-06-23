Kiểm tra số nguyên 4 byte có dạng 3^𝑘 hay không?
/*
n = 27 -> có dạng 3^k (27 = 3^3)
n = 26 -> không có dạng 3^k (26 = 2.96)
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
	double kq = log10((double)n) / log10(3);
	if (kq == (int)kq)
	{
		printf( "\nCo dang 3^k, 3^%d", (int)kq);
	}
	else
	{
		printf("\nKhong co dang 3^k");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
