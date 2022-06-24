Nhập vào hai chuỗi s1 và s2, nối chuỗi s2 vào s1. Xuất chuỗi s1 ra màn hình

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define Max 100

void XoaKytu(char* s, int vitrixoa) {
	int length = strlen(s);
	for (int i = vitrixoa + 1; i < length; i++) {
		s[i - 1] = s[i];
	}
	s[length - 1] = '\0';	// cập nhật cho kết thúc chuỗi.
}
char* ChuanHoaChuoi(char *s) {
	// tạo bản sao giữ chuỗi đầu vào
	char* p = _strdup(s);
	int length = strlen(p);
	for (int i = 0; i < length; i++) {
		if (p[i] == ' ' && p[i + 1] == ' ') {	//nếu có 2 khoảng trắng tiếp nhau
			XoaKytu(p, i);
			i--;	//cập nhật lại vị trí tránh nhảy qua vị trí khác
			length--;   // mỗi lần phải xóa xong phải cập nhật lại( do bên mảng nó sẽ chạy theo n, còn ở đây chạy theo length nên ta phải cập nhật lại cho nó).
		}
	}
	if (p[0] == ' ') {
		XoaKytu(p, 0);
		length--;
	}
	if (p[length - 1] == ' ') {
		XoaKytu(p, length - 1);
	}
	return p;
}
int main() {
	char s1[Max] = "truong   van     hoang     ";
	char s2[] = " dep trai ";
	char p[Max];
	strcpy(p, ChuanHoaChuoi(s1));
	strcat(p, s2);
	printf("%s", p);
	return 0;
}
