Bạn lại được ra 1 nhiệm vụ dễ dàng : Cho số nguyên n phân tích n thành thừa số nguyên tố.

Lưu ý: Kết quả gồm nhiều dòng mỗi dòng gồm 2 số nguyên dương. Số đầu tiên là thừa số nguyên tố p, số thứ hai là số mũ của p trong phân tích thừa số nguyên tố của n.
Chú ý cần sắp xếp các thừa số nguyên tố tăng dần theo thứ tự từ trên xuống.

input: 12	-> output: 2 2	
			   3 1

#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

void factorize(long long n) {
	int count = 0;

	while ((n % 2 == 0)) {
		n /= 2;
		count++;
	}
	if (count) cout << 2 << " " << count << endl;

	for (long long i = 3; i <= sqrt(n); i += 2) {
		count = 0;
		while (n % i == 0) {
			count++;
			n = n / i;
		}
		if (count)
			cout << i << " " << count << endl;
	}
	if (n > 2) cout << n << " " << 1 << endl;
}
int main() {
	long long N;
	cin >> N;
	clock_t start = clock(); //ghi lại thời gian lúc sau
	factorize(N);
	clock_t end = clock();
	double timerun = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "\n" << timerun << "s";
	return 0;
}
