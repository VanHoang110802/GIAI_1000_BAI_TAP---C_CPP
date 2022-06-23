Viết chương trình nhập vào một số nguyên không âm n (0 <= n < 86400). Đó là giây hiện tại của một ngày. Hãy chuyển đổi giây đó sang dạng giờ, phút, giây.
input: 61	-> output: 00:01:01

#include <iostream>
#include<cstdio>
using namespace std;
int main() {
	unsigned int n;
	cin >> n;
	unsigned int gio = 0, phut = 0, giay = n;
	check:
	if (giay < 60) {
		printf("%02d:%02d:%02d", gio, phut, giay);
	}
	else {
		phut++;
		giay -= 60;
		if (phut >= 60) {
			gio++;
			phut -= 60;
		}
		goto check;
	}
	return 0;
}
