Cho số nguyên dương n. Kiểm tra số nguyên dương n có phải là số
chính phương hay không
/*
số chính phương là số căn ra được 1 số nguyên. 
4,9,16,49,100....

*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
int main() {
hoang:
	int n;
	printf("nhap so n = ");
	scanf("%d", &n);
	double kq = sqrt((double)n);
	if (n > 0) {
		if (kq == (int)kq) {
			printf("Day la so chinh phuong");
		}
		else {
			printf("Day khong la so chinh phuong");
		}
	}
	else {
		printf("So nhap khong hop le, n > 0");
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
