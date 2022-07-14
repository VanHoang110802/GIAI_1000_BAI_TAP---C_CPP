Hàm nối hai chuỗi: strcat(s1, s2) -
+ Nối chuỗi s2 vào sau chuỗi s1. Chuỗi s1 phải đủ chứa kết quả
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
void STRCAT(char *s1, char *s2){
	int length_s1 = STRLEN(s1);
	int length_s2 = STRLEN(s2);
	for(int i=0;i<length_s2;i++){
		s1[length_s1++] = s2[i];
	}
	s1[length_s1] = '\0'; // tránh lỗi khi không có kết thúc chuỗi.
}
int main() {
	char s1[Max] = "hoang8D";
	char s2[Max] = "hoang8d";
	STRCAT(s1, s2);	// nối ten2 vào ten
	printf("\n%s", s1);	// -> hoang8Dhoang8d
	return 0;
}
