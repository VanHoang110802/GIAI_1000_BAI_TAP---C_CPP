Cho 1 chuỗi, hãy đảo ngược thứ tự từng ký tự trong từng từ của chuỗi
vd: GameLoft -> tfoLemaG

/*
bản gốc: For a string, reverse the order of each character in each word of the string.
Giả sử: Truong Van Hoang
-> đảo lại là: gnourT naV gnaoH
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include <string.h>
#define Max 50
int STRLEN(char* s) {
	int dem = 0;
	while (s[dem] != '\0') {
		dem++;
	}
	return dem;
}
void HoanVi(char& x, char& y) {
	char temp = x;
	x = y;
	y = temp;
}
void STRREV(char* s) {
	int length = STRLEN(s);
	for (int i = 0; i < length / 2; i++) {
		HoanVi(s[i], s[length - 1 - i]);
	}
}
int main() {
	char str[Max] = "GameLoft";
	const char s[] = " ";
	char* token = strtok(str, s);
	while (token != NULL) {
		STRREV(token);
		printf("%s ", token);
		token = strtok(NULL, s);
	}
	return(0);
}
