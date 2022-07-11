/*
Khai báo kiểu dữ liệu để biểu diễn thông tin của một số phức.
Nhập số phức.
Xuất số phức
Tính tổng hai số phức.
Tính hiệu hai số phức.
Tính tích hai số phức.
Tính thương hai số phức.
Tính lũy thừa bậc n của số phức.
*/

#include "SoPhuc.h"
int main()
{
	int n;
	SOPHUC sp1, sp2, ketqua, luythua;
	NhapSoPhuc(sp1);
	NhapSoPhuc(sp2);
	cout << "\n";
	XuatSoPhuc(sp1);
	cout << "\n";
	XuatSoPhuc(sp2);
	ketqua = TinhTong(sp1, sp2);
	cout << "\n";
	cout << "Tong 2 so phuc: ";
	XuatSoPhuc(ketqua);
	ketqua = TinhHieu(sp1, sp2);
	cout << "\n";
	cout << "Hieu 2 so phuc: ";
	XuatSoPhuc(ketqua);
	ketqua = TinhTich(sp1, sp2);
	cout << "\n";
	cout << "Tich 2 so phuc: ";
	XuatSoPhuc(ketqua);
	ketqua = TinhThuong(sp1, sp2);
	cout << "\n";
	cout << "Thuong 2 so phuc: ";
	XuatSoPhuc(ketqua);
	cout << "\n";
	cout << "Nhap n = ";
	cin >> n;
	luythua = TinhLuyThuaBacN(sp1,n);
	cout << "\nLuy thua bac " << n << " so phuc(sp1) la: ";
	XuatSoPhuc(luythua);
	luythua = TinhLuyThuaBacN(sp2, n);
	cout << "\nLuy thua bac " << n << " so phuc(sp2) la: ";
	XuatSoPhuc(luythua);
	return 0;
}
