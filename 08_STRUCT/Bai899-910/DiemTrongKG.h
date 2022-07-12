#ifndef _khonggianOxy_
#define _khonggianOxy_

#include <iostream>
#include <cmath>
using namespace std;

struct Diem
{
	float x, y, z;
};
typedef struct Diem diem;

void NhapDiem(diem&);
void XuatDiem(diem);
float TinhKhoangCachGiua2Diem(diem, diem);
float TinhKhoangCachGiua2DiemTheoOx(diem, diem);
float TinhKhoangCachGiua2DiemTheoOy(diem, diem);
float TinhKhoangCachGiua2DiemTheoOz(diem, diem);
diem TimDiemDoiXungQuaO(diem);
diem TimDiemDoiXungQuaOxy(diem);
diem TimDiemDoiXungQuaOxz(diem);
diem TimDiemDoiXungQuaOyz(diem);

#endif
