Viết chương trình nhập vào 1 số có 3 chữ số, in ra cách đọc của số này.

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main() {
	int n;
	printf("Nhap n= ");
	scanf("%d", &n);

	if (n < 0) {
		printf("am ");
		n *= -1;
	}

	if (n == 0) {
		printf("0");
	}

	int sochuso = log10((double)n)+1;

	if (sochuso == 3) {
		int hangtram = n / 100;
		if (hangtram == 1) {
			printf("mot tram ");
		}
		if (hangtram == 2) {
			printf("hai tram ");
		}
		if (hangtram == 3) {
			printf("ba tram ");
		}
		if (hangtram == 4) {
			printf("bon tram ");
		}
		if (hangtram == 5) {
			printf("nam tram ");
		}
		if (hangtram == 6) {
			printf("sau tram ");
		}
		if (hangtram == 7) {
			printf("bay tram ");
		}
		if (hangtram == 8) {
			printf("tam tram ");
		}
		if (hangtram == 9) {
			printf("chin tram ");
		}
		n %= 100;
	}
	sochuso--;
	if (sochuso == 2) {
		int hangchuc = n / 10;
		if (hangchuc == 1) {
			printf("muoi");
		}
		if (hangchuc == 2) {
			printf("hai muoi");
		}
		if (hangchuc == 3) {
			printf("ba muoi");
		}
		if (hangchuc == 4) {
			printf("bon muoi");
		}
		if (hangchuc == 5) {
			printf("nam muoi");
		}
		if (hangchuc == 6) {
			printf("sau muoi");
		}
		if (hangchuc == 7) {
			printf("bay muoi");
		}
		if (hangchuc == 8) {
			printf("tam muoi");
		}
		if (hangchuc == 9) {
			printf("chin muoi");
		}
	}
	sochuso--;
	if (sochuso == 1) {
		int hangdonvi = n % 10;
		if (hangdonvi == 1) {
			printf(" mot");
		}
		if (hangdonvi == 2) {
			printf(" hai");
		}
		if (hangdonvi == 3) {
			printf(" ba");
		}
		if (hangdonvi == 4) {
			printf(" bon");
		}
		if (hangdonvi == 5) {
			printf(" nam");
		}
		if (hangdonvi == 6) {
			printf(" sau");
		}
		if (hangdonvi == 7) {
			printf(" bay");
		}
		if (hangdonvi == 8) {
			printf(" tam");
		}
		if (hangdonvi == 9) {
			printf(" chin");
		}
	}
	return 0;
}
