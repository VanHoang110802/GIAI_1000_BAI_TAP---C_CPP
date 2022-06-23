Cho tử số a và mẫu số b của 1 phân số là các số nguyên, bạn cần viết 1 chương trình rút gọn phân số a/b về phân số tối giản.
Phân số tối giản sau khi đã rút gọn:
Nếu phân số được yêu cầu không hợp lệ, in raINVALID
Nếu giá trị của phân số là một số nguyên, in ra số nguyên đó
Trường hợp khác, in ra tử số và mẫu số của phân số tối giản cách nhau 1 dấu cách
input: 4 -8		-> output: -1 2

//------------ CÁCH 1: --------------
#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a, b, ucln;
    cin >> a >> b;
    if (b == 0)
    {
        cout << "INVALID";
        return 0;
    }
    if (a % b == 0)
    {
        cout << (int(a / b));
        return 0;
    }
    ucln = abs(__gcd(a, b)); // Tranh TH UCLN ra so am
    /*
	 Library: 'algorithm'
    __gcd(m, n)
    Parameter :  m, n
    Return Value :  0 if both m and n are zero,
    else gcd of m and n.
    */
    if (b < 0)
    { 
        a /= -1 * ucln;
        b /= -1 * ucln;
        cout << (int(a)) << " " << int(b);
    }
    else {
        a /= ucln;
        b /= ucln;
        cout << (int(a)) << " " << int(b);
    }
    return 0;
}

// ------------ CÁCH 2: ------------------
// Cho tử số a và mẫu số b của 1 phân số là các số nguyên, bạn cần viết 1 chương trình rút gọn phân số a/b về phân số tối giản.
#include<iostream>
using namespace std;

int UCLN(int m, int n) {
    if (m == 0 || n == 0)
        return m + n;
    else {
        if (m > 0 && n > 0)
            while (m != n) {
                if (m > n)
                    m -= n;
                else
                    n -= m;
            }
        else {
            if (m < 0)
                m *= -1;
            if (n < 0)
                n *= -1;
            while (m != n) {
                if (m > n)
                    m -= n;
                else
                    n -= m;
            }
        }
    }
    return m;
}

int main() {
    int a, b;
    cin >> a >> b;
    if (b == 0)
        cout << "INVALID";
    else if (a % b == 0)
        cout << a / b;
    else if (a < 0 && b < 0)
        cout << (a / UCLN(a, b)) * (-1) << " " << (b / UCLN(a, b)) * (-1);
    else
        cout << a / UCLN(a, b) << " " << b / UCLN(a, b);
    return 0;
}
