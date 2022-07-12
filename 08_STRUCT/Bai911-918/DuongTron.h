#ifndef _duongtrontrongmp_
#define _duongtrontrongmp_

#include "DiemTrongKG.h"
struct DuongTron
{
	diem I;
	float r;
};
typedef struct DuongTron duongtron;

void NhapDuongTron(duongtron&);
void XuatDuongTron(duongtron);
float TinhChuViDuongTron(duongtron);
float TinhDienTichHinhTron(duongtron);
float TinhKhoangCachGiua2Diem(diem, diem);
int XetViTriTuongDoiGiua2DuongTron(duongtron, duongtron);
int KiemTra1DiemCoNamTrongDuongTron(duongtron, diem);
float TinhDienTichPhanGiaoNhauGiua2DuongTron(duongtron, duongtron);

#endif
