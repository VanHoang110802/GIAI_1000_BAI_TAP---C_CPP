#include "PhanSo.h"
void NhapPS(PHANSO& ps)
{
	cout << "\nNhap vao tu so: ";
	cin >> ps.tuso;

	do
	{
		cout << "Nhap vao mau so: ";
		cin >> ps.mauso;

		if (ps.mauso == 0)
		{
			cout << "\nMau so khong hop le! Xin hay kiem tra lai!\n";
		}
	} while (ps.mauso == 0);
}
void XuatPS(PHANSO ps)
{
	cout << ps.tuso << "/" << ps.mauso;
}
