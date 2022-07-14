Viết hàm nhận vào một chuỗi s và đếm xem có bao nhiêu từ trong chuỗi đó.
// từ là 1 hoặc 1 nhóm các kí tự khác khoảng trắng

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
int DemSoTu(char *s){
	int dem;
	if(s[0] == ' '){
		dem = 0;
	} else dem = 1;
	int length = strlen(s);
	for(int i =0;i<length - 1;i++){
		if(s[i] == ' ' && s[i+1] != ' '){
			dem++;				
		}
	}
	return dem;
}

int main(){
	char s[] = " Hoang  dep   trai";
	int sotu = DemSoTu(s);
	printf("\n%d",sotu);
	return 0;
}
