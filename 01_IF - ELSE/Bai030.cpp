Cho 3 số nguyên a,b,c. (1 <= a, b, c <= 100000). Sắp xếp 3 số a,b,c theo thứ tự từ lớn đến bé.

#include <iostream>
using namespace std;
int main() {
	int a, b,c,d;
	cin >> a >> b >> c;
    
	if ((a >= b) && (a >= c))
	{
		if (b > c) cout << a << " " << b << " " << c;
		else cout << a << " " << c << " " << b ;
        return 0;
	}
	else if ((b >= a) && (b >=c))
	{
		if (a > c) cout << b << " " << a << " " << c;
		else cout << b << " " << c << " " << a;
        return 0;
	}
	else if ((c >= a) && (c >= b))
	{
		if (a > b) cout << c << " " << a << " " << b;
		else cout << c << " " << b << " " << a ;
        return 0;
	} 
}
