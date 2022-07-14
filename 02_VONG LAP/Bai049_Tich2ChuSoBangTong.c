Tìm và in lên màn hình tất cả các số nguyên trong phạm vi từ 10 đến 99 sao cho tích của 2 chữ số bằng 2 lần 
tổng của 2 chữ số đó. Ví dụ: Số 44

// dựa vào công thức: a*b == 2*(a+b).
#include <stdio.h>
#include <conio.h>
int main() {
hoang:
	int chuso1, chuso2;
	for (int i = 10; i <= 99; i++) {
		int temp = i;
		chuso1 = temp % 10;
		temp /= 10;
		chuso2 = temp % 10;
		if (chuso1 * chuso2 == (2 * (chuso1 + chuso2))) {
			printf(" %d ", i);
		}
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
