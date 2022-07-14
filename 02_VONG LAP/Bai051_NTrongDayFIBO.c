Nhập n (n >= 1). In n số đầu tiên trong dãy Fibonacy. Biết nguyên tắc của dãy Fibonacy như sau:
a[0] = a[1] = 1
a[n] = a[n – 1] + a[n – 2]
Vd: Dãy Fibonacy bình thường là: 1 1 2 3 5 8 13 21 34 55 89 144 233
Test 1: Nhập n = 3 => in ra là: 1 1 2
Test 2: Nhập n = 7 => in ra là: 1 1 2 3 5 8 13
Test 3: Nhập n = 1 => in ra là 1

/*
Ý tưởng: ta thấy số thứ 2 chính là tổng của số thứ nhất cộng với số thứ 2. Ta sẽ dùng vòng lặp in ra 2 số ban đầu, từ 
số thứ 3 đổ lên, ta lấy số đầu cộng số thứ 2, rồi cập nhật cho biến số thứ 2 là số thứ 1, biến số thứ 2 là số tổng 
mình vừa tính được để tránh vòng lặp lặp lại số giống nhau liên tục.

*/
#include <stdio.h>
#include <conio.h>
int main() {
hoang:
	int n;
	do {
		printf("Nhap n= ");
		scanf("%d", &n);
		if (n <= 0) {
			printf("n > 0, xin hay kiem tra lai !");
		}
	} while (n <= 0);
	int a1 = 1, a2 = 1;
	if (n == 1) {
		printf("%d", a1);
	}
	else if (n == 2) {
		printf("%d %d", a1, a2);
	}
	else {
		printf("%d %d ", a1, a2);
		for (int i = 0; i < n - 2; i++) {
			int an = a1 + a2;
			a1 = a2;
			a2 = an;
			printf("%d ", an);
		}
		
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
