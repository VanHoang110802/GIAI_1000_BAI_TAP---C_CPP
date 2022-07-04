#ifndef _DSMONHOC_
#define _DSMONHOC_
#include "MonHoc.h"

struct DanhSachMonHoc
{
	int n;
	MONHOC* arr;
};
typedef struct DanhSachMonHoc DANHSACHMONHOC;

void NhapDanhSachMon(DANHSACHMONHOC&);
void XuatDanhSachMon(DANHSACHMONHOC);

#endif
