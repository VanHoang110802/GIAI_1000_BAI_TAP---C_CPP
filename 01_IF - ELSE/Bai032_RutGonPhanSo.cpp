Cho tử số a và mẫu số b của 1 phân số là các số nguyên, bạn cần viết 1 chương trình rút gọn phân số trên.
Phân số tối giản sau khi đã rút gọn:
Nếu phân số được yêu cầu không hợp lệ, in ra INVALID
Nếu giá trị của phân số là một số nguyên, in ra số nguyên đó
Trường hợp khác, in ra tử số và mẫu số của phân số tối giản cách nhau 1 dấu cách
​input: 4 -8	-> output: -1 2

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
/*
* TH1: mẫu = 0 và 1
* TH2: mẫu âm
* TH3: mẫu tử đều âm
* TH4: số test ngoài phạm vi
* TH5: tử chia hết cho mẫu
*/
int main() {
	int a, b,ucln;
	cin >> a >> b;
	if (b == 0) {
		cout << "INVALID";
		return 0;
	}
	if (a % b == 0) {
		cout << a / b;
		return 0;
	}
	// dùng hàm hỗ trợ tìm ucln: _gcd() trong thư viện #include<algorithm>
	ucln = abs(__gcd(a, b)); // Tránh TH UCLN ra số âm
	if (b < 0) { //  mẫu âm thì chuyển dấu âm lên trên tử, khử mẫu âm ở dưới
		a /= -1 * ucln;
		b /= -1 * ucln;
		cout << a << " " << b;
	}
	else {
		a /= ucln;
		b /= ucln;
		cout << a<< " " << b;
	}
	return 0;
}
