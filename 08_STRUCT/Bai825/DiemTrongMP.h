#ifndef _DIEMTRONGMP_
#define _DIEMTRONGMP_

#include <iostream>
using namespace std;
struct Diem
{
	float x, y,z;
};
typedef struct Diem DIEM;

void NhapDiem(DIEM&);
void XuatDiem(DIEM);
#endif
