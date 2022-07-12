#ifndef _hinhcautrongmp_
#define _hinhcautrongmp_

#include "DiemTrongKG.h"
struct HinhCau
{
	diem I;
	float r;
};
typedef struct HinhCau hinhcau;

void NhapHinhCau(hinhcau&);
void XuatHinhCau(hinhcau);
float TinhDienTichXungQuanhHinhCau(hinhcau);
float TinhTheTichHinhCau(hinhcau);
float TinhKhoangCachGiua2Diem(diem, diem);
int XetViTriTuongDoi2HinhCau(hinhcau, hinhcau);
int KiemTra1DiemCoNamTrongHinhCau(hinhcau, diem);

#endif
