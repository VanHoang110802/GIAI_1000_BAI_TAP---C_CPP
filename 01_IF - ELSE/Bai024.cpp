Cho một kí tự in thường (a đến z), bạn hãy in ra kí tự đứng liền sau nó trong bảng chữ cái tiếng Anh.
Lưu ý sau z là a.
Input: d	->Output: e

#include<iostream>
using namespace std;
int main(){
    char c;
    cin>>c;
    if(c>=97&&c<122){
        c++;
    } else if(c== 122) c= 97;
    else cout << " ";
    cout<< c;
    return 0;
}
