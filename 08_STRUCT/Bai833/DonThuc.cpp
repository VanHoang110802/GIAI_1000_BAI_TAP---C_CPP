#include "DonThuc.h"

void NhapDonThuc(DONTHUC& dt)
{
	cout << "Nhap he so: ";
	cin >> dt.heso;
	cout << "Nhap bac cua don thuc: ";
	cin >> dt.somu;
}
void XuatDonThuc(DONTHUC dt)
{
	cout << dt.heso << "x^" << dt.somu;
}
DONTHUC TinhTong2DT(DONTHUC X, DONTHUC Y)
{
	DONTHUC A;
	A.heso = X.heso + Y.heso;
	A.somu = X.somu;	
	return A;
}
DONTHUC TinhHieu2DT(DONTHUC X, DONTHUC Y)
{
	DONTHUC A;
	A.heso = X.heso - Y.heso;
	A.somu = X.somu;
	return A;
}
DONTHUC TinhTich2DT(DONTHUC X, DONTHUC Y)
{
	DONTHUC D;
	D.heso = X.heso * Y.heso;
	D.somu = X.somu + Y.somu;
	return D;
}
DONTHUC TinhThuong2DT(DONTHUC X, DONTHUC Y)
{
	DONTHUC D;
	D.heso = X.heso / Y.heso;
	D.somu = X.somu - Y.somu;
	return D;
}
DONTHUC TimDaoHamDT(DONTHUC X)
{
	//a.x^n = n.a.x^n - 1
	DONTHUC C; // ta cứ coi như n = số mũ, a = hệ số
	C.heso = X.somu * X.heso;
	C.somu = X.somu - 1;
	return C;
}

DONTHUC TimDaoHamKDT(DONTHUC X, int k)
{
	while (k != 0)
	{
		X = TimDaoHamDT(X);
		k--;
	}
	return X;
}
double TinhGiaTriDonThuc(DONTHUC A, int x)
{
	return A.heso * pow((double)x, A.somu);
}

DONTHUC operator * (DONTHUC X, DONTHUC Y)
{
	DONTHUC D;
	D.heso = X.heso * Y.heso;
	D.somu = X.somu + Y.somu;
	return D;
}
DONTHUC operator / (DONTHUC X, DONTHUC Y)
{
	DONTHUC E;
	E.heso = X.heso / Y.heso;
	E.somu = X.somu - Y.somu;
	return E;
}
