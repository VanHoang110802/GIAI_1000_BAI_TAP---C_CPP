/*
Hãy khai báo kiểu dữ liệu biểu diễn khái niệm hỗn số trong toán học và định nghĩa hàm nhập, hàm xuất 
cho kiểu dữ liệu này.

- Hỗn số là kết quả của việc viết gọn tổng của một số tự nhiên nguyên dương với một phân số dương bằng 
cách bỏ dấu cộng xen giữa chúng. Như vậy, một hỗn số gồm hai phần: phần nguyên và phần phân số.
- Số đối của hỗn số này cũng được gọi là một hỗn số.
- Hỗn số được viết dưới dạng a(b/c) <-> a + (b/c). Phần phân số của hỗn số luôn luôn nhỏ hơn 1.
- Đổi một hỗn số sang một phân số: a(b/c) = (ac + b)/c
*/

#include"HonSo.h"

int main()
{
	HONSO hs;
	NhapHonSo(hs);
	XuatHonSo(hs);
	return 0;
}
