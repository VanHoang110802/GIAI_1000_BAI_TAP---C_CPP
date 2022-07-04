#ifndef _MONHOC_
#define _MONHOC_

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct MonHoc
{
	string TenMon;
	float SoDiem;
	int SoChi;
};
typedef struct MonHoc MONHOC;

void NhapMonHoc(MONHOC&);
void XuatMonHoc(MONHOC);
bool KiemTraLaSo(string);
#endif
