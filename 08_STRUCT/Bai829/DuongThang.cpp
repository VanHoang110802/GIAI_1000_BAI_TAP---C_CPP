#include "DuongThang.h"
void NhapDuongThang(DUONGTHANG& dt)
{
	cout << "Nhap a = ";
	cin >> dt.a;
	cout << "Nhap b = ";
	cin >> dt.b;
	cout << "Nhap c = ";
	cin >> dt.c;
}
void XuatDuongThang(DUONGTHANG dt)
{
	cout << "(d): ";
	if ((dt.a == 1 || dt.b == 1 || dt.c == 1 ) && (dt.a != 0 &&  dt.b != 0&& dt.c != 0))
	{
		if (dt.a == 1 && (dt.b != 1 && dt.c != 1))
		{
			cout << "x + " << dt.b << "y + " << dt.c << " = 0";
		}
		else if (dt.b == 1 && (dt.a != 1 && dt.c != 1))
		{
			cout << dt.a << "x + " << "y + " << dt.c << " = 0";
		}
		else if (dt.a == 1 && dt.b == 1)
		{
			cout << "x + " << "y + " << dt.c << " = 0";
		}
	}
	else if ((dt.a == 0 || dt.b == 0 || dt.c == 0) && (dt.a != -1 && dt.b != -1 && dt.c != -1))
	{
		if (dt.a == 0 && (dt.b != 0 && dt.c != 0))
		{
			if (dt.b == 1)
			{
				cout << "y + " << dt.c << " = 0";
			}
			else cout << dt.b << "y + " << dt.c << " = 0";
			
		}
		else if (dt.b == 0 && (dt.a != 0 && dt.c != 0))
		{
			if (dt.a == 1)
			{
				cout << "x + " << dt.c << " = 0";
			}
			else cout << dt.a << "x + " << dt.c << " = 0";
		}
		else if ((dt.a == 0 && dt.b == 0))
		{
			cout << dt.c;
		}
		else if ((dt.b == 0 && dt.c == 0))
		{
			cout << dt.a;
		}
		else if ((dt.a == 0 && dt.c == 0))
		{
			cout << dt.b;
		}
		else
		{
			cout << dt.a << "x + " << dt.b << "y = 0";
		}
	}
	else if (dt.a == -1 || dt.b == -1 || dt.c == -1)
	{
		if (dt.a == -1 && (dt.b != 0 && dt.b != -1))
		{
			cout << "-x + " << dt.b << "y + " << dt.c << " = 0";
		}
		else if (dt.b == -1 &&(dt.a != 0 && dt.a != -1))
		{
			cout << dt.a << "x - "<< "y + " << dt.c << " = 0";
		}
		else if (dt.a == -1 && dt.b == 0)
		{
			cout << "-x + " << dt.c << " = 0";
		}
		else if (dt.b == -1 && dt.a == 0)
		{
			cout << "-y + " << dt.c << " = 0";
		}
		else if (dt.a == -1 && dt.b == -1)
		{
			cout << "-x " << "- y + " << dt.c << " = 0";
		}
		else if ((dt.a == -1 && dt.b != 1))
		{
			cout << "-x " << "+ y + " << dt.c << " = 0";
		}
		else if ((dt.a != -1 && dt.b == -1))
		{
			cout << "x " << "- y + " << dt.c << " = 0";
		}
	}
	else cout << dt.a << "x + "<< dt.b << "y + " << dt.c << " = 0";
}
