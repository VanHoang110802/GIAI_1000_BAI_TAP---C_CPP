Nhập vào tháng & năm. Hãy cho biết tháng đó trong năm đó có bao nhiêu ngày

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
int main() {
	int thang, nam;
	printf("nhap thang: ");
	scanf("%d", &thang);
	if (thang < 0 || thang >12) {
		printf("So thang nhap khong hop le! Xin kiem tra lai!");
		return 0;
	}
	printf("nhap nam: ");
	scanf("%d", &nam);
	if (thang == 1 || thang == 3 || thang == 7 || thang == 8 || thang == 10 || thang == 12) {
		printf("thang nay co 31 ngay");
	}
	else if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
		printf("thang co 30 ngay");
	}
	else {
		if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0) {
			printf("thang nay co 29 ngay");
		}
		else {
			printf("thang nay co 28 ngay");
		}
	}
	return 0;
}
