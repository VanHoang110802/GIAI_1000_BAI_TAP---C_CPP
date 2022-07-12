/*
Đường tròn trong mặt phẳng Oxy
Khai báo kiểu dữ liệu để biểu diễn đường tròn.
Nhập đường tròn.
Xuất đường tròn theo định dạng ((x,y),r).
Tính chu vi đường tròn.
Tính diện tích đường tròn.
Xét vị trí tương đối giữa hai đường tròn (không cắt nhau, tiếp xúc, cắt nhau).
Kiểm tra một toạ độ điểm có nằm trong đường tròn hay không.
Cho hai đường tròn. Tính diện tích phần mặt phẳng bị phủ bởi hai đường tròn đó.
*/

#include "DuongTron.h"

int main()
{
	duongtron dgt1,dgt2;
	diem d;
	NhapDuongTron(dgt1);
	NhapDuongTron(dgt2);
	XuatDuongTron(dgt1);
	cout << "\n";
	XuatDuongTron(dgt2);
	float ChuVi = TinhChuViDuongTron(dgt1);
	cout << "\nChu vi duong tron (dgt1): " << ChuVi;
	ChuVi = TinhChuViDuongTron(dgt2);
	cout << "\nChu vi duong tron (dgt2): " << ChuVi;

	float DienTich = TinhDienTichHinhTron(dgt1);
	cout << "\nDien tich duong tron (dgt1): "<< DienTich;
	DienTich = TinhDienTichHinhTron(dgt2);
	cout << "\nDien tich duong tron (dgt2): " << DienTich;

	int check = XetViTriTuongDoiGiua2DuongTron(dgt1, dgt2);
	if (check == 1) cout << "\n2 duong tron khong cat nhau";
	else if (check == 2) cout << "\n2 duong tron tiep xuc nhau";
	else if (check == 3) cout << "\n2 duong tron cat nhau";

	NhapDiem(d);
	if (KiemTra1DiemCoNamTrongDuongTron(dgt1, d))
	{
		cout << "\nDiem nam trong duong tron (dgt1)";
	}
	else
	{
		cout << "\nDiem nam ngoai duong tron (dgt1)";
	}
	if (KiemTra1DiemCoNamTrongDuongTron(dgt2, d))
	{
		cout << "\nDiem nam trong duong tron (dgt2)";
	}
	else
	{
		cout << "\nDiem nam ngoai duong tron (dgt2)";
	}
	float S = TinhDienTichPhanGiaoNhauGiua2DuongTron(dgt1, dgt2);
	cout << "\nS phan giao nhau giua 2 duong tron: "<< S;
	return 0;
}
