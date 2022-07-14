Tìm ước số chung lớn nhất của 2 số nguyên dương a và b nhập từ bàn phím.

/*
Ư(12) = {1; 2; 3; 4; 6; 12}

 Ư(30) = {1; 2; 3; 5; 6; 10; 15; 30}

Các phần tử chung của Ư(12) và Ư(30) là: 1; 2; 3; 6.

Vậy ƯC(12, 30) = {1; 2; 3; 6} -> ƯCLN (12,30) = 6.

ý tưởng: xét từ số bé nhất và xét các số mà nó chia hết, lần lượt lấy các số đó so sánh với thằng lớn hơn, nếu thằng lớn hơn mà nó cũng chia hết -> thỏa mãn. 
Lưu ý: ta nên xét từ số lớn nhất về số bé nhất, nếu số đó mà bằng nhau thì lập tức thoát ra luôn. Bởi vì nó đã đảm bảo 
chỗ đó là lớn nhất rồi.
Và, số nó chỉ chia hết trong đoạn từ [1, n/2] và chính nó mà thôi, nếu hơn chắc chắn nó sẽ không chia hết được. Để 
tránh dài dòng rắc rối ta chỉ nên xét số đó ngừng lại khi nó chia 2 và chính nó thôi, nếu xét hơn cũng chẳng để làm gì,
dư thừa.
*/

#include <stdio.h>
#include <conio.h>

int main()
{
hoang:
	int a, b;
	do{
	printf("Nhap a= ");
	scanf("%d", &a);
	if (a <= 0) {
		printf("a phai luon lon hon 0, xin hay kiem tra lai!\n");
	}
	}while (a <= 0);

	do {
		printf("Nhap b= ");
		scanf("%d", &b);
		if (b <= 0) {
			printf("b phai luon lon hon 0, xin hay kiem tra lai!\n");
		}
		
	} while (b <= 0);

	int min = a < b ? a : b;
	int max = a > b ? a : b;
	int ucln;

	if (max % min == 0) {	// mình chỉ xét min thôi, còn max chắc chắn không chia được rồi.
		ucln = min;
	}
	else {
		for (int i = min / 2; i >= 1; i--) {
			if (max % i == 0 && min % i == 0) {
				ucln = i;
				break;
			}
		}
	}
	printf("UCLN(%d,%d) = %d",a,b, ucln);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
