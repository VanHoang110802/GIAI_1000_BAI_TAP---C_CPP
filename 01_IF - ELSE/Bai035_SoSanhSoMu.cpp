Cho 3 số nguyên a,b và c. Hãy so sánh a^c và b^c
Nếu a^c > b^c, in ra >
Nếu a^c < b^c, in ra <
Nếu a^c = b^c, in ra =
input: 2 3 4	-> output: < (2^4 < 3^4)
input: 1 1 1	-> output: = (1 = 1)

#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (c % 2 == 0)
	{
		if (a < 0)
			a = -a;
		if (b < 0)
			b = -b;
	}
	if (c == 0) cout << "=" << endl;
	else if (a < b) cout << "<" << endl;
	else if (a > b) cout << ">" << endl;
	else cout << "=" << endl;
	return 0;
}
