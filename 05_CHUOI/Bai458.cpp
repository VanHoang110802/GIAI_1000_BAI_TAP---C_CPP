Các ký tự thành ký tự hoa (giống strupr).
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
char* BienDoiThanhHoa(char *s){
	// tạo bản sao cho chuỗi vì phải giữ nguyên đầu vào.
	char *p = strdup(s);
	strupr(p);
	return p;
}
int main(){
	char s[] = "Hoang dep trai";
	char p[30];
	strcpy(p, BienDoiThanhHoa(s));	// gán chuỗi s sang cho p
	printf("\n%s",s);
	printf("\n%s",p);
	return 0;
}
