Tìm chữ số nhỏ nhất của số nguyên dương n.
/*
n = 372159684
-> max = 1.
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
	int min = temp % 10;	 // là 1 số bất kì
	while (temp !=0)
	{
		int chuso = temp % 10;
		temp /= 10;
		if(chuso < min){
			min = chuso;
		}
		
	}
	printf("So %d co chu so be nhat la: %d",n,min);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
