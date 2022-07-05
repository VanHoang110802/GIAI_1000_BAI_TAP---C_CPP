#include "DonThuc.h"
void NhapDonThuc(DONTHUC& dt)
{
	cout << "Nhap he so: ";
	cin >> dt.a;
	cout << "Nhap bac cua don thuc: ";
	cin >> dt.n;
}
void XuatDonThuc(DONTHUC dt)
{
	cout <<"\n" << dt.a << "x^" << dt.n <<"\n";
}
