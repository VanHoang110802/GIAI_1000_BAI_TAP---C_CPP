#include "DanhSachMon.h"
void NhapDanhSachMon(DANHSACHMONHOC& ds)
{
	string n_hocphan;
	do
	{
		cout << "\nNhap vao so luong hoc phan: ";
		getline(cin, n_hocphan);
		bool check = KiemTraLaSo(n_hocphan);
		if (check == false)
		{
			cout << "\nKieu du lieu khong hop le. Xin kiem tra lai !";
		}
		else
		{
			ds.n = atoi((char*)n_hocphan.c_str());
			if (ds.n < 0)
			{
				cout << "\nSo hoc phan khong hop le! Xin kiem tra lai !\n";
			}

		}
	} while (KiemTraLaSo(n_hocphan) == false || ds.n < 0);

	// cấp phát bộ nhớ
	
	ds.arr = new MONHOC[ds.n];

	for (int i = 0; i < ds.n; i++)
	{
		cout << "\n-------- Nhap vao hoc phan thu " << i + 1 << " --------\n";
		NhapMonHoc(ds.arr[i]);
	}
}

void XuatDanhSachMon(DANHSACHMONHOC ds)
{
	for (int i = 0; i < ds.n; i++)
	{
		cout << "\n\t\t-------> Hoc phan thu " << i + 1 << " <-------\n";
		XuatMonHoc(ds.arr[i]);
	}
}
