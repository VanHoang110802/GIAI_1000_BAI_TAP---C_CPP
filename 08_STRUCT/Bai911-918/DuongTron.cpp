#include "DuongTron.h"
void NhapDuongTron(duongtron& dgt) // dgt = duongtron
{
	NhapDiem(dgt.I);
	cout << "\nNhap ban kinh: ";
	cin >> dgt.r;
}
void XuatDuongTron(duongtron dgt)
{
	cout << "((" << dgt.I.x << ", " << dgt.I.y << "), " << dgt.r << ")";
}
float TinhChuViDuongTron(duongtron dgt)
{
	return 2 * Pi * dgt.r;
}
float TinhDienTichHinhTron(duongtron dgt)
{
	
	return Pi * dgt.r * dgt.r;
}
float TinhKhoangCachGiua2Diem(diem d1, diem d2)
{
	return sqrt(pow((d2.x - d1.x), 2) + pow((d2.y - d1.y), 2));
}
int XetViTriTuongDoiGiua2DuongTron(duongtron dgt1, duongtron dgt2)
{
	// ta sẽ đi tìm min, max bán kính của 2 đường tròn. Rồi đi tính khoảng cách giữa 2 tâm của đường tròn
	// nếu khoảng cách giữa 2 điểm kc mà > tổng, hoặc < hiệu max - min, hoặc = 0 của cả 2 bán kính đường tròn cộng lại -> không cắt
	// nếu khoảng cách giữa 2 điểm kc mà = tổng, hoặc hiệu của cả 2 bán kính đường tròn -> tiếp xúc
	// nếu khoảng cách giữa 2 điểm kc mà < tổng của cả 2 bán kính đường tròn và > max - min -> cắt
	int check;
	float rmax = (dgt1.r > dgt2.r) ? dgt1.r : dgt2.r;
	float rmin = (dgt1.r < dgt2.r) ? dgt1.r : dgt2.r;

	float khoangcach2tam = TinhKhoangCachGiua2Diem(dgt1.I, dgt2.I);

	if (khoangcach2tam > rmax + rmin || khoangcach2tam < rmax - rmin || khoangcach2tam == 0)
	{
		return check = 1;
	}
	else if (khoangcach2tam == rmax + rmin || khoangcach2tam == rmax - rmin)
	{
		return check = 2;
	}
	else if (rmax - rmin < khoangcach2tam && khoangcach2tam < rmax + rmin)
	{
		return check = 3;
	}
}
int KiemTra1DiemCoNamTrongDuongTron(duongtron dgt, diem d)
{
	// câu này dựa vào ví dụ trên mạng nên tự suy ra công thức
	float kcachtutamdendiem = sqrt(pow((dgt.I.x - d.x), 2) + pow((dgt.I.y - d.y), 2));
	if (kcachtutamdendiem < dgt.r) return 1;
	return 0;
}
float TinhDienTichPhanGiaoNhauGiua2DuongTron(duongtron dgt1, duongtron dgt2)
{
	// phần này tra trên mạng
	float sgiaonhau = 0.0, d, r1, r2, a, b, GocABC, GocCAB;
	int flag = XetViTriTuongDoiGiua2DuongTron(dgt1, dgt2);
	if (flag != 3)
	{
		return -1;
	}
	else
	{
		 d = TinhKhoangCachGiua2Diem(dgt1.I, dgt2.I);

		 r2 = (dgt1.r > dgt2.r) ? dgt1.r : dgt2.r;
		 r1 = (dgt1.r < dgt2.r) ? dgt1.r : dgt2.r;
		 GocABC = cos(d * d + r2 * r2 - r1 * r1) / (2 * d * r2);
		 GocCAB = cos(d * d + r1 * r1 - r2 * r2) / (2 * d * r1);

		 a = 2 * GocCAB;
		 b = 2 * GocABC;

		sgiaonhau = ((a * r1 * r1) / 2) - (1 / 2 * r1 * r1 * sin(a)) + ((b * r2 * r2) / 2) - (1 / 2 * r2 * r2 * sin(b));
	}
	return abs(sgiaonhau);
}
