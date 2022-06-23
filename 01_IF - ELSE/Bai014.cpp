Viết chương trình nhập vào 1 số nguyên dương giới hạn 9 chữ số. In ra cách đọc của số này.
Vd: 12345 => Muoi hai ngan ba tram bon muoi lam

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main() {
	int n;
	printf("Nhap so nguyen duong: ");
	scanf("%d", &n);
	if (n < 0) {
		printf("Am ");
		n *= -1;
	}
	if (n == 0) {
		printf("khong");
	}
	int sochuso = log10((double)n) + 1;
	if (sochuso > 9) {
		printf("So qua lon, khong ho tro so nay!");
		return 0;
	}
	if (sochuso == 9) {
		int x = n / 100000000;
		if (x == 1) {
			printf("mot tram ");
		}
		if (x == 2) {
			printf("hai tram ");
		}
		if (x == 3) {
			printf("ba tram ");
		}
		if (x == 4) {
			printf("bon tram ");
		}
		if (x == 5) {
			printf("nam tram ");
		}
		if (x == 6) {
			printf("sau tram ");
		}
		if (x == 7) {
			printf("bay tram ");
		}
		if (x == 8) {
			printf("tam tram ");
		}
		if (x == 9) {
			printf("chin tram ");
		}
		sochuso--;
		n %= 100000000;
	}
	if (sochuso == 8) {
		int x = n / 10000000;
		if (x == 1) {
			printf("muoi ");
		}
		if (x == 2) {
			printf("hai muoi ");
		}
		if (x == 3) {
			printf("ba muoi ");
		}
		if (x == 4) {
			printf("bon muoi ");
		}
		if (x == 5) {
			printf("nam muoi ");
		}
		if (x == 6) {
			printf("sau muoi ");
		}
		if (x == 7) {
			printf("bay muoi ");
		}
		if (x == 8) {
			printf("tam muoi ");
		}
		if (x == 9) {
			printf("chin muoi ");
		}
		sochuso--;
		n %= 10000000;
	}

	if (sochuso == 7) {
		int x = n / 1000000;
		if (x == 1) {
			printf("mot trieu ");
		}
		if (x == 2) {
			printf("hai trieu ");
		}
		if (x == 3) {
			printf("ba trieu ");
		}
		if (x == 4) {
			printf("bon trieu ");
		}
		if (x == 5) {
			printf("nam trieu ");
		}
		if (x == 6) {
			printf("sau trieu ");
		}
		if (x == 7) {
			printf("bay trieu ");
		}
		if (x == 8) {
			printf("tam trieu ");
		}
		if (x == 9) {
			printf("chin trieu ");
		}
		sochuso--;
		n %= 1000000;
	}

	if (sochuso == 6) {
		int x = n / 100000;
		if (x == 1) {
			printf("mot tram ");
		}
		if (x == 2) {
			printf("hai tram ");
		}
		if (x == 3) {
			printf("ba tram ");
		}
		if (x == 4) {
			printf("bon tram ");
		}
		if (x == 5) {
			printf("nam tram ");
		}
		if (x == 6) {
			printf("sau tram ");
		}
		if (x == 7) {
			printf("bay tram ");
		}
		if (x == 8) {
			printf("tam tram ");
		}
		if (x == 9) {
			printf("chin tram ");
		}
		sochuso--;
		n %= 100000;
	}
	
	 if (sochuso == 5) {
		int x = n / 10000;
		if (x == 1) {
			printf("muoi ");
		}
		if (x == 2) {
			printf("hai muoi ");
		}
		if (x == 3) {
			printf("ba muoi ");
		}
		if (x == 4) {
			printf("bon muoi ");
		}
		if (x == 5) {
			printf("nam muoi ");
		}
		if (x == 6) {
			printf("sau muoi ");
		}
		if (x == 7) {
			printf("bay muoi ");
		}
		if (x == 8) {
			printf("tam muoi ");
		}
		if (x == 9) {
			printf("chin muoi ");
		}
		sochuso--;
		n %= 10000;
	}
	
	if (sochuso == 4) {
		int x = n / 1000;
		if (x == 1) {
			printf("mot nghin ");
		}
		if (x == 2) {
			printf("hai nghin ");
		}
		if (x == 3) {
			printf("ba nghin ");
		}
		if (x == 4) {
			printf("bon nghin ");
		}
		if (x == 5) {
			printf("nam nghin ");
		}
		if (x == 6) {
			printf("sau nghin ");
		}
		if (x == 7) {
			printf("bay nghin ");
		}
		if (x == 8) {
			printf("tam nghin ");
		}
		if (x == 9) {
			printf("chin nghin ");
		}
		sochuso--;
		n %= 1000;
	}
	
	if (sochuso == 3) {
		int x = n / 100;
		if (x == 1) {
			printf("mot tram ");
		}
		if (x == 2) {
			printf("hai tram ");
		}
		if (x == 3) {
			printf("ba tram ");
		}
		if (x == 4) {
			printf("bon tram ");
		}
		if (x == 5) {
			printf("nam tram ");
		}
		if (x == 6) {
			printf("sau tram ");
		}
		if (x == 7) {
			printf("bay tram ");
		}
		if (x == 8) {
			printf("tam tram ");
		}
		if (x == 9) {
			printf("chin tram ");
		}
		sochuso--;
		n %= 100;
	}
	
	if (sochuso == 2) {
		int x = n / 10;
		if (x == 1) {
			printf("muoi");
		}
		if (x == 2) {
			printf("hai muoi");
		}
		if (x == 3) {
			printf("ba muoi");
		}
		if (x == 4) {
			printf("bon muoi");
		}
		if (x == 5) {
			printf("nam muoi");
		}
		if (x == 6) {
			printf("sau muoi");
		}
		if (x == 7) {
			printf("bay muoi");
		}
		if (x == 8) {
			printf("tam muoi");
		}
		if (x == 9) {
			printf("chin muoi");
		}
		sochuso--;
		n %= 10;
	}
	
	if (sochuso == 1) {
		int x = n % 10;
		if (x == 1) {
			printf(" mot");
		}
		if (x == 2) {
			printf(" hai");
		}
		if (x == 3) {
			printf(" ba");
		}
		if (x == 4) {
			printf(" bon");
		}
		if (x == 5) {
			printf(" nam");
		}
		if (x == 6) {
			printf(" sau");
		}
		if (x == 7) {
			printf(" bay");
		}
		if (x == 8) {
			printf(" tam");
		}
		if (x == 9) {
			printf(" chin");
		}
	}
	return 0;
}
