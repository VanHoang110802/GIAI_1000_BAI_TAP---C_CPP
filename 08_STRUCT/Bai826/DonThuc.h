#ifndef _donthuc_
#define _donthuc_

#include <iostream>
using namespace std;
struct DonThuc
{
	float a;
	int n;
};
typedef struct DonThuc DONTHUC;

void NhapDonThuc(DONTHUC&);
void XuatDonThuc(DONTHUC);
#endif
