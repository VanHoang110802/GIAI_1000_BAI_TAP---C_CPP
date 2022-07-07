/*
Hãy khai báo kiểu dữ liệu để biểu diễn khái niệm đa thức một biến trong toán học 
𝑎.𝑛𝑥^𝑛 + 𝑎.𝑛−1𝑥^𝑛−1 + ⋯ + 𝑎1𝑥 + 𝑎0 và định nghĩa hàm nhập và hàm xuất cho kiểu dữ liệu này.

Đa thức một biến là tổng của những đơn thức của cùng một biến.
• Một số được coi là một đơn thức một biến.
• Bậc của đa thức một biến (khác đa thức không, đã thu gọn) là số mũ lớn nhất của biến trong đa thức đó.

Ví dụ: 5x^5 + 4x^3 - 2x^2 + x là đa thức một biến (biến x); bậc của đa thức là 5.
*/

#include"DaThuc.h"

int main()
{
	DATHUC* dt = new DATHUC;

	NhapDaThuc(dt);
	XuatDaThuc(dt);
	delete dt;
	return 0;
}
