#include "DuongTron.h"

void NhapDuongTron(DUONGTRON& dt)
{
	
	NhapDiem(dt.I);
	cout << "\nNhap ban kinh: ";
	cin >> dt.r;
	do

	{
		cout << "\nNhap ten duong tron (Vi du: (C), (D),... ): ";
		cin >> dt.tentamdt;
		if (dt.tentamdt < 65 || dt.tentamdt > 122)
		{
			cout << "\nTen duong tron khong hop le!";
		}
	} while (dt.tentamdt < 65 || dt.tentamdt > 122);
}

void XuatDuongTron(DUONGTRON dt)
{
	cout << "Duong tron(" << dt.tentamdt << "): ";
	cout << "((" << dt.I.x << ", " << dt.I.y <<"),"<< dt.r <<  ")";
}
