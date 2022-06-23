Hoà vừa tạo ra 1 hệ điều hành mới có tên gọi là hoafOS. Nhưng hệ điều hành của cậu ta chưa được hoàn thiện và mắc một số lỗi về thời gian. Giờ đây khi muốn thay đôi thời gian, Hòa phải nhập theo cú pháp:
users setClock \monthmonth\datedate\yearyear
Bạn hãy giúp Hòa viết một chương trình tự động sinh ra câu lệnh này theo thời gian tùy ý nhé.
intput: 21 11 2000	-> output: users setClock \11\21\2000

#include <iostream>
using namespace std;
int main() {
	int date, month, year;
	cin >> date >> month >> year;
    	char c = 92;
	cout << "users setClock " << c << month << c << date << c << year;
	return 0;
}
