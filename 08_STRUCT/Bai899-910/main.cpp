/*
Điểm trong không gian Oxyz
Khai báo kiểu dữ liệu biểu diễn tọa độ một điểm trong không gian Oxyz.
Nhập toạ độ điểm trong không gian Oxyz.
Xuất toạ độ điểm theo định dạng (x, y, z).
Tính khoảng cách giữa hai điểm trong không gian.
Tính khoảng cách giữa hai điểm trong không gian theo phương x.
Tính khoảng cách giữa hai điểm trong không gian theo phương y.
Tính khoảng cách giữa hai điểm trong không gian theo phương z.
Tìm toạ độ điểm đối xứng qua gốc toạ độ.
Tìm toạ độ điểm đối xứng qua mặt phẳng Oxy.
Tìm toạ độ điểm đối xứng qua mặt phẳng Oxz.
Tìm toạ độ điểm đối xứng qua mặt phẳng Oyz.
*/

#include "DiemTrongKG.h"
int main()
{
	diem d1, d2, tim;
	NhapDiem(d1);
	NhapDiem(d2);
	cout << "\n";
	XuatDiem(d1);
	cout << "\n";
	XuatDiem(d2);
	cout << "\n";
	float tinh;
	tinh = TinhKhoangCachGiua2Diem(d1, d2);
	cout << "\nKhoang cach giua 2 diem: " << tinh;
	tinh = TinhKhoangCachGiua2DiemTheoOx(d1, d2);
	cout << "\nKhoang cach giua 2 diem theo Ox: " << tinh;
	tinh = TinhKhoangCachGiua2DiemTheoOy(d1, d2);
	cout << "\nKhoang cach giua 2 diem theo Oy: " << tinh;
	tinh = TinhKhoangCachGiua2DiemTheoOz(d1, d2);
	cout << "\nKhoang cach giua 2 diem theo Oz: " << tinh;
	tim = TimDiemDoiXungQuaO(d1);
	cout << "\nToa do diem (d1) doi xung qua goc toa do: ";
	XuatDiem(tim);
	tim = TimDiemDoiXungQuaO(d2);
	cout << "\nToa do diem (d2) doi xung qua goc toa do: ";
	XuatDiem(tim);
	tim = TimDiemDoiXungQuaOxy(d1);
	cout << "\nToa do diem (d1) doi xung qua mp(Oxy): ";
	XuatDiem(tim);
	tim = TimDiemDoiXungQuaOxy(d2);
	cout << "\nToa do diem (d2) doi xung qua mp(Oxy): ";
	XuatDiem(tim);
	tim = TimDiemDoiXungQuaOyz(d1);
	cout << "\nToa do diem (d1) doi xung qua mp(Oyz): ";
	XuatDiem(tim);
	tim = TimDiemDoiXungQuaOyz(d2);
	cout << "\nToa do diem (d2) doi xung qua mp(Oyz): ";
	XuatDiem(tim);
	tim = TimDiemDoiXungQuaOxz(d1);
	cout << "\nToa do diem (d1) doi xung qua mp(Oxz): ";
	XuatDiem(tim);
	tim = TimDiemDoiXungQuaOxz(d2);
	cout << "\nToa do diem (d2) doi xung qua mp(Oxz): ";
	XuatDiem(tim);
	return 0;
}
