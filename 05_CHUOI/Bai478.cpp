Viết chương trình đếm tần suất xuất hiện của tất cả các ký tự (không phân biệt hoa thường) có trong chuỗi s được nhập từ bàn phím. In ra kết quả theo thứ tự từ điển (Tần suất xuất hiện của các chữ số 0-9, sau đó là a-z).
Lưu ý: Chỉ đếm các ký tự thuộc bảng chữ cái tiếng anh (a-z, A-Z) và các chỗ số (0-9)
Không in các ký tự có tần suất bằng 0.
input: Lap Trinh Khong Kho!
-> output: 
a 1
g 1
h 3
i 1
k 2
l 1
n 2
o 2
p 1
r 1
t 1
/*
Đầu tiên ta đi xét chuỗi s, nếu trong chuỗi có 1 ký tự nào đó là 1 ký tự chữ hoa, thì ta sẽ biến đổi nó thành về dạnh kí tự chữ thường +=32, rồi sau đó, duyệt lại chuỗi 1 lần nữa, sau đó ta sẽ có 1 mảng phụ chỉ được phép chứa các kí tự thường và ký tự số, không được phép hoa, lưu hết tất cả các giá trị phần tử có trong chuỗi đó vào 1 mảng phụ khác, sau đó đi xét duyệt các phần tử ở mảng phụ đó, sắp xếp lại cái mảng đó theo thứ tự tăng dần (HOÁN VỊ CÁC PHẦN TỬ NHƯ MẢNG 1 CHIỀU ĐÓ, và lưu ý: phải bao gồm cả ký tự số trong đó, nếu không là xét thiếu trường hợp này).
Tiếp tục lại có thêm 1 vòng lặp cuối nữa, lại đi xét duyệt lại số lượng phần tử trong mảng phụ, nếu mà các phần tử trong mảng khác nhau thì ta mới xét, không thì bỏ qua, không quan tâm làm gì hết,rồi sau đó khởi tạo ra biến đêm, đi xét phần tử khác. Khi mà đã xác định được chúng khác nhau rồi, thì ta sẽ đem phần tử trong mảng phụ này, đối chiếu với các phần ở mảng ban đầu, nếu chúng bằng nhau thì đếm tăng lên, rồi cứ thế đi duyệt kiểm tra hết chuỗi thì thôi, thì dừng kết luận. 
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define Max 100
void HoanVi(char &a,char&b) {
	int temp = a;
	a = b;
	b = temp;
}
int main() {
	char s[Max], a[Max];
	int x = 0;	// khởi tạo biến của mảng phụ
	fgets(s, Max, stdin);
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += 32;
		}
	}
	for (int i = 0; i < strlen(s); i++) {
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
			a[x] = s[i];
			x++;
		}
	}
	//a[x] = '\0';
	//printf("%s", a);
	for (int i = 0; i < x; i++) {
		for (int j = i + 1; j < x; j++) {
			if (a[i] > a[j]) {
				HoanVi(a[i], a[j]);
			}
		}
		//printf("%c ", a[i]);
	}
	for (int i = 0; i < x; i++) {
		if (a[i] != a[i + 1]) {
			int dem = 0;
			for (int j = 0; j < strlen(s); j++) {
				if (a[i] == s[j]) {
					dem++;
				}
			}
			printf("%c %d\n", a[i], dem);
		}
	}
	return 0;
}
