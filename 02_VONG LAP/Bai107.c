Tìm chữ số lớn nhất của số nguyên dương n.
/*
n = 312759684
-> max = 9.
*/

#include <stdio.h>
#include <conio.h>
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
	int max = temp % 10;	 // là 1 s? b?t kì
	while (temp !=0)
	{
		int chuso = temp % 10;
		temp /= 10;
		if(chuso > max){
			max = chuso;
		}
		
	}
	printf("So %d co chu so lon nhat la: %d",n,max);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
