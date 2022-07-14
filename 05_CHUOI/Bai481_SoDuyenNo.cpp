Con số duyên nợ là con số có chữ số đầu và chữ số cuối giống nhau.
Viết chương trình kiểm tra xem một số nguyên dương n ghi trong hệ thập phân có chữ số đầu và chữ số cuối giống nhau không?
input: 12345	-> output: NO
	123541		    YES
/*
Cách đơn giản nhanh gọn lẹ: ta sẽ đi xác định kích thước, số lượng phần tử của mảng, rồi đem đi so sánh với phần tử đầu, nếu giống nhau thì kết luận luôn, còn không thì thôi.
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
    	cout << (s[0] == s[s.size() - 1] ? "YES\n" : "NO\n");  //nếu phần tử đầu mà bằng với phần từ cuối
    }
    return 0;
}
