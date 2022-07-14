Viết chương trình đảo ngược các kí tự trong chuỗi.Ví dụ: nhập ABCDE, xuất ra màn hình là:EDCBA
/*
dùng mịa strrev cho nhanh =))
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main(){
	char s[] = "ABCDE";
	strrev(s);
	printf("%s",s);
	return 0;
}
