#ifndef _dathuc_
#define _dathuc_

#include <iostream>
using namespace std;

struct DaThuc
{
	int n;
	float* a;
};
typedef struct DaThuc DATHUC;

void NhapDaThuc(DATHUC*);
void XuatDaThuc(DATHUC*);

#endif // !_dathuc_
