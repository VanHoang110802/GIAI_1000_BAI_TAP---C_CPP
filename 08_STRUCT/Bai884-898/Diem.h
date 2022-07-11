#ifndef _diemtrongmp_
#define _diemtrongmp_

#include <iostream>
#include <cmath>
using namespace std;

struct diem
{
	float x, y;
};
typedef struct diem DIEM;

void NhapDiem(DIEM &);
void XuatDiem(DIEM);
float TinhKhoangCachGiua2Diem(DIEM, DIEM);
float TinhKhoangCachGiua2DiemTheoOx(DIEM, DIEM);
float TinhKhoangCachGiua2DiemTheoOy(DIEM, DIEM);
DIEM TimDiemDoiXungQuaO(DIEM);
DIEM TimDiemDoiXungQuaOx(DIEM);
DIEM TimDiemDoiXungQuaOy(DIEM);
DIEM TimDiemDoiXungQuaPhanGiacI(DIEM);
DIEM TimDiemDoiXungQuaPhanGiacII(DIEM);
int KiemTraDiemThuocPhanTuI(DIEM);
int KiemTraDiemThuocPhanTuII(DIEM);
int KiemTraDiemThuocPhanTuIII(DIEM);
int KiemTraDiemThuocPhanTuIV(DIEM);

#endif
