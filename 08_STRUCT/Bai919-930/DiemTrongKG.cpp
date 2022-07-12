#include "DiemTrongKG.h"

void NhapDiem(diem& d)
{
	cout << "\nNhap x = ";
	cin >> d.x;
	cout << "\nNhap y = ";
	cin >> d.y;
}
void XuatDiem(diem d)
{
	cout << "<" << d.x << ", " << d.y << ">";
}
float TinhKhoangCachGiua2Diem(diem d1, diem d2)
{
	return sqrt(pow((d2.x - d1.x), 2) + pow((d2.y - d1.y), 2));
}
