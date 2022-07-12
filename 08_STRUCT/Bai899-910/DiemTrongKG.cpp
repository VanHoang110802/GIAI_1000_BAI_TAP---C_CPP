#include "DiemTrongKG.h"

void NhapDiem(diem& d)
{
	cout << "\nNhap x = ";
	cin >> d.x;
	cout << "\nNhap y = ";
	cin >> d.y;
	cout << "\nNhap z = ";
	cin >> d.z;
}
void XuatDiem(diem d)
{
	cout << "(" << d.x << ", " << d.y << ", " << d.z << ")";
}
float TinhKhoangCachGiua2Diem(diem d1, diem d2)
{
	return sqrt(pow((d2.x - d1.x), 2) + pow((d2.y - d1.y), 2) + pow((d2.z - d1.z), 2));
}
float TinhKhoangCachGiua2DiemTheoOx(diem d1, diem d2)
{
	return fabs(d1.x - d2.x);
}
float TinhKhoangCachGiua2DiemTheoOy(diem d1, diem d2)
{
	return fabs(d1.y - d2.y);
}
float TinhKhoangCachGiua2DiemTheoOz(diem d1, diem d2)
{
	return fabs(d1.z - d2.z);
}
diem TimDiemDoiXungQuaO(diem d)
{
	diem temp;
	temp.x = -1 * d.x;
	temp.y = -1 * d.y;
	temp.z = -1 * d.z;
	return temp;
}
diem TimDiemDoiXungQuaOxy(diem d)
{
	diem temp;
	temp.x = 1 * d.x;
	temp.y = 1 * d.y;
	temp.z = -1 * d.z;
	return temp;
}
diem TimDiemDoiXungQuaOxz(diem d)
{
	diem temp;
	temp.x = 1 * d.x;
	temp.y = -1 * d.y;
	temp.z = 1 * d.z;
	return temp;
}
diem TimDiemDoiXungQuaOyz(diem d)
{
	diem temp;
	temp.x = -1 * d.x;
	temp.y = 1 * d.y;
	temp.z = 1 * d.z;
	return temp;
}
