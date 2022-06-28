#include <iostream>
using namespace std;

struct Ngay
{
	int ngay, thang, nam;
};
typedef struct Ngay NGAY; // bien struct Ngay -> Ngay.

void NhapNgay(NGAY &);
void XuatNgay(NGAY);
