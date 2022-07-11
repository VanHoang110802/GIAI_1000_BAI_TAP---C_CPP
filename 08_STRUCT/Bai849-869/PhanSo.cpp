#include "PhanSo.h"
void NhapPhanSo(PHANSO& ps)
{
	cout << "\nNhap vao tu so: ";
	cin >> ps.TuSo;

	do
	{
		cout << "Nhap vao mau so: ";
		cin >> ps.MauSo;
		if (ps.MauSo == 0)
		{
			cout << "\nMau so khong hop le,xin hay kiem tra lai!\n";
		}
	} while (ps.MauSo == 0);
}
void XuatPhanSo(PHANSO ps)
{
	cout << ps.TuSo << "/" << ps.MauSo;
}
float TimUCLN(float a, float b)
{
	if (a < 0)
	{
		a = a * -1;
	}
	if (b < 0)
	{
		b = b * -1;
	}

	if (a == 0 && b != 0)
	{
		return b;
	}
	else if (b == 0 && a != 0)
	{
		return a;
	}

	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
			b = b - a;
	}
	return a;
}
PHANSO RutGonPhanSo(PHANSO a)
{
	float UCLN = TimUCLN(a.TuSo, a.MauSo);
	a.TuSo = a.TuSo / UCLN;
	a.MauSo = a.MauSo / UCLN;
	return a;
}
PHANSO TinhTong(PHANSO ps1, PHANSO ps2)
{
	PHANSO temp, x;	// phân số tạm
	temp.TuSo = ps1.TuSo * ps2.MauSo + ps2.TuSo * ps1.MauSo;
	temp.MauSo = ps1.MauSo * ps2.MauSo;
	x = RutGonPhanSo(temp);
	return x;
}
PHANSO TinhHieu(PHANSO ps1, PHANSO ps2)
{
	PHANSO temp, x;	// phân số tạm
	temp.TuSo = ps1.TuSo * ps2.MauSo - ps2.TuSo * ps1.MauSo;
	temp.MauSo = ps1.MauSo * ps2.MauSo;
	x = RutGonPhanSo(temp);
	return x;
}
PHANSO TinhTich(PHANSO ps1, PHANSO ps2)
{
	PHANSO temp, x;
	temp.TuSo = ps1.TuSo * ps2.TuSo;
	temp.MauSo = ps1.MauSo * ps2.MauSo;
	x = RutGonPhanSo(temp);
	return x;
}
PHANSO TinhThuong(PHANSO ps1, PHANSO ps2)
{
	PHANSO temp, x;
	temp.TuSo = ps1.TuSo * ps2.MauSo;
	temp.MauSo = ps1.MauSo * ps2.TuSo;
	x = RutGonPhanSo(temp);
	return x;
}
int KiemTraPSToiGian(PHANSO ps)
{
	PHANSO temp;
	temp = RutGonPhanSo(ps);
	if (temp.TuSo == ps.TuSo && temp.MauSo == ps.MauSo)
	{
		return 1;
	}
	return 0;
}
void QuyDong2PS(PHANSO&ps1, PHANSO &ps2)
{
	PHANSO temp;	// như kiểu hoán vị a, b vậy
	temp.TuSo = ps1.TuSo;
	temp.MauSo = ps1.MauSo;

	ps1.TuSo *= ps2.MauSo;
	ps1.MauSo *= ps2.MauSo;

	ps2.TuSo *= temp.MauSo;
	ps2.MauSo *= temp.MauSo;
}
int KTPSDuong(PHANSO ps)
{
	if (ps.TuSo > -1 && ps.MauSo > -1)
	{
		return 1;
	}
	return 0;
}
int KTPSAm(PHANSO ps)
{
	if (ps.TuSo < 1 || ps.MauSo < 1)
	{
		return 1;
	}
	return 0;
}
int SoSanh2PS(PHANSO ps1, PHANSO ps2)
{
	float kq1, kq2;
	kq1 = ps1.TuSo / ps1.MauSo;
	kq2 = ps2.TuSo / ps2.MauSo;
	if (kq1 < kq2)
	{
		return -1;
	}
	if (kq1 > kq2)
	{
		return 1;
	}
	return 0;
}

PHANSO operator + (PHANSO ps1, PHANSO ps2)
{
	PHANSO temp;	// phân số tạm
	temp.TuSo = ps1.TuSo * ps2.MauSo + ps2.TuSo * ps1.MauSo;
	temp.MauSo = ps1.MauSo * ps2.MauSo;
	RutGonPhanSo(temp);
	return temp;
}
PHANSO operator - (PHANSO ps1, PHANSO ps2)
{
	PHANSO temp;	// phân số tạm
	temp.TuSo = ps1.TuSo * ps2.MauSo - ps2.TuSo * ps1.MauSo;
	temp.MauSo = ps1.MauSo * ps2.MauSo;
	RutGonPhanSo(temp);
	return temp;
}
PHANSO operator * (PHANSO ps1, PHANSO ps2)
{
	PHANSO temp;
	temp.TuSo = ps1.TuSo * ps2.TuSo;
	temp.MauSo = ps1.MauSo * ps2.MauSo;
	RutGonPhanSo(temp);
	return temp;
}
PHANSO operator / (PHANSO ps1, PHANSO ps2)
{
	PHANSO temp;
	temp.TuSo = ps1.TuSo * ps2.MauSo;
	temp.MauSo = ps1.MauSo * ps2.TuSo;
	RutGonPhanSo(temp);
	return temp;
}
PHANSO operator ++ (PHANSO& ps)
{
	ps.TuSo += ps.MauSo;
	return ps;
}
PHANSO operator -- (PHANSO& ps)
{
	ps.TuSo += ps.MauSo;
	return ps;
}
