/*
Hãy khai báo kiểu dữ liệu biểu diễn khái niệm phân số trong toán học và định nghĩa hàm nhập,
hàm xuất cho kiểu dữ liệu này.

Một phân số bao gồm hai phần cơ bản là tử số và mẫu số. 
Tử số là một số tự nhiên được viết ngay bên trên dấu gạch ngang.
Mẫu số là một số tự nhiên luôn luôn khác 0 và được viết ngay bên dưới tử, 
phân cách với tử số bằng một dấu gạch ngang.
*/

#include"PhanSo.h"
int main()
{
	PHANSO ps1;
	NhapPS(ps1);
	XuatPS(ps1);
	return 0;
}
