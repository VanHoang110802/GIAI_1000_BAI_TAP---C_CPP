Hàm đảo ngược chuỗi: strrev(s) - 
Đảo ngược thứ tự các ký tự trong chuỗi s (trừ ký tự kết thúc chuỗi).
(làm bài số đối xứng cực kì dễ luôn á :D).
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
void HoanVi(char &x, char &y){
	char temp = x;
	x = y;
	y = temp;
}
void STRREV(char *s){
	int length = STRLEN(s);
	for(int i=0;i<length / 2;i++){
		HoanVi(s[i], s[length-1-i]);
	}
}
int main(){
	char s[] = "Hoang Dep Trai";
	STRREV(s);
	printf("\nS = %s", s);	// -> iarT peD gnaoH
	return 0;
}
