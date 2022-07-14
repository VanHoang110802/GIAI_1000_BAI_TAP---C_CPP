Tèo có một con Robot đồ chơi rất thông minh, nó rất hứng thú với bộ đồ chơi chữ cái của Tèo.
Tèo cho Robot chơi trò chơi như sau: Tèo xếp các chữ cái trong bộ đồ chơi của mình thành một hàng dọc, Robot sẽ đi từ đầu hàng đến cuối hàng, mỗi khi đi đến một chữ 
cái, nếu Robot chưa nhặt được loại chữ cái đó thì nó sẽ nhặt, nếu đã nhặt rồi thì nó bỏ qua.
Cho biết hàng chữ cái Tèo xếp ban đầu, bạn hãy cho biết xâu chữ cái (theo đúng thứ tự) mà Robot sẽ nhặt
input: ABABACD -> output: ABCD
/*
Ta sẽ khởi tạo chuỗi x ban đầu chưa có gì, vì chuỗi là mảng 1 chiều các kí tự nên ta sẽ gán chuỗi x nhận vào là 1 phần tử đầu tiên của chuỗi s vừa nhập(s[0]), 
sau đó ta sẽ đi duyệt cả 2 chuỗi, khởi tạo biến check = 0, xét xem nếu phần tử của chuỗi này giống chuỗi kia hay không( kiểm tra xem phần tử đã nhập đó tồn tại hay 
chưa?), 
nếu giống thì check vẫn = 0, rồi bỏ qua, không in gì hết, còn nếu check = 1, có nghĩa là khác thì thêm vào chuỗi x rồi in ra phần tử đó rồi cứ thế duyệt cho đến khi 
hết chuỗi thì thôi, thì ngừng, rồi đi kết luận.
*/

#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	getline(cin, s);
	string x="";	// khởi tạo chuỗi x ban đầu chưa có gì
	// vì chuỗi là mảng 1 chiều các kí tự nên ta sẽ:
	x += s[0];
	cout<<s[0];
	for (int i = 1; i < s.length(); i++) {
		int check = 1;
		for (int j = 0; j < x.length(); j++) {
			if (s[i] == x[j]) {
				check = 0;
			}
		}
		if (check == 1) {
			x += s[i];
			cout<<endl<<s[i]; //in ra các phần tử phân biệt
		}
	}
	cout <<endl<< x;
	return 0;
}
