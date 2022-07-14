Bé Na rất thích học tiếng Anh. Một hôm, trong lúc đọc một đoạn văn tiếng Anh, Bé Na muốn biết đoạn văn mà mình phải đọc có bao nhiêu từ, bạn hãy lập một chương trình trình giúp bạn Na làm việc này nhé.
Cho một đoạn văn bản là một xâu ký tự chỉ gồm các chữ cái trong bảng chữ cái la-tinh (‘A’…’Z’, ‘a’…’z’) và các dấu cách (‘ ‘). Mỗi từ là một dãy chữ cái liên tiếp không chứa dấu cách. Hai từ được phân cách bởi một hoặc nhiều dấu cách. Hãy đếm xem đoạn văn đó có bao nhiêu từ.
input: Thank you very much for your letter which arrived a few days ago		-> output: 13
	Thank    you    very    much		-> output: 4
/*
từ là 1 hoặc 1 nhóm các kí tự khác khoảng trắng
Đi duyệt các phần tử trong mảng, nếu phần tử đầu khác khoảng trắng và phần tử sau là 1 khoảng trắng hoặc nếu phần tử đầu khác khoảng trắng và phần tử sau là 1 phần tử cuối cùng của chuỗi thì đếm tăng lên
*/
#include <iostream>
#include<string>
using namespace std;
string s;
int main() {
	int dem = 0;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		// nếu phần tử đầu khác khoảng trắng và phần tử sau là 1 khoảng trắng hoặc phần tử sau là 1 phần tử cuối cùng của chuỗi thì đếm tăng lên
		if ((s[i] != ' ' && s[i + 1] == ' ') || (s[i] != ' ' && i == s.size() - 1)) dem++;
	}
	cout << dem;
	return 0;
}
