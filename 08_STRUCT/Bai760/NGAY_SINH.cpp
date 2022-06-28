#include "NGAY_SINH.h" // moi lien ket giua file .h va .cpp
// neu dung cap <> thi no se di do tim vao cac thu vien co san se nhanh hon "".
void NhapNgay(NGAY &x)
{
	cout << "\nNhap vao ngay: ";
	cin >> x.ngay;

	cout << "\nNhap vao thang: ";
	cin >> x.thang;

	cout << "\nNhap vao nam: ";
	cin >> x.nam;
}
void XuatNgay(NGAY x)
{
	cout << "Ngay: " << x.ngay << "\nThang: " << x.thang << "\nNam: " << x.nam;
}
