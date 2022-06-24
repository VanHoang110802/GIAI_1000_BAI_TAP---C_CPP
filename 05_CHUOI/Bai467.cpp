/* 
substring(vị trí bắt đầu, số lượng ký tự cần lấy)

s = "Truong Van Hoang";

substring(6, 3) => "Van"

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>

char* SubString(char* s, int start, int count) {
	char p[30];
	int k = 0;
	for (int i = start; i < start + count; i++) {
		p[k++] = s[i];
	}
	p[k] = '\0'; // kết thúc chuỗi
	return p;
}

int main() {
	char s[] = "Van lai la hoang dap trai :vv";

	char p[30];
	strcpy(p, SubString(s, 10, 15));

	printf("\np = %s", p);
	return 0;
}
