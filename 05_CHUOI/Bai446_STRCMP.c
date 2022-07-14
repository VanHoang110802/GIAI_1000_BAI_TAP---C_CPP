Hàm so sánh hai chuỗi 1: strcmp(s1, s2) -
+ So sánh hai chuỗi s1 và s2 (phân biệt hoa thường).
+ Hàm so sánh này thì cũng như mảng 1 chiều thôi, 1 là tượng trưng cho lớn hơn, 0 là bằng và -1 là bé hơn.
+ Nguyên tắc chạy của hàm này: So sánh từng kí tự của chuỗi s1 so với từng kí tự của s2 theo bảng mã ascii,nếu bằng nhau thì cứ xét ký tự kế bên, xét hết trong cái chuỗi, nếu ngay tại đó mà có 1 ký tự nào đó khác biệt(không bằng nhau về mã ascii ký tự) thì lập tức trả về kết luận so sánh luôn.
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
int main(){
	char s1[] = "hoang8c";
	char s2[] = "hoang8d";
	int kq = STRCMP(s1, s2);	// so sánh s1 vs s2
	printf("\n%d",kq);	// -> -1
	return 0;
}
