Đổi tất cả các kí tự có trong chuỗi thành chữ thường (không dùng hàm strlwr).
/*
Ta có độ dài chuỗi,sau đó duyệt từng phần tử trong chuỗi, đổi hết các phần tử sang kí tự thường +=32
*/
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
void DoiCacKyTuTrongChuoiSangThuong(char*s){
	int length = STRLEN(s);
	for(int i=0;i<length;i++){
		if(s[i] >= 'A' && s[i]<='Z'){
			s[i]+=32;
		}
	}
}
int main(){
	char s[] = "HoanG DEp TrAi";
	DoiCacKyTuTrongChuoiSangThuong(s);
	printf("\nS = %s", s);	// -> hoang dep trai
	return 0;
}
