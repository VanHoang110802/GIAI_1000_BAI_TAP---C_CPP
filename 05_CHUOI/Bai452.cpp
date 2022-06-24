/*
	- Đổi thành số thực (atof, atol) -
"12.34" -> 12.34
"-12.34" -> -12.34
- bỏ dấu "." thành 1234, dùng lại cái hàm ở trên đổi thành 1234, ta thấy sau dấu "." có 2 chữ số -> 1234 / 10^2 = 12.34
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define Max 110
int STRLEN(char *s){
	int dem =0;
	while(s[dem]!='\0'){
		dem++;
	}
	return dem;
}
int ATOI(char *s1){
	int length = STRLEN(s1);
	int i = 0;	// nếu là số 0 thì không thể khởi tạo i=0 ở dưới vòng lặp được được, vì nếu có cả số âm nữa thì có nghĩa là chỉ tính xét từ số dương >= 0 thôi, không xét được số âm
	
	int temp = length - 1;
	if(s1[0] == '-'){
		i = 1;
		temp -= 1;	// nếu là số âm thì độ dài phải - 1 do tính cả dấu âm.
	}
	
	int number = 0;
	
	for(;i<length;i++){	// chưa biết số đầu người dùng nhập âm hay dương
		number += (s1[i] - 48) *pow(10.0, temp--);
	}
	if(s1[0] == '-'){
		return -number;
	}
	return number;
}
float ATOF(char *s){
	char a[Max];
	int length = STRLEN(s);
	int idx = 0, k;
	for(int i=0;i<length;i++){
		if(s[i] != '.'){
			a[idx++] = s[i];
		}
		else k = i;	// lưu lại vi trí của dấu '.'
	}
	a[idx] = '\0';
	int soluong = length - 1 - k;
	return ATOI(a) / pow(10.0, soluong);
}
int main() {
	char s1[Max] = "-12.345";
	float n = ATOF(s1);
	printf("%f", n);
	return 0;
}
