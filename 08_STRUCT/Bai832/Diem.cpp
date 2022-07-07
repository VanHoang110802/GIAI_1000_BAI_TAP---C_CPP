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

float TinhKhoangCach(DIEM A, DIEM B)
{
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
