#include "SinhVien.h"

void NhapSinhVien(SINHVIEN& sv)
{
	cout << "\nNhap vao ho ten: ";
	getline(cin,sv.Ten);
	cout << "\nNhap danh sach hoc phan: ";
	NhapDanhSachMon(sv.danhsachmon);
}

void XuatSinhVien(SINHVIEN sv)
{
	cout << "\nMa so: " << sv.MaSo;
	cout << "\nHo & ten: " << sv.Ten;
	cout << "\n";
	XuatDanhSachMon(sv.danhsachmon);
	if (sv.danhsachmon.n > 0)
	{
		cout << "\n\t\t\tDiem trung binh la: " << TinhDiemTrungBinh(sv);
		cout << "\n\n\t\t---> XEP LOAI: " << XepLoai(sv) << " <---\n\n";
	}
	else
	{
		cout << "\n\t\t\tDiem trung binh la: 0";
		cout << "\n\n\t\t---> XEP LOAI: KEM <---\n\n";
	}
}

float TinhDiemTrungBinh(SINHVIEN sv)
{
	float TongDiem = 0;
	int TongChi = 0;
	for (int i = 0; i < sv.danhsachmon.n; i++)
	{
		TongDiem += (sv.danhsachmon.arr[i].SoDiem * sv.danhsachmon.arr[i].SoChi);
		TongChi += sv.danhsachmon.arr[i].SoChi;
	}
	return TongDiem / TongChi;
}

string XepLoai(SINHVIEN sv)
{
	float Dtb = TinhDiemTrungBinh(sv);

	if (Dtb < 2)
	{
		return "KEM";
	}

	if (Dtb < 5)
	{
		return "YEU";
	}

	if (Dtb < 6.5)
	{
		return "TRUNG BINH";
	}

	if (Dtb < 8)
	{
		return "KHA";
	}

	if (Dtb < 9)
	{
		return "GIOI";
	}
	return "XUAT SAC";
}

// Kiểm tra 1 đối tượng sinh viên có bị rớt ít nhất 1 môn hay không ?
// rớt thì trả về 1, không rớt trả về 0
int KiemTraBiRotMon(SINHVIEN sv)
{
	// đi vào danh sách các môn học của sinh viên
	for (int i = 0; i < sv.danhsachmon.n; i++)
	{
		// Kiểm tra từng môn xem nếu điểm thi < 5 => return 1 (rớt môn)
		if (sv.danhsachmon.arr[i].SoDiem < 5)
		{
			return 1;
		}
	}
	return 0;
}
