Giải phương trình 𝑎𝑥 + 𝑏 = 0.
/*
phương trình 2x - 3 = 0
->x = 3/2.
- không được do-while ở chỗ nhập xuất các phần tử của phương trình vì phương trình sẽ có số âm.

*/

#include <stdio.h>
#include <conio.h>
int main() {
hoang:
	int a, b;
	printf("nhap a= ");
	scanf("%d", &a);
	printf("nhap b= ");
	scanf("%d", &b);
	if (a == 0) {
		if (b == 0) {
			printf("phuong trinh co vo so nghiem");
		}
		else {
			printf("phuong trinh vo nghiem");
		}
	}
	else {
		printf("phuong trinh co nghiem = %d", -b / a);
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
