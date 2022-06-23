Cho số nguyên dương n. Kiểm tra số nguyên dương n có phải là số
nguyên tố hay không?
/*
số nguyên tố: 2,3,7,9,17,191,997....
số không nguyên tố: cứ chẵn > 2 thì không là số nguyên tố.
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
int main(){
hoang:
	int n;
	do {
		printf("Nhap n= ");
		scanf("%d", &n);
		if (n <= 0) {
			printf("Vui long nhap lai n, n >0 !\n");
		}
	} while (n <= 0);

	int temp = n, check = 1;
	for (int i = 2; i * i <= temp; i++) {
		if (temp % i == 0) {
			check = 0;
			break;
		}
	}

	if (check == 1 && temp >= 2) {
		printf("Day la so nguyen to!");
	}
	else {
		printf("Day khong la so nguyen to!");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
