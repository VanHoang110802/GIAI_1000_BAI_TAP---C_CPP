Cho hai số nguyên dương a và b. Hãy vẽ lưu đồ, tìm ước chung lớn nhất
của hai giá trị này.
/*
16: 1,2,4,8,16
8: 1,2,4,8
-> UCLN: 8
*/
#include <stdio.h>
#include <conio.h>

int main(){
hoang:
	int a, b;
	do{
		printf("Nhap a= ");
		scanf_s("%d", &a);
		if (a <= 0) {
			printf("a phai luon lon hon 0, xin hay kiem tra lai!\n");
		}
	} while (a <= 0);

	do {
		printf("Nhap b= ");
		scanf_s("%d", &b);
		if (b <= 0) {
			printf("b phai luon lon hon 0, xin hay kiem tra lai!\n");
		}

	} while (b <= 0);

	int min = a < b ? a : b;
	int max = a > b ? a : b;
	int ucln;

	if (max % min == 0) {	// mình chỉ xét min thôi còn max chắc chắn không chia hết được rồi.
		ucln = min;
	}
	else {
		for (int i = min / 2; i >= 1; i--) {
			if (max % i == 0 && min%i==0) {
				ucln = i;
				break;
			}
		}
	}
	printf("UCLN(%d,%d) = %d", a, b, ucln);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
