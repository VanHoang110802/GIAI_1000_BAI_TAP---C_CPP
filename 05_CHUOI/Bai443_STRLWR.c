Hàm chuyển thành chuỗi thường: strlwr(s) - 
+ Chuyển chuỗi s thành chuỗi thường ('A' thành 'a', 'B' thành 'b', …, 'Z' thành 'z')

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
int main(){
	char s[] = "Hoang Dep Trai";
	STRLWR(s);
	printf("\nS = %s", s);	// -> hoang dep trai
	return 0;
}
