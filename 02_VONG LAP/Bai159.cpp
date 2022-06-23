Cho số nguyên không âm N. Hãy kiểm tra xem có tồn tại số nguyên không âm x sao cho x^3 = N hay không?
input: 2 8 4 27 1000	-> output: NO YES NO YES YES

#include <iostream>
#include<math.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    while (n-- != 0) {
        long long a;
        cin >> a;
        double c = pow(a, 1 / 3.0);
        long long lc = (long long)(c);
        if (lc * lc* lc == a || (lc + 1)* (lc + 1) * (lc + 1) == a) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

    }
    return 0;
}
