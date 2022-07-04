#ifndef _Lophoc_
#define _Lophoc_
#include "SinhVien.h"

struct LopHoc
{
	int n = 0; // số lượng sinh viên
	SINHVIEN* arr; // mảng động sinh viên
};
typedef struct LopHoc LOPHOC;

void NhapLopHoc(LOPHOC&);
void XuatLopHoc(LOPHOC);
void HoanVi(SINHVIEN&, SINHVIEN&);
void SapXepLopHoc(LOPHOC&, char);
int DemSoLuongHocBong(LOPHOC);
void XuLyHocLai(LOPHOC, int&, float&);
SINHVIEN* TimKiemThongTin(LOPHOC, string);
void XoaSinhVien(LOPHOC&, int);
void XoaSinhVienDuaTrenMaSo(LOPHOC&, string);
void XoaTatCaSinhVienRotMon(LOPHOC&);
void CapNhatDuaTrenMaSo(LOPHOC&, string);
float TongTienHocBong(LOPHOC);
void SapXepTen(LOPHOC&, char);

#endif
