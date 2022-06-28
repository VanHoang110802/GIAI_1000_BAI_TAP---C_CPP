#include "Sinh_Vien.h"

void NhapSinhVien(SINHVIEN &sv)
{
	fflush(stdin);
	cout << "\nNhap vao ma so: ";
	getline(cin, sv.maso);
	fflush(stdin);
	cout << "\nNhap vao ho ten: ";
	getline(cin, sv.hoten);

	cout << "\nNhap ngay sinh: ";
	NhapNgay(sv.ngaysinh);

	cout << "\nNhap diem toan: ";
	cin >> sv.toan;

	cout << "\nNhap diem li: ";
	cin >> sv.li;

	cout << "\nNhap diem hoa: ";
	cin >> sv.hoa;
}
void XuatSinhVien(SINHVIEN sv)
{
	cout << "\nMa so: " << sv.maso;
	cout << "\nHo ten: " << sv.hoten;
	cout << "\nNgay sinh: ";
	XuatNgay(sv.ngaysinh);
	cout << "\nDiem toan: " << sv.toan;
	cout << "\nDiem hoa: " << sv.hoa;
	cout << "\nDiem li: " << sv.li;
}
float DiemTB(SINHVIEN sv)
{
	return (sv.toan + sv.hoa + sv.li) / 3.0;
}
