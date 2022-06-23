Ta định nghĩa trung bình cộng của ba số nguyên x1,x2,x3 là (x1+x2+x3)/3.
Cho ba số nguyên a, b và x. Hãy tìm số nguyên c sao cho trung bình cộng của ba số a, b, c đúng bằng x.
(1<= a,b,x <= 100).

#include<iostream>
using namespace std;
int main() {
	int a, b, x;
	cin >> a >> b >> x;
	cout << x * 3 - a - b;
	return 0;
}
