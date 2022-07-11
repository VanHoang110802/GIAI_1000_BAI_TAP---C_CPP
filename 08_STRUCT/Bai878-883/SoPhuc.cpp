#include "SoPhuc.h"
void NhapSoPhuc(SOPHUC& sp)
{
	cout << "Nhap phan thuc: ";
	cin >> sp.PhanThuc;

	cout << "Nhap phan ao: ";
	cin >> sp.PhanAo;
}
void XuatSoPhuc(SOPHUC sp)
{
	cout << sp.PhanThuc << " + " <<  sp.PhanAo;
}
SOPHUC TinhTong(SOPHUC sp1, SOPHUC sp2)
{
	SOPHUC temp;
	temp.PhanThuc = sp1.PhanThuc + sp2.PhanThuc;
	temp.PhanAo = sp1.PhanAo + sp2.PhanAo;
	return temp;
}
SOPHUC TinhHieu(SOPHUC sp1, SOPHUC sp2)
{
	SOPHUC temp;
	temp.PhanThuc = sp1.PhanThuc - sp2.PhanThuc;
	temp.PhanAo = sp1.PhanAo - sp2.PhanAo;
	return temp;
}
SOPHUC TinhTich(SOPHUC sp1, SOPHUC sp2)
{
	//(a + bi)(c + di) = (ac - bd) + (ad + bc)i
	SOPHUC temp;
	temp.PhanThuc = sp1.PhanThuc * sp2.PhanThuc - sp1.PhanAo * sp2.PhanAo;
	temp.PhanAo = sp1.PhanThuc * sp2.PhanAo + sp1.PhanAo * sp2.PhanThuc;
	return temp;
}
SOPHUC SoPhucLienHop(SOPHUC sp)
{
	sp.PhanThuc = -sp.PhanThuc;
	return sp;
}
SOPHUC TinhThuong(SOPHUC sp1, SOPHUC sp2)
{
	SOPHUC temp = TinhTich(sp1, SoPhucLienHop(sp2));
	float x = sp2.PhanAo * sp2.PhanAo + sp2.PhanThuc * sp2.PhanThuc;
	temp.PhanThuc /= x;
	temp.PhanAo /= x;
	return temp;
}
SOPHUC TinhLuyThuaBacN(SOPHUC sp, int n)
{
	while (n != 0)
	{
		sp = TinhTich(sp, sp);
		n--;
	}
	return sp;
}
