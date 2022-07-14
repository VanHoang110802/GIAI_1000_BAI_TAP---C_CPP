/*
	- Đổi thành số nguyên (atoi) -

- Bản chất, ta thấy nó luôn luôn bắt đầu là 1 con số, rồi lấy số đó nhân 10^x, x là số lượng số vừa nhập để đổi. Số đầu tiên = số đầu * lenght - 1
Làm sao để lấy được kí tự đầu là số? Ta biết rắng các kí tự trong chuỗi thì đều luôn luôn là 1 ký tự có chứa mã ascci, không lẽ lại đi lấy mã ascci đó đi tính ? Vậy ta sẽ phải đổi lại sang như sau (*): 
- Từ 1 ký tự số mà muốn chuyển sang số tương ứng thì lấy ký tự số đó - 48

s[0] = '1' => có mã ascii là 49 -> '1' = 49 - 48
s[1] = '2' => có mã ascii là 50 -> '2' = 50 - 48
s[2] = '3' => có mã ascii là 51 -> '3' = 51 - 48

- Từ 1 số nguyên mà muốn chuyển sang ký tự số tương ứng thì lấy số nguyên đó + 48
-> 1 + 48 = '1'
-> 2 + 48 = '2'

đổi thành số nguyên: "123" -> 123
		     "12345" -> 12345

ta thấy 123 = 1*100 + 2*10 + 3*1
ta thấy 12345 = 1*10^4 + 2*10^3 + 3*10^2 + 4*10^1 + 5*10^0
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
int main() {
	char s1[Max] = "12345";
	int n = ATOI(s1);
	printf("%d", n);
	return 0;
}
