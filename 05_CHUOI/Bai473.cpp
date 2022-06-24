Viết chương trình đổi chữ xen kẻ 1 chữ hoa và 1 chữ thường.Ví dụ: nhập ABCDEfgh đổi thành AbCdEfGh

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define Max 50

char* DoiChuXenKe(char* s) {
	char* p = _strdup(s);
	int length = strlen(p);
	if (p[0] == ' ') {
		for (int i = 1; i < length; i++) {
			if (i % 2 != 0) {
				if (p[i] >= 'a' && p[i] <= 'z') {
					p[i] -= 32;
				}
			}
			else 
			{
				if (p[i] >= 'A' && p[i] <= 'Z') {
					p[i] += 32;
				}
			}
		}
		return p;
	}
	else {
		for (int i = 0; i < length; i++) {
			if (i % 2 == 0) {
				if (p[i] >= 'a' && p[i] <= 'z') {
					p[i] -= 32;
				}
			}
			else {
				if (p[i] >= 'A' && p[i] <= 'Z') {
					p[i] += 32;
				}
			}
		}
		return p;
	}
}
int main() {
	char s[] = " ABCDEfgh";	
	char p[Max];
	printf("%s",s);
	strcpy(p, DoiChuXenKe(s));
	printf("\n\n%s", p);
	return 0;
}
