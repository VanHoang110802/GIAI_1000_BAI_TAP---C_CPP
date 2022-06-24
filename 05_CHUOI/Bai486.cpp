Cho xâu ký tự s chỉ gồm các chữ cái latin và chữ số. Ta gọi một số trong xâu s là một dãy các ký tự số liên tiếp (có thể bắt đầu bằng ký tự số '0'). Hãy đếm số lượng số xuất hiện trong xâu s.
input: A0123b345 	-> output: 2
/*
Ta xét 1 chuỗi, đem đi duyệt cái chuỗi đó, duyệt từ phần tử đầu tiên đến khi gặp 1 phần tử nào đó là 1 ký tự chữ cái A-Z, a-z thì kết thúc 1 chuỗi và đếm tăng lên 1(dem++), hoặc nếu có trường hợp phần tử đầu là 1 khoảng trắng hay 1 kí tự khác số, hoặc là 1 phần tử nào đó trong chuỗi khác phần tử đầu cũng là 1 kí tự nào đó khác kí tự số, thì bỏ qua luôn, đi xét phần tử kế nó, cũng như vậy, xét từng phần từ kế tiếp cho đến khi gặp '\0' hoặc 1 ký tự khác số thì biến đếm lại tăng lên, sau cùng duyệt hết chuỗi rồi thì kết luận có bao nhiêu số lượng số xuất hiện là xong thôi.  
*/
#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int dem(0);  //tương tự như int dem = 0;
	for (int i=0; i<s.length(); ++i) {
		if (((s[i]<='Z' && s[i]>='A') || (s[i]<='z' && s[i]>='a')) && (s[i+1]<='9' && s[i+1]>='0')) ++dem;
	}
	if (s[0]<='9' && s[0]>='0') ++dem;
	cout << dem;
	return 0;
}
