Nhập vào 1 ký tự là chữ cái. Nếu nhập sai thì báo thông báo đã nhập sai. Nếu đúng thì đi kiểm tra nếu đó
đang là chữ cái thường thì biến nó thành chữ cái hoa, nếu nó là chữ cái hoa thì biến nó thành chữ cái thường.
Gợi ý: Ký tự chữ cái thường và hoa có mã ASCII cách nhau 32 đơn vị. Vd: ‘a’ là 97, ‘A’ là 65

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
int main() {
	char x;
	printf("Nhap vao 1 ki tu : ");
	scanf("%c", &x);
	if (x < 'A' || x>'Z' && x < 'a' || x>'z') {
		printf("Ky tu nhap khong hop le!");
		return 0;
	}
	else {
		if (x >= 'a' && x <= 'z') {
			x -= 32;
		}
		else if (x >= 'A' && x <= 'Z') {
			x += 32;
		}
	}
	printf("Ky tu sau khi bien doi: %c", x);
	return 0;
}
