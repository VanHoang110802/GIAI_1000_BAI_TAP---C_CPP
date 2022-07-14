Nhập vào 1 số nguyên dương n, đếm xem n có bao nhiêu chữ số, tìm ra chữ số lớn nhất, chữ số nhỏ nhất.
Vd: n = 216935
-> Có 6 chữ số
-> Chữ số Min = 1, Chữ số Max = 9

#include <stdio.h>
#include <conio.h>
#include <math.h>
int main() {
hoang:
	int n;
	do {
		printf("Nhap n= ");
		scanf("%d", &n);
		if (n < 0) {
			printf("Vui long nhap lai n, n>=0 !\n");
		}
	} while (n < 0);
	if (n == 0) {
		printf("So %d nay co 1 chu so!", n);
	}
	else {
		int dem = log10((double)n) + 1;

		printf("So %d nay co %d chu so!", n, dem);
	}

	int chuso, temp = n, min, max;
	min = max = temp % 10;	// gán mặc định min, max bằng chữ số cuối (cái này quên mất lần 1)
	printf("\ncac chu so sau khi tach khoi n: ");
	if (temp == 0) {
		chuso = 0;
		printf("%d", chuso);
	}
	while (temp != 0) { 	// vòng lặp này bị lú, quên mất lần 2 -.-! (xác định lộn sang vòng lặp for)
		chuso = temp % 10;
		temp /= 10;
		if (chuso < min) {
			min = chuso;
		}
		if (chuso > max) {
			max = chuso;
		}
		printf("%d ", chuso);
	}
	printf("\nmin: %d ", min);
	printf("max: %d ", max);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
