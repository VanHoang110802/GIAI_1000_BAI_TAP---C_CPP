#include "MonHoc.h"
bool KiemTraLaSo(string chuoi)
{
	// Kiểm tra xem chuỗi có phải là số thực ?
	int length = chuoi.length();
	if (length == 0)
	{
		return false;
	}
	int dem = 0;
	for (int i = 0; i < length; i++)
	{
		if ((chuoi[i] < '0' || chuoi[i] > '9') && chuoi[i] != '.')
		{
			return false;
		}
		if (chuoi[i] == '.')
		{
			dem++;
			if (dem == 2)
			{
				return false;
			}
		}
		if (chuoi[i] == '.' && length == 1)
		{
			return false;
		}
	}
	return true;
}
void NhapMonHoc(MONHOC& mh)
{
	cout << "\nNhap vao ten hoc phan: ";
	getline(cin, mh.TenMon);

	string diem, so_tinchi;
	// điểm phải nằm trong đoạn 0 --> 10
	do
	{
		cout << "\nNhap vao so diem cua hoc phan: ";
		getline(cin, diem);
		bool Check = KiemTraLaSo(diem);

		if (Check == false)
		{
			cout << "\nKieu du lieu khong hop le. Xin kiem tra lai !";
		}
		else
		{
			mh.SoDiem = atof((char*)diem.c_str());
			if (mh.SoDiem < 0 || mh.SoDiem > 10)
			{
				cout << "\nSo diem khong hop le. Xin kiem tra lai !\n";
			}
		}
	} while (KiemTraLaSo(diem) == false || (mh.SoDiem < 0 || mh.SoDiem > 10));

	do {
		cout << "\nNhap vao so chi cua hoc phan: ";
		
		getline(cin , so_tinchi);

		bool Check = KiemTraLaSo(so_tinchi);

		if (Check == false)
		{
			cout << "\nKieu du lieu khong hop le. Xin kiem tra lai !";
		}
		else
		{
			mh.SoChi = atoi((char*)so_tinchi.c_str());
			if (mh.SoChi < 0)
			{
				cout << "\nSo tin chi khong hop le. Xin kiem tra lai !\n";
			}
			if (mh.SoChi == 0)
			{
				mh.SoChi = 1;
			}
		}
	} while (KiemTraLaSo(so_tinchi) == false|| (mh.SoChi < 0));
}

void XuatMonHoc(MONHOC mh)
{
	cout << "\n\t\t\tTen hoc phan: " << mh.TenMon;
	cout << "\n\t\t\tDiem thi: " << mh.SoDiem;
	cout << "\n\t\t\tSo chi: " << mh.SoChi;
}
