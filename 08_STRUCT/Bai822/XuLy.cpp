#include "XuLy.h"
int TimUCLN(int a, int b)
{
	// chi xet khi a != b, a = b return luon
	// xet truong hop con truoc: hoac a= 0 hoac b = 0:
	if (a == 0 && b != 0)
	{
		return b;
	}
	if (b == 0 && a != 0)
	{
		return a;
	}
	if (a < 0)
	{
		a *= -1;
	}
	if (b < 0)
	{
		b *= -1;
	}
	while (a != b)
	{
		if (a > b)
		{
			a -= b;
		}
		else
		{
			b -= a;
		}
	}
	return a; // or b cung ok
}

void RutGonPS(PHANSO& ps)
{
	// tu va mau se chia cho ucln cua no
	int ucln = TimUCLN(ps.tuso, ps.mauso);

	ps.tuso /= ucln;
	ps.mauso /= ucln;
}
PHANSO operator+(PHANSO ps1, PHANSO ps2)
{
	//	a/b + c/d = (a*d + b*c)/(b*d)

	PHANSO temp;
	temp.tuso = ps1.tuso * ps2.mauso + ps2.tuso * ps1.mauso;
	temp.mauso = ps1.mauso * ps2.mauso;
	return temp;
}
PHANSO operator+(PHANSO ps1, int songuyen)
{
	//	a/b + x 

	PHANSO ps2;
	ps2.tuso = songuyen;
	ps2.mauso = 1;
	return ps1 + ps2;
}
PHANSO operator+(int songuyen, PHANSO ps1)
{
	//	 x + a/b 
	return ps1 + songuyen;
}

PHANSO operator-(PHANSO ps1, PHANSO ps2)
{
	//	a/b - c/d = (a*d - b*c)/(b*d)

	PHANSO temp;
	temp.tuso = ps1.tuso * ps2.mauso - ps2.tuso * ps1.mauso;
	temp.mauso = ps1.mauso * ps2.mauso;
	return temp;
}
PHANSO operator*(PHANSO ps1, PHANSO ps2)
{
	//	a/b * c/d = a*b/c*d

	PHANSO temp;
	temp.tuso = ps1.tuso * ps2.tuso;
	temp.mauso = ps1.mauso * ps2.mauso;
	return temp;
}
PHANSO operator/(PHANSO ps1, PHANSO ps2)
{
	//	a/b - c/d = a*d/b*c

	PHANSO temp;	// ps dao
	// dao lai ps2
	temp.tuso = ps2.mauso;
	temp.mauso = ps2.tuso;

	return ps1 * temp;
}
