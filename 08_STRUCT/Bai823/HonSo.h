#ifndef _HONSO_
#define _HONSO_

#include <iostream>
using namespace std;
struct HonSo
{
	int phannguyen, tuso, mauso;
};
typedef struct HonSo HONSO;

void NhapHonSo(HONSO &);
void XuatHonSo(HONSO);
#endif
