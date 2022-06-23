John có 1 số thập phân x nhưng vì yêu thích những chữ số nguyên nên John quyết định làm tròn nó thành số nguyên.(−10000 <= x <= 10000)
Nhiệm vụ của bạn là tìm ra 2 số nguyên trong đó:
1 số sẽ là số nguyên lớn nhất nhưng bé hơn hoặc bằng x
1 số sẽ là số nguyên nhỏ nhất nhưng lớn hơn x
input: -5.23	->output: -6 -5
intput: 98.222	->output: 98 99

#include<iostream>
using namespace std;
int main()
{
	double n;
	cin >> n;
	if (n < 0){
		cout << (int)n - 1 << " " << (int)n;
	} else{
		cout << (int)n << " " << (int)n + 1;
	}
	return 0;
}
