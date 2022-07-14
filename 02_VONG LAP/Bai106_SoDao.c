Hãy tìm số đảo ngược của số nguyên dương n.
/*
n = 24689
sodaonguoc = 9 * 10000 + 8 * 1000 + 6 * 100 + 4 * 10 + 2 *1
-> 98642.

*/
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main() {
hoang:
	int n;
	do {
		printf("Nhap so n= ");
		scanf("%d", &n);
		if (n <= 0) {
			printf("Vui long nhap lai! n > 0\n");
		}
	} while (n <= 0);
	int temp = n;
	int dem = log10((double)temp);
	int sodaonguoc = 0;
	while (temp !=0)
	{
		int chuso = temp % 10;
		temp /= 10;
		printf("%d ", chuso);
		sodaonguoc += chuso * pow(10.0, dem--);
		
	}
	printf("\nSo dao nguoc: %d", sodaonguoc);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
