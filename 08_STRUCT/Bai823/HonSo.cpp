#include "HonSo.h"
void NhapHonSo(HONSO& hs)
{
	cout << "Nhap phan nguyen: ";
	cin >> hs.phannguyen;
	cout << "Nhap tu so: ";
	cin >> hs.tuso;
	do
	{
		cout << "Nhap mau so: ";
		cin >> hs.mauso;
		if (hs.mauso == 0)
		{
			cout << "\nMau khong duoc bang 0, xin kiem tra lai!\n";
		}
	} while (hs.mauso == 0);
}
void XuatHonSo(HONSO hs)
{
	cout <<"\n"<< hs.phannguyen << "(" << hs.tuso << "/" << hs.mauso << ")\n";
}
