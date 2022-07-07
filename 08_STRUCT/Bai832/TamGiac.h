#ifndef _tamgiacmpOXY_
#define _tamgiacmpOXY_

#include "Diem.h"

struct TamGiac
{
	DIEM A;
	DIEM B;
	DIEM C;
};
typedef struct TamGiac TAMGIAC;

void NhapTamGiac(TAMGIAC& );
void XuatTamGiac(TAMGIAC );
float TinhDienTich(TAMGIAC );
float TinhChuVi(TAMGIAC );
DIEM TimTrongTam(TAMGIAC );

#endif 

