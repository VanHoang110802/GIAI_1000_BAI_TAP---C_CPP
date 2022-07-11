#ifndef _phanso_
#define _phanso_

#include <iostream>
using namespace std;

struct PhanSo
{
	int TuSo, MauSo;
};
typedef struct PhanSo PHANSO;

void NhapPhanSo(PHANSO&);
void XuatPhanSo(PHANSO);
PHANSO RutGonPhanSo(PHANSO);
PHANSO TinhTong(PHANSO, PHANSO);
PHANSO TinhHieu(PHANSO, PHANSO);
PHANSO TinhTich(PHANSO, PHANSO);
PHANSO TinhThuong(PHANSO, PHANSO);
int KiemTraPSToiGian(PHANSO);
void QuyDong2PS(PHANSO&, PHANSO&);
int KTPSDuong(PHANSO);
int KTPSAm(PHANSO);
int SoSanh2PS(PHANSO, PHANSO);
PHANSO operator + (PHANSO, PHANSO);
PHANSO operator - (PHANSO, PHANSO);
PHANSO operator * (PHANSO, PHANSO);
PHANSO operator / (PHANSO, PHANSO);
PHANSO operator ++ (PHANSO&);
PHANSO operator -- (PHANSO&);

#endif
