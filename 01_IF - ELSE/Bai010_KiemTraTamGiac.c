Nhập vào độ dài 3 cạnh của 1 tam giác.Kiểm tra xem 3 cạnh đó có tạo thành 1 tam giác hay không ? Và nếu
có thì sẽ tạo thành tam giác gì(thường / cân / vuông / vuông cân / đều)
Gợi ý : Điều kiện để tạo thành 1 tam giác đó là tổng của 2 cạnh bất kỳ luôn lớn hơn cạnh còn lại

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
int main() {
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
	return 0;
}
