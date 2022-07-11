#include "Diem.h"
void NhapDiem(DIEM& d)
{
	printf("\nNhap x =  ");
	cin >> d.x;

	printf("\nNhap y: ");
	cin >> d.y;
}
void XuatDiem(DIEM d)
{
	cout << "(" << d.x << ", " << d.y << ")";
}
float TinhKhoangCachGiua2Diem(DIEM d1, DIEM d2)
{
	return sqrt(pow((d2.x - d1.x), 2) + pow((d2.y - d1.y), 2));
}
float TinhKhoangCachGiua2DiemTheoOx(DIEM d1, DIEM d2)
{
	return fabs(d1.x - d2.x);
}
float TinhKhoangCachGiua2DiemTheoOy(DIEM d1, DIEM d2)
{
	return fabs(d1.y - d2.y);
}
DIEM TimDiemDoiXungQuaO(DIEM d)
{
	DIEM temp;
	temp.x = -1.0 * d.x;
	temp.y = -1.0 * d.y;
	return temp;
}
DIEM TimDiemDoiXungQuaOx(DIEM d)
{
	DIEM temp;
	temp.x = d.x;
	temp.y = -1.0 * d.y;
	return temp;
}
DIEM TimDiemDoiXungQuaOy(DIEM d)
{
	DIEM temp;
	temp.x = -1.0 * d.x;
	temp.y = d.y;
	return temp;
}
DIEM TimDiemDoiXungQuaPhanGiacI(DIEM d)
{
	DIEM temp;
	temp.x = d.y;
	temp.y = d.x;
	return temp;
}
DIEM TimDiemDoiXungQuaPhanGiacII(DIEM d)
{
	DIEM temp;
	temp.x = -1.0 * d.y;
	temp.y = -1.0 * d.x;
	return temp;
}
int KiemTraDiemThuocPhanTuI(DIEM d)
{
	if (d.x > 0 && d.y > 0) return 1;
	return 0;
}
int KiemTraDiemThuocPhanTuII(DIEM d)
{
	if (d.x < 0 && d.y > 0) return 1;
	return 0;
}
int KiemTraDiemThuocPhanTuIII(DIEM d)
{
	if (d.x < 0 && d.y < 0) return 1;
	return 0;
}
int KiemTraDiemThuocPhanTuIV(DIEM d)
{
	if (d.x > 0 && d.y < 0) return 1;
	return 0;
}
