#include "DiemTrongMP.h"
void NhapDiem(DIEM& d)
{
	cout << "Nhap x: ";
	cin >> d.x;
	cout << "Nhap y: ";
	cin >> d.y;
	cout << "Nhap z: ";
	cin >> d.z;
}
void XuatDiem(DIEM d)
{
	cout <<"\n" << "(" << d.x << "; " << d.y << "; " << d.z <<")\n";
}
