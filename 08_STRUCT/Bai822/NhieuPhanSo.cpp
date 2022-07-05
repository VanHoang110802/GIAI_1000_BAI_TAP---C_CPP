#include "NhieuPhanSo.h"
istream& operator >> (istream& is, PHANSO& ps)
{
	cout << "\nNhap vao tu so: ";
	is >> ps.tuso;

	do
	{
		cout << "Nhap vao mau so: ";
		is >> ps.mauso;

		if (ps.mauso == 0)
		{
			cout << "\nMau so khong hop le! Xin hay kiem tra lai!\n";
		}
	} while (ps.mauso == 0);
	return is;
}
ostream& operator << (ostream& os, PHANSO ps)
{
	os << ps.tuso << "/" << ps.mauso;
	return os;
}
