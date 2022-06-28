#pragma once
#include "Sinh_Vien.h"
#include <vector>

struct LopHoc
{
	vector<SINHVIEN> a; // mang nhieu sinh vien
	// so luong thi minh co size roi.
};
typedef struct LopHoc LOPHOC;
void NhapLop(LOPHOC&);
void XuatLop(LOPHOC);
float TimDTBMax(LOPHOC);
void XuatThongTinCacSinhVienDTBMax(LOPHOC);
