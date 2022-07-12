#include "HinhCau.h"
void NhapHinhCau(hinhcau& hc)
{
	NhapDiem(hc.I);
	cout << "\nNhap ban kinh: ";
	cin >> hc.r;
}
void XuatHinhCau(hinhcau hc)
{
	cout << "((" << hc.I.x << ", " << hc.I.y << ", " << hc.I.z << "), " << hc.r << ")";
}
float TinhDienTichXungQuanhHinhCau(hinhcau hc)
{
	return 4 * Pi * hc.r * hc.r;
}
float TinhTheTichHinhCau(hinhcau hc)
{
	return 4 / 3 * Pi * hc.r * hc.r * hc.r;
}
float TinhKhoangCachGiua2Diem(diem d1, diem d2)
{
	return sqrt(pow((d2.x - d1.x), 2) + pow((d2.y - d1.y), 2) + pow(d2.z - d1.z, 2));
}
int XetViTriTuongDoi2HinhCau(hinhcau hc1, hinhcau hc2)
{
	int check;
	float rLon = (hc1.r > hc2.r) ? hc1.r : hc2.r;
	float rNho = (hc1.r < hc2.r) ? hc1.r : hc2.r;

	float khoangcach2Tam = TinhKhoangCachGiua2Diem(hc1.I, hc2.I);

	if (khoangcach2Tam > rLon + rNho || khoangcach2Tam < rLon - rNho || khoangcach2Tam == 0)
	{
		check = 1;
	}
	else if (khoangcach2Tam == rLon + rNho || khoangcach2Tam == rLon - rNho)
	{
		check = 2;
	}
	else if (rLon - rNho < khoangcach2Tam && khoangcach2Tam < rLon + rNho)
	{
		check = 3;
	}
	return check;
}
int KiemTra1DiemCoNamTrongHinhCau(hinhcau hc, diem d)
{
	float kcachtutamdendiem = sqrt(pow((hc.I.x - d.x), 2) + pow((hc.I.y - d.y), 2) + pow((hc.I.z - d.z), 2));
	if (kcachtutamdendiem < hc.r) return 1;
	return 0;
}
