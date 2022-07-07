#ifndef _ngaythangnam_
#define _ngaythangnam_

#include <iostream>
using namespace std;

struct ThoiGian
{
    int Day, Month, Year;
};
typedef ThoiGian THOIGIAN;

void NhapThoiGian(THOIGIAN&);
void XuatThoiGian(THOIGIAN);

#endif 

