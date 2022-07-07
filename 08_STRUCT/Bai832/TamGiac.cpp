#include "TamGiac.h"

void NhapTamGiac(TAMGIAC& tg)
{
	cout << "\nNhap toa do dinh thu nhat: ";
	NhapDiem(tg.A);

	cout << "\nNhap toa do dinh thu hai: ";
	NhapDiem(tg.B);

	cout << "\nNhap toa do dinh thu ba: ";
	NhapDiem(tg.C);
}

void XuatTamGiac(TAMGIAC tg)
{
	cout << "\nToa do dinh thu nhat: ";
	XuatDiem(tg.A);

	cout << "\nToa do dinh thu hai: ";
	XuatDiem(tg.B);

	cout << "\nToa do dinh thu ba: ";
	XuatDiem(tg.C);
}
float TinhDienTich(TAMGIAC tg)
{
	float a = TinhKhoangCach(tg.B, tg.C);
	float b = TinhKhoangCach(tg.C, tg.A);
	float c = TinhKhoangCach(tg.A, tg.B);
	float p = (a + b + c) / 2;
	float DienTich = sqrt(p * (p - a) * (p - b) * (p - c));

	return DienTich;
}

float TinhChuVi(TAMGIAC tg)
{
	float a = TinhKhoangCach(tg.B, tg.C);
	float b = TinhKhoangCach(tg.C, tg.A);
	float c = TinhKhoangCach(tg.A, tg.B);

	float ChuVi = (a + b + c);
	return ChuVi;
}

DIEM TimTrongTam(TAMGIAC tg)
{
	DIEM G;
	G.x = (tg.A.x + tg.B.x + tg.C.x) / 3;
	G.y = (tg.A.y + tg.B.y + tg.C.y) / 3;

	return G;
}
