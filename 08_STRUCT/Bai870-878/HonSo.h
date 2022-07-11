#ifndef _honso_
#define _honso_

#include <iostream>
using namespace std;

struct HonSo
{
	int PhanNguyen, TuSo, MauSo;
};
typedef struct HonSo HONSO;

void NhapHonSo(HONSO &);
void XuatHonSo(HONSO);
int TimUCLN(int , int );
HONSO RutGonHonSo(HONSO);
HONSO TinhTong(HONSO, HONSO);
HONSO TinhHieu(HONSO, HONSO);
HONSO TinhTich(HONSO, HONSO);
HONSO TinhThuong(HONSO, HONSO);
int KiemTraToiGian(HONSO);
void QuyDong2HS(HONSO&, HONSO&);

#endif
