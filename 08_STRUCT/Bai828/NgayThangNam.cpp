#include "NgayThangNam.h"

void NhapThoiGian(THOIGIAN& tg)
{
	do
	{
		cout << "\nNhap nam: ";
		cin >> tg.Year;
		if (tg.Year == 0)
		{
			cout << "\nNam phai khac 0, xin hay nhap lai!\n";
		}
	} while (tg.Year == 0);
		
	do
	{
		cout << "\nNhap thang: ";
		cin >> tg.Month;
		if (tg.Month < 1 || tg.Month > 12)
		{
			cout << "\nThang nhap khong hop le!\n";
		}
	} while (tg.Month < 1 || tg.Month > 12);

	vanhoang:
	cout << "\nNhap ngay: ";
	cin >> tg.Day;
	if (tg.Month == 1 || tg.Month == 3 || tg.Month == 7 || tg.Month == 8 || tg.Month == 10 || tg.Month == 12)
	{
		if ((tg.Day < 1 || tg.Day > 31))
		{
			cout << "\nNgay nhap khong hop le!\n";
			goto vanhoang;
		}
	}
	
	else if (tg.Month == 4 || tg.Month == 6 || tg.Month == 9 || tg.Month == 11)
	{
		if ((tg.Day < 1 || tg.Day > 30))
		{
			cout << "\Ngay nhap khong hop le!\n";
			goto vanhoang;
		}
	}
	else
	{
		if (((tg.Year % 4 == 0 && tg.Year % 100 != 0) || tg.Year % 400 == 0)  )
		{
			if (tg.Day < 1 || tg.Day > 29)
			{
				cout << "\Ngay nhap khong hop le!\n";
				goto vanhoang;
			}
			
		}
		else 
		{
			if (tg.Day < 1 || tg.Day > 28)
			{
				cout << "\Ngay nhap khong hop le!\n";
				goto vanhoang;
			}
		}
	}
}
void XuatThoiGian(THOIGIAN tg)
{
	if (tg.Year < 1)
	{
		tg.Year *= -1;
		cout << "Ngay/thang/nam: " << tg.Day << "/" << tg.Month << "/" << tg.Year << "(TCN)";
	}
	else
	{
		cout << "Ngay/thang/nam: " << tg.Day << "/" << tg.Month << "/" << tg.Year;
	}
}
