Nhập vào một chuỗi, hãy loại bỏ những khoảng trắng thừa trong chuỗi.
/*
Nhập vào một chuỗi, hãy loại bỏ những khoảng trắng thừa trong chuỗi.(chuẩn hóa chuỗi )
	- tạo bảo sao của chuỗi gốc để giữ nguyên chuỗi đầu vào
	- duyệt độ dài của chuỗi gặp phần tử nào khoảng trắng thì ta sẽ đi xóa nó đi, mỗi lần xóa xong nhớ phải cập nhật lại cho chuỗi
*/
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
char* ChuanHoaChuoi_Cach1(char *s) {
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
/*
// dùng hàm hỗ trợ isspace();
// dùng hàm thì nhớ #include<ctype.h>

char* ChuanHoaChuoi_Cach2(char* s) {
	// tạo bản sao giữ chuỗi đầu vào
	char* p = _strdup(s);
	int length = strlen(p);
	for (int i = 0; i < length; i++) {
		if (isspace(p[i]) && isspace(p[i+1])) {	//nếu có 2 khoảng trắng tiếp nhau
			XoaKytu(p, i);
			i--;	//cập nhật lại vị trí tránh nhảy qua vị trí khác
			length--;   // mỗi lần phải xóa xong phải cập nhật lại( do bên mảng nó sẽ chạy theo n, còn ở đây chạy theo length nên ta phải cập nhật lại cho nó).
		}
	}
	if (isspace(p[0])) {
		XoaKytu(p, 0);
		length--;
	}
	if (isspace(p[length - 1])) {
		XoaKytu(p, length - 1);
	}
	return p;
}*/
int main() {
	char s[] = "  truong   van     hoang    ";
	char p[Max];
	strcpy(p, ChuanHoaChuoi_Cach1(s));
	printf("\n%s", p);
	return 0;
}
