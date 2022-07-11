/*
Viết khai báo kiểu dữ liệu để biểu diễn thông tin của một hỗn số
Nhập hỗn số.
Xuất hỗn số.
Rút gọn hỗn số.
Tính tổng hai hỗn số.
Tính hiệu hai hỗn số.
Tính tích hai hỗn số.
Tính thương hai hỗn số.
Kiểm tra hỗn số tối giản.
Qui đồng hai hỗn số.
*/

#include "HonSo.h"
int main()
{
	HONSO hs1, hs2, ketqua;
	NhapHonSo(hs1);
	NhapHonSo(hs2);
	cout << "\n";
	XuatHonSo(hs1);
	cout << "\n";
	XuatHonSo(hs2);

	ketqua = TinhTong(hs1, hs2);
	cout << "\nTong cua 2 hon so la: ";
	XuatHonSo(ketqua);
	ketqua = TinhHieu(hs1, hs2);
	cout << "\nHieu cua 2 hon so la: ";
	XuatHonSo(ketqua);
	ketqua = TinhTich(hs1, hs2);
	cout << "\nTich cua 2 hon so la: ";
	XuatHonSo(ketqua);
	ketqua = TinhThuong(hs1, hs2);
	cout << "\nThuong cua 2 hon so la: ";
	XuatHonSo(ketqua);

	if (KiemTraToiGian(hs1))
	{
		cout << "\nHon so (hs1) goc, da toi gian!";
	}
	else cout << "\nHon so (hs1) goc, chua toi gian!";
	if (KiemTraToiGian(hs2))
	{
		cout << "\nHon so (hs2) goc, da toi gian!";
	}
	else cout << "\nHon so (hs2) goc, chua toi gian!";
	QuyDong2HS(hs1, hs2);
	cout << "\nHon so (hs1) sau khi qui dong: ";
	XuatHonSo(hs1);
	cout << "\nHon so (hs2) sau khi qui dong: ";
	XuatHonSo(hs2);
	return 0;
}
