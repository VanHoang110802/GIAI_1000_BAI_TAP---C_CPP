#pragma once
#include "NGAY_SINH.h"
#include <string>

struct SinhVien
{
	string maso, hoten;
	NGAY ngaysinh;
	float toan, li, hoa;
};
typedef struct SinhVien SINHVIEN;

void NhapSinhVien(SINHVIEN&);
void XuatSinhVien(SINHVIEN);
float DiemTB(SINHVIEN);
