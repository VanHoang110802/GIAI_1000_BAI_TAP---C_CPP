#ifndef _diem_
#define _diem_

#include <iostream>
using namespace std;

struct Diem
{
	float x, y;
};
typedef struct Diem DIEM;

void NhapDiem(DIEM&);
void XuatDiem(DIEM);
#endif 
