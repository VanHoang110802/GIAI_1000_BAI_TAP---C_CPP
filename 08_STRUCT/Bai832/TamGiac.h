#ifndef _tamgiacmpOXY_
#define _tamgiacmpOXY_

#include "Diem.h"

struct tamgiac
{
	DIEM A;
	DIEM B;
	DIEM C;
};
typedef struct tamgiac TAMGIAC;

void NhapTamGiac(TAMGIAC& );
void XuatTamGiac(TAMGIAC );
float TinhDienTich(TAMGIAC );
float TinhChuVi(TAMGIAC );
DIEM TimTrongTam(TAMGIAC );

#endif 

