#include "Lop_Hoc.h"

void NhapLop(LOPHOC& lh)
{
	int luachon;
	do
	{
		cout << "\n---------------------- MENU ---------------------- \n";
		cout << "\n1. Nhap";
		cout << "\n2. Thoat";
		cout << "\n-------------------------------------------------- \n";

		cout << "\nNhap vao lua chon: ";
		cin >> luachon;
		
		if (luachon == 1)
		{
			SINHVIEN sv;
			NhapSinhVien(sv);
			lh.a.push_back(sv);
		}
	} while (luachon != 2);
	
}
void XuatLop(LOPHOC lh)
{
	int size = lh.a.size();
	for (int i = 0; i < size; ++i)
	{
		cout << "\nThong tin sinh vien thu " << i + 1 << " la\n";
		XuatSinhVien(lh.a[i]);
	}
}
float TimDTBMax(LOPHOC lh)
{
	float dtbMax = DiemTB(lh.a[0]);

	int size = lh.a.size();
	for (int i = 1; i < size; ++i)
	{
		float dtb = DiemTB(lh.a[i]);
		if (dtb > dtbMax)
		{
			dtbMax = dtb;
		}
	}
	return dtbMax;
}

void XuatThongTinCacSinhVienDTBMax(LOPHOC lh)
{
	float dtbmax = TimDTBMax(lh);
	int size = lh.a.size();

	for (int i = 0; i < size; ++i)
	{
		XuatSinhVien(lh.a[i]);
		cout << "\n\n";
	}
}
