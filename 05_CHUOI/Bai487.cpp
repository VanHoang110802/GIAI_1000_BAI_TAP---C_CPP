Viết chương trình tìm số đảo ngược của 1 số nguyên dương n nhập từ bàn phím.In ra số nguyên dương đảo ngược của số n
input: 1234 	-> ouput: 4321
intput: 1320	->output: 231
/*
Các hàm cần: (gọi s là string)
Đảo string: reverse(s.begin(), s.end());
Xóa kí tự trong string: s.erase(vị trí kí tự, số kí tự);
Bài này có cả những trường hợp những số 0 phía sau nữa. Ví dụ: 14230000 -> 3241
Do đó, phải dùng while để bỏ những số 0 đi. Tại sao lại là while?
While sẽ xuất khi điều kiện vẫn còn đúng, và nó sẽ tiếp tục vòng lặp cho tới khi điều kiện đó sai.
Còn If sẽ xuất ra ngay khi điều kiện đó đúng.
Sau đó chỉ cần dùng if cho trường hợp '-'(là số âm).
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    while(s[0]=='0') s.erase(0, 1);
    if (s[s.size()-1]=='-') s.erase(s.size()-1, 1);
 	cout<<s;   
	return 0;
}
