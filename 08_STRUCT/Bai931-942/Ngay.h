#ifndef _ngaythangnam_
#define _ngaythangnam_

#include <iostream>
using namespace std;

const int MinNam = 1900;
struct NhapNgayThangNam
{
	int Ngay, Thang, Nam;
};
typedef struct NhapNgayThangNam NHAP;

void NhapNgay(NHAP&);
void XuatNgay(NHAP);
int TimSoNgayTrongThang(NHAP);
int KiemTraNamNhuan(NHAP);
int TinhSoThuTuNgayTrongNam(NHAP);
int CheckYear(int);
int TinhSoThuTuNgayTuNgayChoTruoc(NHAP);
int TimNgayKhiBietNamVaSoThuTuNgayTrongNam(int, int);
int TimNgayKhiBietSoThuTuNgayChoTruoc(int);
NHAP TimNgayKeTiep(NHAP);
NHAP TimNgayHomQua(NHAP);
NHAP TimNgayKeDoKNgay(NHAP, int);
NHAP TimNgayTruocDoKNgay(NHAP, int);
int TimKhoangCach2Ngay(NHAP, NHAP);
int SoSanh2Ngay(NHAP, NHAP);
void TinhThuTrongTuanCua1NgayBatKyTrongNam(NHAP);

#endif
