Hãy đếm số lượng chữ số lớn nhất của số nguyên dương n.

/*
n = 219076594
-> có tất cả 2 số lớn nhất và số lớn nhất là 9.
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
	int max = temp % 10;	 // là 1 s? b?t kì
	if(temp == 0){
		dem = 1;
	}
	while (temp !=0)
	{
		int chuso = temp % 10;
		temp /= 10;
		if(chuso == max){
			dem++;
		}
		if(chuso > max){
			max = chuso;
		}
	}
	printf("\nCo tat ca %d chu so lon nhat va so lon nhat la %d!", dem, max);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
