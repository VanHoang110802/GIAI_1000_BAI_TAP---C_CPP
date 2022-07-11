/*
Rút gọn phân số.
Tính tổng hai phân số.
Tính hiệu hai phân số.
Tính tích hai phân số.
Tính thương hai phân số.
Kiểm tra phân số tối giản
Qui đồng hai phân số.
Kiểm tra phân số dương.
Kiểm tra phân số âm.
So sánh hai phân số (Hàm sẽ trả về một trong 3 giá trị 0, -1, 1).
Định nghĩa toán tử cộng (operator +) cho hai phân số.
Định nghĩa toán tử hiệu (operator -) cho hai phân số.
Định nghĩa toán tử tích (operator *) cho hai phân số.
Định nghĩa toán tử thương (operator /) cho hai phân số.
Định nghĩa toán tử tăng một (operator ++) cho hai phân số.
Định nghĩa toán tử giảm một (operator --) cho hai phân số.
*/

#include "PhanSo.h"
int main()
{
	PHANSO ps1, ps2,rutgon, ketqua;
	NhapPhanSo(ps1);
	NhapPhanSo(ps2);
	cout << "\nPhan so (ps1) la: ";
	XuatPhanSo(ps1);
	cout << "\nPhan so (ps2) la: ";
	XuatPhanSo(ps2);
	cout << "\n";
	rutgon = RutGonPhanSo(ps1);
	cout << "\nRut gon phan so(ps1): ";
	XuatPhanSo(rutgon);
	rutgon = RutGonPhanSo(ps2);
	cout << "\nRut gon phan so(ps2): ";
	XuatPhanSo(rutgon);
	ketqua = TinhTong(ps1, ps2);
	cout << "\nTong 2 phan so: ";
	XuatPhanSo(ketqua);
	ketqua = TinhHieu(ps1, ps2);
	cout << "\nHieu 2 phan so: ";
	XuatPhanSo(ketqua);
	ketqua = TinhTich(ps1, ps2);
	cout << "\nTich 2 phan so: ";
	XuatPhanSo(ketqua);
	ketqua = TinhThuong(ps1, ps2);
	cout << "\nThuong 2 phan so: ";
	XuatPhanSo(ketqua);
	int kiemtra = KiemTraPSToiGian(ps1);
	if (kiemtra == 0)
	{
		cout << "\nPhan so (ps1) goc chua duoc toi gian!";
	}
	else cout << "\nPhan so (ps1) goc da duoc toi gian!";
	kiemtra = KiemTraPSToiGian(ps2);
	if (kiemtra == 0)
	{
		cout << "\nPhan so (ps2) goc chua duoc toi gian!";
	}
	else cout << "\nPhan so (ps2) goc da duoc toi gian!";

	kiemtra = KTPSDuong(ps1);
	if (kiemtra == 0)
	{
		cout << "\nPhan so (ps1) khong la phan so duong!";
	}
	else cout << "\nPhan so (ps1) la phan so duong!";
	kiemtra = KTPSDuong(ps2);
	if (kiemtra == 0)
	{
		cout << "\nPhan so (ps2) goc khong la phan so duong!";
	}
	else cout << "\nPhan so (ps2) goc la phan so duong!";

	kiemtra = KTPSAm(ps1);
	if (kiemtra == 0)
	{
		cout << "\nPhan so (ps1) goc khong la phan so am!";
	}
	else cout << "\nPhan so (ps1) goc la phan so am!";
	kiemtra = KTPSAm(ps2);
	if (kiemtra == 0)
	{
		cout << "\nPhan so (ps2) goc khong la phan so am!";
	}
	else cout << "\nPhan so (ps2) goc la phan so am!";
	int sosanh = SoSanh2PS(ps1, ps2);
	if (sosanh == -1)
	{
		cout << "\nPhan so (ps1) nho hon phan so (ps2)!";
	}
	else if (sosanh == 1)
	{
		cout << "\nPhan so (ps1) lon hon phan so (ps2)!";
	}
	else cout << "\nPhan so (ps1) bang phan so (ps2)!";
	cout << "\nQuy dong 2 phan so: ";
	QuyDong2PS(ps1, ps2);
	XuatPhanSo(ps1); cout << "   ";
	XuatPhanSo(ps2);
	return 0;
}
