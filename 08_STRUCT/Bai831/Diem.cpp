#include "Diem.h"

void NhapDiem(DIEM& d)
{
	cout << "\nNhap x : ";
	cin >> d.x ;

	cout << "\nNhap y: ";
	cin >> d.y;
}

void XuatDiem(DIEM d)
{
	cout << "(" << d.x<< ", " << d.y << ")";
}
