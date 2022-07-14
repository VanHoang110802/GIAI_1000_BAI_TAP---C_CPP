Viết chương trình nhập hai số thực . Sau đó hỏi phép tính cần thực hiện và in kết quả của phép tính đó .
  Nếu là “+” , in kết quả của tổng lên màn hình .
  Nếu là “-” , in kết quả của hiệu lên màn hình .
  Nếu là “/” , in kết quả của thương lên màn hình .
  Nếu là “*” , in kết quả của tích lên màn hình .  Nếu là “+” , in kết quả của tổng lên màn hình .
  Nếu là “+” , in kết quả của tổng lên màn hình .

#include <iostream>
using namespace std;
int main() {
    int a, b;
    char luachon;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
   
    cout << "\nbam cac phim +, -, *, / de thuc hien phep tinh ! \nBan muon lam gi voi bieu thuc nay: ";
    
    cin >> luachon;

    if (luachon == '+') {
        cout << "Tong cua a + b = " <<  a + b;
        return 0;
    }
    else if (luachon == '-') {
        cout << "Hieu cua a - b = " << a - b;
        return 0;
    }
    else if (luachon == '*') {
        cout << "Tich cua a * b = " << a * b;
        return 0;
    }
    else if (luachon == '/') {
        cout << "Thuong cua a / b = " << (float)a / b;
        return 0;
    }
    return 0;
}
