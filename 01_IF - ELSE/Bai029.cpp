Viết chương trình làm tròn số thực n nhập từ bàn phím về số nguyên gần nhất (chênh lệch giá trị nhỏ nhất, n <= 10^6).
vd: 5.5 -> 6, -100.299 -> 100
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	double n;
	cin >> n;
	cout << round(n) ;
	return 0;
}
