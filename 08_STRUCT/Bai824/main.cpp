/*
Hãy khai báo kiểu dữ liệu biểu diễn khái niệm điểm trong mặt phẳng Oxy và định nghĩa hàm nhập,
hàm xuất cho kiểu dữ liệu này.

Giả sử ta có x, y.
Mỗi 1 cặp số x, y sẽ xác định 1 điểm <-> mỗi điểm M sẽ có 1 cặp số x, y xác định.
Cặp số (x;y) là tọa độ của điểm M, x là hoành độ, y là tung độ của điểm M.
Điểm M có tọa độ (x;y) kí hiệu là M(x;y).

*/

#include"DiemTrongMP.h"

int main()
{
	DIEM d;
	NhapDiem(d);
	XuatDiem(d);
	return 0;
}
