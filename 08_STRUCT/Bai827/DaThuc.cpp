#include "DaThuc.h"

void NhapDaThuc(DATHUC* dt)
{
	do
	{
		cout << "Nhap n = ";
		cin >> dt->n;
		if (dt->n < 1)
		{
			cout << "\nSo bac cua da thuc phai > 0. Xin kiem tra lai !\n";
		}
	} while (dt->n < 1);
	dt->a = new float[dt->n + 1];
	for (int i = 0; i <= dt->n; i++)
	{
		cout << "\nNhap vao he so thu " << i << " la: ";
		cin >> dt->a[i];
	}
}
void XuatDaThuc(DATHUC *dt)
{
	if (dt->n == 1)
	{
		cout << dt->a[0] << " + ";
		cout << dt->a[1] << "*x";
	}
	else
	{
		cout << dt->a[0] << " + ";
		cout << dt->a[1] << "*x ";
		for (int i = 2; i < dt->n; i++)
		{
			cout << dt->a[i] << "*x^" << i << " + ";
		}
		cout << dt->a[dt->n] << "*x^" << dt->n;
	}
}
