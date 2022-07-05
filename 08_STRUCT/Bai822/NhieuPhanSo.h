#ifndef _NHIEUPHANSO_
#define _NHIEUPHANSO_

#include <iostream>
using namespace std;
struct PhanSo
{
	int tuso, mauso;
};
typedef struct PhanSo PHANSO;

istream& operator >> (istream& , PHANSO&);
ostream& operator << (ostream& , PHANSO);

#endif
