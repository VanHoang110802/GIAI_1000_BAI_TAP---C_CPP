#include "DiemTrongMP.h"
void NhapDiem(DIEM& d)
{
	cout << "Nhap x: ";
	cin >> d.x;
	cout << "Nhap y: ";
	cin >> d.y;
}
void XuatDiem(DIEM d)
{
	cout <<"\n" << "(" << d.x << "; " << d.y << ")\n";
}
