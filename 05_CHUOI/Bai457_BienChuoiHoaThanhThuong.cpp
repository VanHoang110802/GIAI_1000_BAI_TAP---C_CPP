Viết hàm nhận vào một chuỗi và trả về chuỗi tương ứng (giữ nguyên chuỗi đầu vào):
- Các ký tự thành ký tự thường (giống strlwr).

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
char *BienDoiThanhThuong(char *s){
	// tạo bản sao cho chuỗi vì phải giữ nguyên đầu vào.
	char *p = strdup(s);
	strlwr(p);
	return p;
}

int main(){
	char s[] = "Hoang dep trai";
	char p[30];
	strcpy(p,BienDoiThanhThuong(s));	// gán chuỗi s sang cho p
	printf("\n%s",s);
	printf("\n%s",p);
	return 0;
}
