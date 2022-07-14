Hàm so sánh hai chuỗi 2: stricmp(s1, s2) -
So sánh hai chuỗi s1 và s2 (không phân biệt hoa thường).
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
void STRLWR(char*s){
	int length = STRLEN(s);
	for(int i=0;i<length;i++){
		if(s[i] >= 'A' && s[i]<='Z'){
			s[i]+=32;
		}
	}
}
void STRUPR(char*s){
	int length = STRLEN(s);
	for(int i=0;i<length;i++){
		if(s[i] >= 'a' && s[i]<='z'){
			s[i]-=32;
		}
	}
}
int STRCMP(char *s1, char *s2){
	int min = STRLEN(s1) < STRLEN(s2) ? STRLEN(s1) : STRLEN(s2);
	int i;
	for(i=0;i<min;i++){
		if(s1[i] < s2[i]){
			return -1;
		} else if(s1[i] < s2[i]){
			return 1;
		}
	}
	if(s1[i] =='\0'){
		if(s2[i] =='\0'){
			return 0;
		} else return -1;
	}
	if(s2[i] =='\0'){
		if(s1[i] == '\0'){
			return 0;
		} else return 1;
	}
}
int STRICMP(char *s1, char *s2){
	// biến cả 2 chuỗi thành hoặc là chữ hoa hoặc là chữ thường hết
	STRLWR(s1); STRLWR(s2);
	return STRCMP(s1,s2);
}
int main() {
	char s1[] = "hoang8D";
	char s2[] = "hoang8d";
	int kq = STRICMP(s1, s2);	// so sánh ten vs ten2
	printf("\n%d", kq);	// -> 0
	return 0;
}
