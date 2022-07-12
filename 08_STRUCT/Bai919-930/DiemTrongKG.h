#ifndef _khonggianOxy_
#define _khonggianOxy_

#include <iostream>
#include <cmath>
using namespace std;

struct Diem
{
	float x, y;
};
typedef struct Diem diem;

void NhapDiem(diem&);
void XuatDiem(diem);
float TinhKhoangCachGiua2Diem(diem, diem);

#endif
