/*
Điểm trong mặt phẳng Oxy
Khai báo kiểu dữ liệu.
Nhập toạ độ điểm trong mặt phẳng.
Xuất toạ độ điểm theo định dạng (x,y).
Tính khoảng cách giữa hai điểm.
Tính khoảng cách giữa hai điểm theo phương Ox.
Tính khoảng cách giữa hai điểm theo phương Oy.
Tìm toạ độ điểm đối xứng qua gốc toạ độ.
Tìm toạ độ điểm đối xứng qua trục hoành.
Tìm toạ độ điểm đối xứng qua trục tung.
Tìm toạ độ điểm đối xứng qua đường phân giác thứ nhất (y = x).
Tìm toạ độ điểm đối xứng qua đường phân giác thứ hai (y = -x).
Kiểm tra điểm có thuộc phần tư thứ I không?.
Kiểm tra điểm có thuộc phần tư thứ II không?.
Kiểm tra điểm có thuộc phần tư thứ III không?.
Kiểm tra điểm có thuộc phần tư thứ IV không?.
*/

#include "Diem.h"
int main()
{
	DIEM d1, d2, diemdoixung, ddx;
	float khoangcach, kcOx, kcOy;
	NhapDiem(d1);
	NhapDiem(d2);
	XuatDiem(d1);
	cout << "\n";
	XuatDiem(d2);
	khoangcach = TinhKhoangCachGiua2Diem(d1, d2);
	cout << "\nKhoang cach giua 2 diem: " << khoangcach;
	kcOx = TinhKhoangCachGiua2DiemTheoOx(d1, d2);
	cout << "\nKhoang cach giua 2 diem theo phuong Ox: " << kcOx;
	kcOy = TinhKhoangCachGiua2DiemTheoOx(d1, d2);
	cout << "\nKhoang cach giua 2 diem theo phuong Oy: " << kcOy;
	diemdoixung = TimDiemDoiXungQuaO(d1);
	cout << "\nDiem doi xung(d1) qua goc toa do: ";
	XuatDiem(d1);
	diemdoixung = TimDiemDoiXungQuaOx(d1);
	cout << "\nDiem doi xung(d1) qua truc hoanh (Ox): ";
	XuatDiem(diemdoixung);
	diemdoixung = TimDiemDoiXungQuaOy(d1);
	cout << "\nDiem doi xung(d1) qua truc hoanh (Oy): ";
	XuatDiem(d1);
	diemdoixung = TimDiemDoiXungQuaO(d2);
	cout << "\nDiem doi xung(d2) qua goc toa do: ";
	XuatDiem(d2);
	diemdoixung = TimDiemDoiXungQuaOx(d2);
	cout << "\nDiem doi xung(d2) qua truc hoanh (Ox): ";
	XuatDiem(d2);
	diemdoixung = TimDiemDoiXungQuaOy(d2);
	cout << "\nDiem doi xung(d2) qua truc hoanh (Oy): ";
	XuatDiem(d2);
	diemdoixung = TimDiemDoiXungQuaPhanGiacI(d1);
	cout << "\nDiem doi xung(d1) qua duong phan giac thu 1: ";
	XuatDiem(d1);
	diemdoixung = TimDiemDoiXungQuaPhanGiacII(d1);
	cout << "\nDiem doi xung(d1) qua duong phan giac thu 2: ";
	XuatDiem(d1);
	diemdoixung = TimDiemDoiXungQuaPhanGiacI(d2);
	cout << "\nDiem doi xung(d2) qua duong phan giac thu 1: ";
	XuatDiem(d2);
	diemdoixung = TimDiemDoiXungQuaPhanGiacII(d2);
	cout << "\nDiem doi xung(d2) qua duong phan giac thu 1: ";
	XuatDiem(d2);

	if (KiemTraDiemThuocPhanTuI(d1)) printf("\nd1 thuoc phan tu thu 1");
	else printf("\nd1 khong thuoc phan tu thu 1");
	if (KiemTraDiemThuocPhanTuII(d1)) printf("\nd1 thuoc phan tu thu 2");
	else printf("\nd1 khong thuoc phan tu thu 2");
	if (KiemTraDiemThuocPhanTuIII(d1)) printf("\nd1 thuoc phan tu thu 3");
	else printf("\nd1 khong thuoc phan tu thu 3");
	if (KiemTraDiemThuocPhanTuIV(d1)) printf("\nd1 thuoc phan tu thu 4");
	else printf("\nd1 khong thuoc phan tu thu 4");

	if (KiemTraDiemThuocPhanTuI(d2)) printf("\nd2 thuoc phan tu thu 1");
	else printf("\nd2 khong thuoc phan tu thu 1");
	if (KiemTraDiemThuocPhanTuII(d2)) printf("\nd2 thuoc phan tu thu 2");
	else printf("\nd2 khong thuoc phan tu thu 2");
	if (KiemTraDiemThuocPhanTuIII(d2)) printf("\nd2 thuoc phan tu thu 3");
	else printf("\nd2 khong thuoc phan tu thu 3");
	if (KiemTraDiemThuocPhanTuIV(d2)) printf("\nd2 thuoc phan tu thu 4");
	else printf("\nd2 khong thuoc phan tu thu 4");
	return 0;
}
