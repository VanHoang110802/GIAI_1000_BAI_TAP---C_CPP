/*

Tính cộng, trừ, tích, thương hai đơn thức.
Tính đạo hàm cấp 1 đơn thức.
Tính đạo hàm cấp k đơn thức.
Tính giá trị đơn thức tại vị trí x = xo.
Định nghĩa toán tử tích (operator *) cho hai đơn thức.
Định nghĩa toán tử thương (operator /) cho hai đơn thức.

*/
/*
 Để nhân hai đơn thức, ta nhân các hệ số với nhau và nhân các phần biến với nhau.
 (biến = số mũ, muốn nhân 2 số mũ với nhau: a^n * a^m = a^n + m )
*/
/*
Để cộng, trù 2 đơn thức, ta cộng, trừ các hệ số với nhau, giữ nguyên phần biến là được
*/
/*
Để chia hai đơn thức, ta chia các hệ số với nhau và chia các phần biến với nhau
(biến = số mũ, muốn chia 2 số mũ với nhau: a^n / a^m = a^(n - m))
*/
/*
Để tính đạo hàm cho 1 đơn thức, ta có công thức tổng quát như sau:
		a.x^n = n.a.x^n - 1 ( '.' là nhân nhé)
*/
/*
Để tính đạo hàm cho k đơn thức, ta có công thức tổng quát như sau:
		a.x^n = n.a.x^n - 1 ( '.' là nhân nhé)
ta nhớ lại đạo hàm của số đã học ở THPT trước đó:
-> đạo hàm cấp 1: n.ax^n-1
-> đạo hàm cấp 2: n.n-1.ax^n-2 (đạo hàm của đạo hàm cấp 1)
-> đạo hàm cấp 3: n.n-1.n-2.ax^n-3 (đạo hàm của đạo hàm cấp 2)

vậy ta có vòng lặp dựa trên số k được người dùng nhập từ bàn phím vào, mỗi lần lặp k-- đi đơn vị
ta sẽ suy ra được công thức tổng quát như sau:
		a.x^k-- = n.k--.a.n^k--

*/
/*
 giá trị đơn thức tại vị trí x = x0, y = ax^n thì ta thay x = x0 (ví dụ x = 3)
 -> y = a.3^n -> y = 2.3^2 = 18

*/
#include "DonThuc.h"
int main()
{
	DONTHUC dt,dt1,kqTinhTong, kqTinhHieu,kqTinhTich,kqTinhThuong,kqDaoHam, kqDaoHamKDT, kqOperator1, kqOperator2;
	NhapDonThuc(dt);
	NhapDonThuc(dt1);
	cout << "\nDon thuc thu 1: "; XuatDonThuc(dt);
	cout << "\nDon thuc thu 2: "; XuatDonThuc(dt1);
	if (dt.somu != dt1.somu)
	{
		cout << "\n\nKhong the tinh duoc vi so mu cua 2 don thuc khac nhau!";
	}
	else
	{
		kqTinhTong = TinhTong2DT(dt, dt1);
		kqTinhHieu = TinhHieu2DT(dt, dt1);
		cout << "\n\nTong cua 2 don thuc la: " << kqTinhTong.heso << "x^" << kqTinhTong.somu;
		cout << "\nHieu cua 2 don thuc la: " << kqTinhHieu.heso << "x^" << kqTinhHieu.somu;
	}
	kqTinhTich = TinhTich2DT(dt, dt1);
	cout << "\nTich cua 2 don thuc: " << kqTinhTich.heso << "x^" << kqTinhTich.somu;
	kqTinhThuong = TinhThuong2DT(dt, dt1);
	cout << "\nThuong cua 2 don thuc: " << kqTinhThuong.heso << "x^" << kqTinhThuong.somu;
	kqDaoHam = TimDaoHamDT(dt);
	cout << "\n\nDao ham don thuc 1: " << kqDaoHam.heso << "x^" << kqDaoHam.somu;
	kqDaoHamKDT = TimDaoHamKDT(dt,2);
	cout << "\nDao ham k = 2 don thuc 1: " << kqDaoHamKDT.heso << "x^" << kqDaoHamKDT.somu;
	double giatribieuthuc = TinhGiaTriDonThuc(dt, 3);
	cout << "\nGia tri cua bieu thuc sau khi thay x la: " << giatribieuthuc;

	/*------------------------------------------------------*/
	DONTHUC kq = dt*dt1;
	cout << "\nTich don thuc theo openrator: " << kq.heso << "x^" << kq.somu;
	DONTHUC kq1 = dt/dt1;
	cout << "\nThuong don thuc theo openrator: " << kq1.heso << "x^" << kq1.somu;
	return 0;
}
