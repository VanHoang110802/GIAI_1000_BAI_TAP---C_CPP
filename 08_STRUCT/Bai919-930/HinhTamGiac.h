#ifndef _hinhtamgiactrongmp_
#define _hinhtamgiactrongmp_

#include "DiemTrongKG.h"
struct HinhTamGiac
{
	diem A, B, C;
};
typedef struct HinhTamGiac tamgiac;

int KiemTraCoPhaiTamGiac(tamgiac);
void NhapHinhTamGiac(tamgiac&);
void XuatHinhTamGiac(tamgiac);
float TinhChuViTamGiac(tamgiac);
float TinhDienTichTamGiac(tamgiac);
diem TimToaDoTrongTamTamGiac(tamgiac);
diem TimDinhCoHoanhDoLonNhat(tamgiac);
diem TimDinhCoTungDoNhoNhat(tamgiac);
float TinhKhoangCachTuPToi3Dinh(tamgiac, diem);
int KiemTra1DiemCoNamTrongTamGiac(tamgiac, diem);
int DangTamGiac(tamgiac);

#endif
