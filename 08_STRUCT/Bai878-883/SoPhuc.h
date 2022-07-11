#ifndef _sophuc_
#define _sophuc_

#include <iostream>
using namespace std;

struct SoPhuc
{
	int PhanThuc, PhanAo;
};
typedef struct SoPhuc SOPHUC;

void NhapSoPhuc(SOPHUC&);
void XuatSoPhuc(SOPHUC);
SOPHUC TinhTong(SOPHUC, SOPHUC);
SOPHUC TinhHieu(SOPHUC, SOPHUC);
SOPHUC TinhTich(SOPHUC, SOPHUC);
SOPHUC SoPhucLienHop(SOPHUC);
SOPHUC TinhThuong(SOPHUC, SOPHUC);
SOPHUC TinhLuyThuaBacN(SOPHUC, int);

#endif
