#ifndef _donthuc_
#define _donthuc_

#include <iostream>
#include <cmath>
using namespace std;
struct DonThuc
{
	float heso;
	int somu;
};
typedef struct DonThuc DONTHUC;

void NhapDonThuc(DONTHUC&);
void XuatDonThuc(DONTHUC);
DONTHUC TinhTong2DT(DONTHUC, DONTHUC);
DONTHUC TinhHieu2DT(DONTHUC, DONTHUC);
DONTHUC TinhTich2DT(DONTHUC, DONTHUC);
DONTHUC TinhThuong2DT(DONTHUC, DONTHUC);
DONTHUC TimDaoHamDT(DONTHUC);
DONTHUC TimDaoHamKDT(DONTHUC, int);
double TinhGiaTriDonThuc(DONTHUC , int );
DONTHUC operator * (DONTHUC, DONTHUC);
DONTHUC operator / (DONTHUC, DONTHUC);

#endif

