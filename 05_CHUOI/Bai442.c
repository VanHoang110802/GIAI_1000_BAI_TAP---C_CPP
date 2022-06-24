Hàm tạo bản sao chuỗi: strdup(s) - 
+ Tạo bản sao của một chuỗi s cho trước. Hàm sẽ tự tạo vùng nhớ dài strlen(s) + 1 (bytes) để chứa chuỗi s. Phải tự hủy vùng nhớ này khi không sử dụng nữa (vì vùng nhớ được cấp ngẫu nhiên, không biết nằm đâu hết).
// Lưu ý: bên C++ không có hàm này.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define Max 50

int STRLEN(char *s){
	int dem =0;
	while(s[dem]!='\0'){
		dem++;
	}
	return dem;
}
void STRCPY(char *s1, char *s2){
	int lengths2 = STRLEN(s2);
	for(int i =0;i<lengths2;i++){
		s1[i] = s2[i];
	}
	s1[lengths2] = '\0';
}
char *STRDUP(char *s){	// thuộc phần bài con trỏ nên chỉ làm tham khảo thôi.
	int length = STRLEN(s);
	char *p = (char *)malloc(length+1);
	STRCPY(p,s);
	return p;
}

int main(){
	char s1[] = "Hoang";
	char *s2 = STRDUP(s1);
	printf("\nS2 = %s", s2);
	free(s2);
	return 0;
}
