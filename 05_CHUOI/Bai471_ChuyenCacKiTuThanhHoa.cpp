Đổi tất cả các kí tự trong chuỗi sang chữ in hoa (không dùng hàm struppr).
/*
Tương tự bài trên nhưng -= 32 để đổi thành hoa
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
void DoiCacKyTuTrongChuoiSangHoa(char*s){
	int length = STRLEN(s);
	for(int i=0;i<length;i++){
		if(s[i] >= 'a' && s[i]<='z'){
			s[i]-=32;
		}
	}
}
int main(){
	char s[] = "hoang deo dep trai ";
	DoiCacKyTuTrongChuoiSangHoa(s);
	printf("\nS = %s", s);	
	return 0;
}
