Hàm chuyển thành chuỗi HOA: strupr(s) -
Chuyển chuỗi s thành chuỗi IN ('a' thành 'A', 'b' thành 'B', …, 'z' thành 'Z')
// Lưu ý: bên C++ không có hàm này.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#define Max 50

int STRLEN(char *s){
	int dem =0;
	while(s[dem]!='\0'){
		dem++;
	}
	return dem;
}
void STRUPR(char*s){
	int length = STRLEN(s);
	for(int i=0;i<length;i++){
		if(s[i] >= 'a' && s[i]<='z'){
			s[i]-=32;
		}
	}
}
int main(){
	char s[] = "Hoang Dep Trai";
	STRUPR(s);
	printf("\nS = %s", s);	// -> HOANG DEP TRAI
	return 0;
}
