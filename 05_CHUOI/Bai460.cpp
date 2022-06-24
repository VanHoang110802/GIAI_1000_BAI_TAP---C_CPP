Chuẩn hóa chuỗi (xóa khoảng trắng thừa).

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
void XoaKyTu(char *s, int vitrixoa){
	int length = strlen(s);
	for(int i= vitrixoa + 1; i< length;i++){
		s[i-1] = s[i];
	}
	s[length -1] = '\0';									
}
char *ChuanHoaChuoi(char *s){
	// tạo bản sao cho chuỗi vì phải giữ nguyên đầu vào.
	char *p = strdup(s);
	int length = strlen(p);
	for(int i= 0; i< length;i++){
		if(p[i] == ' ' && p[i+1] == ' '){
			XoaKyTu(p,i);
			i--;
			length--;	// mỗi lần phải xóa xong phải cập nhật lại( do bên mảng nó sẽ chạy theo n, còn ở đây chạy theo length nên ta phải cập nhật lại cho nó).
		}
	}
	if(p[0] == ' '){
		XoaKyTu(p,0);
		length--;
	}
	if(p[length - 1] == ' '){
		XoaKyTu(p,length - 1);
	}
	return p;
}

int main(){
	char s[] = " Hoang  dep   trai";
	char p[30];
	strcpy(p, ChuanHoaChuoi(s));	// gán chuỗi s sang cho p
	printf("\n%s",s);
	printf("\n%s",p);
	//XoaKyTu(s,0);
	//printf("\n%s",s);
	return 0;
}
