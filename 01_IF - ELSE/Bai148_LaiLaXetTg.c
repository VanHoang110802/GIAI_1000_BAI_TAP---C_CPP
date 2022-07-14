Viết chương trình nhập 3 cạnh của một tam giác. Hãy cho biết đó là
tam giác gì?

#include <stdio.h>
#include <conio.h>
int main() {
hoang:
	int a,b,c;
	printf("nhap vao 3 canh: ");
	scanf("%d%d%d",&a,&b,&c);
	if (a +b <= c || a + c <= b || b + c <= a) {
		printf("3 canh khong tao thanh 1 tam giac");
		return 0;
	}
	else {
		if (a == b && a== c) {
			printf("3 canh tao thanh tam giac deu");
			return 0;
		}
		else if (a == b || b == c || c == a) {
			printf("3 canh tao thanh 1 tam giac can");
			return 0;
		}
		else if (a * a + b * b == c * c||a * a + c * c == b * b|| c * c + b * b == a * a) {
			printf("3 canh tao thanh 1 tam giac vuong");
			return 0;
		}
		else {
			printf("3 canh tao thanh 1 tam giac thuong");
			return 0;
		}
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
