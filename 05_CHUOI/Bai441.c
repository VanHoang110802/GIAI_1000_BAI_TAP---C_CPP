Hàm tính độ dài chuỗi: strlen(s) - 
(Không tính ký tự kết thúc: '\0')

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
int STRLEN(char *s){
	int dem =0;
	while(s[dem]!='\0'){
		dem++;
	}
	return dem;
}
int main(){
	char s[] = "Hoang";
	int length = STRLEN(s);
	printf("\nDo dai la: %d", length);
	return 0;
}
