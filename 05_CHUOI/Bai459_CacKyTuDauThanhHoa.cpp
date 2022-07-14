Các ký tự đầu tiên mỗi từ thành ký tự hoa.
/*
- Biến đổi làm sao để tìm ra được 1 ký tự đầu tiên của 1 từ? Nếu trước đó là 1 khoảng trắng và tiếp theo sau là 1 kí tự gì đó khác khoảng trắng thì đó là ký tự đầu tiên của 1 từ.
- Đầu tiên ta sẽ đi xét vị trí đầu tiên của chuỗi, sẽ có 2 trường hợp:
	+ TH1: Không có khoảng trắng ở vị trí đầu ở chuỗi: ta đi kiểm tra nếu phần tử đầu mà là kí tự thường thì theo mã ascii thì -= 32, nếu là kí tự hoa thì thôi khỏi xét, sau đó duyệt từ vị trí từ sau đó đến hết, nếu tại vị trí nào đó có khoảng trắng thì kí tự kế nó sẽ -= 32 đổi thành hoa (vì trước đó là 1 khoảng trắng và tiếp theo sau là 1 kí tự gì đó khác khoảng trắng thì đó thì có nghĩa đã kết thúc 1 từ rồi), còn khác thì nếu có kí tự theo mã ascii là kí tự chữ hoa ta += 32 biến đổi nó thành thường.
	
	+ TH2: Có khoảng trắng ở vị trí ở đầu chuỗi: nếu tại vị trí nào đó có khoảng trắng thì kí tự kế nó sẽ -= 32 đổi thành hoa (vì trước đó là 1 khoảng trắng và tiếp theo sau là 1 kí tự gì đó khác khoảng trắng thì đó thì có nghĩa đã kết thúc 1 từ rồi), còn khác thì nếu có kí tự theo mã ascii là kí tự chữ hoa ta += 32 biến đổi nó thành thường.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define Max 100

char* DoiCacKiTuKhacThanhThuong(char* s) {
	char* p = _strdup(s);
	int length = strlen(p);
	if (p[0] != ' ') {	// nếu phần tử đầu không bắt đầu là 1 khoảng trắng
		if (p[0] >= 'a' && p[0] <= 'z') {
			p[0] -= 32;
		}
		for (int i = 0; i < length; i++) {
			if (p[i] == ' ') {	// nếu phần tử đang xét là khoảng trắng thì phần tử kế sẽ đổi thành hoa
				if (p[i + 1] >= 'a' && p[i + 1] <= 'z') {
					p[i + 1] -= 32;
				}
			}
			if (p[i] != ' ') {	// nếu phần tử đang xét khác khoảng trắng thì phần tử kế sẽ đổi thành thường
				if (p[i + 1] >= 'A' && p[i + 1] <= 'Z') {
					p[i + 1] += 32;
				}
			}
		}
		return p;
	}
	else {	// nếu phần tử đầu bắt đầu là 1 khoảng trắng
		for (int i = 0; i < length; i++) {
			if (p[i] == ' ') {	// nếu phần tử đang xét là khoảng trắng thì phần tử kế sẽ đổi thành hoa
				if (p[i + 1] >= 'a' && p[i + 1] <= 'z') {
					p[i + 1] -= 32;
				}
			}
			if (p[i] != ' ') {	// nếu phần tử đang xét khác khoảng trắng thì phần tử kế sẽ đổi thành thường
				if (p[i + 1] >= 'A' && p[i + 1] <= 'Z') {
					p[i + 1] += 32;
				}
			}
		}
		return p;
	}
}
int main() {
	char s[] = "trUonG vAN hOAnG";
	char p[Max];
	strcpy(p, DoiCacKiTuKhacThanhThuong(s));
	printf("%s", p);
	return 0;
}
