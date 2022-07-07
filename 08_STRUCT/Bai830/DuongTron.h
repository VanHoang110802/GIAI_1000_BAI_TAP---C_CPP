#ifndef _duongtronmpOXY_
#define _duongtronmpOXY_

#include "Diem.h"

struct DuongTron
{
	DIEM I;
	float r;
	char tentamdt;
};
typedef struct DuongTron DUONGTRON;

void NhapDuongTron(DUONGTRON &);
void XuatDuongTron(DUONGTRON);

#endif 

