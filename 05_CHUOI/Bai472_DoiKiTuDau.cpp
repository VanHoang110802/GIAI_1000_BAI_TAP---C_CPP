Viết chương trình đổi những kí tự đầu tiên của mỗi từ thành chữ in hoa.
/*
Ta xét vị trí trước đó của kí tự đầu tiên, nếu trước đó mà là 1 khoảng trắng thì ta sẽ biến đổi kí tự đó thành hoa, còn không thì vẫn giữ nguyên (nếu trước đó là 1
khoảng trắng và tiếp theo sau là 1 cái gì đó khác khoảng trắng thì đó là ký tự đầu tiên của 1 từ)
 - Nếu đầu tiên của chuỗi không phải là khoảng trắng thì sẽ bị lỗi
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
char* BienDoiKyTuDauThanhHoa(char *s){
	// tạo bản sao cho chuỗi vì phải giữ nguyên đầu vào.
	char *p = strdup(s);

	int length = strlen(p);
	if(p[0] != ' '){
		if(p[0] >= 'a' && p[0] <='z'){
			p[0] -= 32;
		}
	}
	for(int i=0;i<length;i++){
		if(p[i] == ' ' && p[i+1] != ' '){
			if(p[i+1] >= 'a' && p[i+1]<='z'){
				p[i+1] -= 32;
			}
		}
	}
	return p;
}
int main(){
	char s[] = "hoang dep trai";
	char p[30];
	strcpy(p, BienDoiKyTuDauThanhHoa(s));	// gán chuỗi s sang cho p
	printf("\n%s",s);
	printf("\n%s",p);
	return 0;
}
