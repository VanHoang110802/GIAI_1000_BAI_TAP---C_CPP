#ifndef _Sinhvien_
#define _Sinhvien_
#include "DanhSachMon.h"

struct SinhVien
{
	string MaSo, Ten;
	DANHSACHMONHOC danhsachmon;
};
typedef struct SinhVien SINHVIEN;

void NhapSinhVien(SINHVIEN&);
void XuatSinhVien(SINHVIEN);
float TinhDiemTrungBinh(SINHVIEN);
string XepLoai(SINHVIEN);
int KiemTraBiRotMon(SINHVIEN);

#endif
