#ifndef _XULY_
#define	_XULY_

#include "NhieuPhanSo.h"

int TimUCLN(int, int);
void RutGonPS(PHANSO&);
PHANSO operator+(PHANSO, PHANSO);
PHANSO operator+(PHANSO, int);
PHANSO operator+(int, PHANSO);
PHANSO operator-(PHANSO, PHANSO);
PHANSO operator*(PHANSO, PHANSO);
PHANSO operator/(PHANSO, PHANSO);

#endif

