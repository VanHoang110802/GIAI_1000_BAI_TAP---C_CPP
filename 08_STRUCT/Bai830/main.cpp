/*

Hãy khai báo kiểu dữ liệu biểu diễn khái niệm đường tròn trong mặt phẳng Oxy và định nghĩa hàm nhập, hàm xuất cho kiểu dữ liệu này.

Đường tròn (C): H(11,08) với r = 2002, 
-> đường tròn tâm C có tọa độ x = 11, y = 8, có bán kính 2002.
-> (C): ((11,08),2002)
*/
#include <conio.h>
#include"DuongTron.h"

int main()
{
	while (_getch())
	{
		cout << "\n\n";
		DIEM d;
		DUONGTRON dt;
		NhapDuongTron(dt);
		XuatDuongTron(dt);
	}
	return 0;
}
