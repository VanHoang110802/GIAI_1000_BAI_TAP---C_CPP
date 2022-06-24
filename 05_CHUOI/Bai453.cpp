itoa, ltoa, ultoa: đổi số thành chuỗi.
/*
	- muốn dùng được hàm này thì nhớ cài #include <stdlib.h>
	- đổi số thành chuỗi (tất cả đều là số nguyên hết) -
itoa(int): value, buffer<vùng nhớ>, hệ cơ số đổi<2|8|10|16>
ltoa(long)
ultoa(unsigned long)
tại sao chỉ có số nguyên mà không có số thực? -> các hàm này chỉ đổi được số nguyên thôi, làm gì có số nào số thực đổi được sang nhị phân(hay bát phân, thập lục phân...), nhìn mã ascci có số thực nào đâu :D.

250 đổi sang các hệ

* hệ 2 *
250 : 2 = 125 dư 0
125 : 2 = 62 dư 1
62 : 2 = 31 dư 0
31 : 2 = 15 dư 1
15 : 2 = 7 dư 1
7 : 2 = 3 dư 1
3 : 2 = 1 dư 1
1 : 2 = 0 dư 1
phần nguyên còn 0 => dừng lại
=> đọc ngược lên các giá trị dư sẽ là: 11111010

* hệ 8 *
250 : 8 = 31 dư 2
31 : 8 = 3 dư 7
3 : 8 = 0 dư 3
=> 0 thì dừng lại
=> đọc ngược lại là 372

* hệ 16 *
250 : 16 = 15 dư 10
15 : 16 = 0 dư 15
=> 0 thì dừng lại
-> đọc ngược lên nhưng theo quy tắc sau
nếu là 10 => A, 11 => B, 12 => C, 13 => D, 14 => E, 15 => F
=> FA

*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#define Max 110

int STRLEN(char *s){
	int dem =0;
	while(s[dem]!='\0'){
		dem++;
	}
	return dem;
}
void HoanVi(char &a, char &b){
	char temp = a;
	a = b; 
	b = temp;
}

void STRREV(char *s){
	int length = STRLEN(s);
	for(int i = 0; i < length / 2; i++){
		HoanVi(s[i], s[length - 1 - i]);
	}
}
void ITOA(int number, char *vungnho, int coso){	// hàm chuyển đổi từ kí tự của hệ cơ số 10 -> các hệ khác bất kì
	int idx = 0;
	while(number != 0){
		int ketqua = number % coso;
		number /= coso; 	// cập nhật lại number

		if(ketqua < 10) {	// THÌ LÀ 1 SỐ NGUYÊN
			vungnho[idx++] = ketqua + 48; 	// ĐỔI SỐ NGUYÊN SANG KÝ TỰ TƯƠNG ỨNG
		}
		else if(ketqua == 10){
			vungnho[idx++] = 'A';
		}
		else if(ketqua == 11){
			vungnho[idx++] = 'B';
		}
		else if(ketqua == 12){
			vungnho[idx++] = 'C';
		}
		else if(ketqua == 13){
			vungnho[idx++] = 'D';
		}
		else if(ketqua == 14){
			vungnho[idx++] = 'E';
		}
		else if(ketqua == 15){
			vungnho[idx++] = 'F';
		}
	}
	vungnho[idx] = '\0'; 	// Phải nhớ kết thúc chuỗi
	STRREV(vungnho); 	// đảo ngược chuỗi lại
}

int main() {
	int n = 250;
	char vungnho[Max];
	ITOA(n,vungnho,2);
	printf("%s", vungnho);
	return 0;
}
