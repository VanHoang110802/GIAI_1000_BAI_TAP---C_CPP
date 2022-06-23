Số tự nhiên N được gọi là số đẹp nếu cộng các chữ số của N lại ta có một số mà kết thúc bằng 9.
Ví dụ một số số đẹp là 18 (1+8 = 9) , 234 (2+3+4 = 9) , 658 ( 6+5+8 = 19).
Cho một số N, hãy kiểm tra xem N có phải là số đẹp hay không.
input: 27	-> output: YES
input: 658 	-> output:YES
input: 111	-> output: NO

#include <iostream>
using namespace std;
int n, sum;
int main() {
	cin >> n;
	while (n > 0) {
		sum = sum + n % 10;
		n /= 10;
	}
	if (sum % 10 == 9) cout << "YES";
	else cout << "NO";
	return 0;
}
