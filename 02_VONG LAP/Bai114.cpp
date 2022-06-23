Hãy kiểm tra số nguyên dương n có phải số đối xứng hay không?
/*
n = 121, 12021... -> số đối xứng
n = 123, 6789,... -> không phải là số đối xứng
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
	printf("Cac chu so bi tach la: ");
	while (temp !=0)
	{
		int chuso = temp % 10;
		temp /= 10;
		printf("%d ", chuso);
		sodaonguoc += chuso * pow(10.0, dem--);
		
	}
	printf("\nSo dao nguoc: %d", sodaonguoc);
	if (n == sodaonguoc) {
		printf("\nDay la so doi xung!");
	}
	else {
		printf("\nDay khong la so doi xung!");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
