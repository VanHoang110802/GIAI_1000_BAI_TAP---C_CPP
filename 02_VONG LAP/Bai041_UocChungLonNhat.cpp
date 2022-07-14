Cho 2 số nguyên a và b, viết chương trình tìm ước chung lớn nhất của a và b
input: 2 4 	-> output: 2
input: 0 43 	-> output: 43
input: -2 -10 	-> output: 2

#include<iostream>
#include<math.h>
using namespace std;
int main() {
    long a, b;
    cin >> a >> b;
    long temp1 = abs(a);    // biến phụ lưu gia trị tuyệt đối lại
    long temp2 = abs(b);
    if (a == 0) { 
        cout << b; 
        return 0; 
    }
    if (b == 0) {
        cout << a; 
        return 0; 
    }
    for (int i = temp1; i >= 1; i--)
    {
        for (int j = temp2; j >= 1; j--) {
            if (temp1 % i == 0 && temp2 % j == 0 && i == j) {
                cout << j;
                return 0;
            }
        }
    }
    return 0;
}
