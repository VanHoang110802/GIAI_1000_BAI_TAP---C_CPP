Nhập một số nguyên dương n. Tính: S = 1 + 2 + … + n

#include <stdio.h>
#include <conio.h>
int main() {
hoang:
	int n, tong = 0;
	printf("N = ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		tong += i;
	}
	printf("Tong: %d", tong);	
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
