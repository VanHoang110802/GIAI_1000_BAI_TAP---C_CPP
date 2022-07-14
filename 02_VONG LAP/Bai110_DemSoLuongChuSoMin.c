Hãy đếm số lượng chữ số nhỏ nhất của số nguyên dương n.
/*
n = 197316312
-> có tất cả 3 số bé nhất và số bé nhất là 1.
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
	int temp = n, dem = 0;
	int min = temp % 10;	 // là 1 s? b?t kì
	if(temp == 0){
		dem = 1;
	}
	while (temp !=0)
	{
		int chuso = temp % 10;
		temp /= 10;
		if(chuso == min){
			dem++;
		}
		if(chuso < min){
			min = chuso;
		}
	}
	printf("\nCo tat ca %d chu so be nhat va so be nhat la %d !", dem, min);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
