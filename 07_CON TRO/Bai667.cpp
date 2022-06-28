/*
Demo con trỏ vô kiểu.
*/

#include <iostream>
using namespace std;

int main()
{
	int x = 1108;
	float y = 2002;
	char c = 'A';

	// Con trỏ void đọc là con trỏ vô kiểu. Nó có thể trỏ đến bất cứ ô nhớ kiểu nào. Nhưng khi lấy ra giá trị nó trỏ đến
	// thì ta phải ép kiểu.
	void* p;
	p = &x;
	cout<<*((int*)p); // 1

	p = &y;
	cout<<endl<<*((float*)p);

	p = &c;
	cout<<endl<<*((char*)p);
  
	return 0;
}
