/*
Cho số nguyên n phân tích n thành tích các thừa số nguyên tố.

Dữ liệu vào
Gồm duy nhất số nguyên dương 2≤n≤10^18

Dữ liệu ra
Gồm nhiều dòng mỗi dòng gồm 2 số nguyên dương. Số đầu tiên là thừa số nguyên tố p, số thứ hai là số mũ của p trong thừa số nguyên tố của n.

Chú ý: Cần sắp xếp các thừa số nguyên tố tăng dần theo thứ tự từ trên xuống.
input: 12 -> output: 2 2 
                     3 1
* Lưu ý: timerun chạy chỉ chấp nhận <= 1s
*/
#include <iostream>
#include <math.h>
#include<stdlib.h>
using namespace std;
int main() 
{
    int N = 40000000;
   
    bool* isPrime = new bool[N + 1];
    
    for (int i = 0; i <= N; ++i) 
    {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= N; ++i) 
    {
        if (isPrime[i] == true) 
        {
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }
    long long x;
    cin >> x;
    bool flag = false;
    for (int i = 2; i <= N; ++i) 
    {
        if (isPrime[i])
        {
            int cnt = 0;
            while (x % i == 0)
            {
                cnt++;
                x /= i;
            }
            if (cnt != 0) 
            {
                flag = true;
                cout << i << " " << cnt << endl;
            }
        }
    }
    if (x != 1) 
    {
        long long p = sqrt(x);
        if (p * p == x) 
        {
            cout << p << " 2";
        }
        else 
        {
            cout << x << " 1";
        }
    }
    delete[] isPrime;
    return 0;
}
