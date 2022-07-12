#include "HinhTamGiac.h"

int KiemTraCoPhaiTamGiac(tamgiac tg)
{
	float AB, BC, AC;
	AB = TinhKhoangCachGiua2Diem(tg.A, tg.B);
	BC = TinhKhoangCachGiua2Diem(tg.B, tg.C);
	AC = TinhKhoangCachGiua2Diem(tg.A, tg.C);
	if (AB + BC <= AC || AB + AC <= BC || AC + BC <= AB) return 0;
	return 1;
}
void NhapHinhTamGiac(tamgiac& tg)
{
	int Check;
	do 
	{
		cout << "\nNhap dinh A: "; NhapDiem(tg.A);
		cout << "\nNhap dinh B: "; NhapDiem(tg.B);
		cout << "\nNhap dinh C: "; NhapDiem(tg.C);
		Check = KiemTraCoPhaiTamGiac(tg);
		if (Check == 0)
		{
			cout << "\n3 diem khong tao thanh tam giac. Xin kiem tra lai!\n";
		}
	} while (Check == 0);
}
void XuatHinhTamGiac(tamgiac tg)
{
	cout << "(<" << tg.A.x << ", " << tg.A.y << ">, <" << tg.B.x << ", " << tg.B.y << ">, <" << tg.C.x << ", " << tg.C.y << ">)";
}

float TinhChuViTamGiac(tamgiac tg)
{
	float AB, BC, AC;
	AB = TinhKhoangCachGiua2Diem(tg.A, tg.B);
	BC = TinhKhoangCachGiua2Diem(tg.B, tg.C);
	AC = TinhKhoangCachGiua2Diem(tg.A, tg.C);
	return AB + BC + AC;
}
float TinhDienTichTamGiac(tamgiac tg)
{
	float AB, BC, AC, P;
	AB = TinhKhoangCachGiua2Diem(tg.A, tg.B);
	BC = TinhKhoangCachGiua2Diem(tg.B, tg.C);
	AC = TinhKhoangCachGiua2Diem(tg.A, tg.C);
	P = TinhChuViTamGiac(tg) / 2;
	return sqrt(P * (P - AB) * (P - AC) * (P - BC));
}
diem TimToaDoTrongTamTamGiac(tamgiac tg)
{
	diem G;
	G.x = (tg.A.x + tg.B.x + tg.C.x) / 3;
	G.y = (tg.A.y + tg.B.y + tg.C.y) / 3;
	return G;
}
diem TimDinhCoHoanhDoLonNhat(tamgiac tg)
{
	diem I; // Mặc định điểm có hoành độ lớn nhất 
	I.x = tg.A.x > tg.B.x ? tg.A.x : tg.B.x;
	I.x = I.x > tg.C.x ? I.x : tg.C.x;

	if (I.x == tg.A.x) I.y = tg.A.y;
	else if (I.x == tg.B.x) I.y = tg.B.y;
	else if (I.x = tg.C.x) I.y = tg.C.y;
	return I;
}
diem TimDinhCoTungDoNhoNhat(tamgiac tg)
{
	diem J;	// Mặc định điểm có hoành độ nhỏ nhất 
	J.y = tg.A.y < tg.B.y ? tg.A.y : tg.B.y;
	J.y = J.y < tg.C.y ? J.y : tg.C.y;

	if (J.y == tg.A.y) J.x = tg.A.x;
	else if (J.y = tg.B.y) J.x = tg.B.x;
	else if (J.y = tg.C.y) J.x = tg.C.x;
	return J;
}
float TinhKhoangCachTuPToi3Dinh(tamgiac tg, diem d)
{
	float PA = TinhKhoangCachGiua2Diem(tg.A, d);
	float PB = TinhKhoangCachGiua2Diem(tg.B, d);
	float PC = TinhKhoangCachGiua2Diem(tg.C, d);
	return PA + PB + PC;
}

float XetViTriTuongDoiGiuaDiemVaDuongThang(diem d1, diem d2, diem d3)
{
	return (d1.x - d3.x) * (d2.y - d3.y) - (d2.x - d3.x) * (d1.y - d3.y);
}
int KiemTra1DiemCoNamTrongTamGiac(tamgiac tg, diem d)
{
/*
dùng phương pháp xét vị trí điểm D so với 3 cạnh.
Điểm D nếu nằm trong tam giác nếu nó thuộc 1 trong ba cạnh hoặc ở trên(hay bên trái) 2 cạnh và dưới (hay bên phải) 1 cạnh hoặc dưới hai cạnh và trên 1 cạnh.

Để xét điểm nằm trên hay dưới đường thẳng qua hai điểm (x1,y1), (x2,y2) ta dùng công thức sau:
Vector v1 = {x2-x1, y2-y1}
Vector v2 = {x2-xA, y2-yA}
Tính xp = v1.x*v2.y - v1.y*v2.x  // Cross product
Nếu xp > 0  bên trên. Ngược lại Nếu xp < 0 bên dưới. Ngược lại thuộc đường thẳng
*/
	diem d1 = tg.A;
	diem d2 = tg.B;
	diem d3 = tg.C;
	int check1, check2, check3;

	check1 = XetViTriTuongDoiGiuaDiemVaDuongThang(d, d1, d2) < 0.0f;
	check2 = XetViTriTuongDoiGiuaDiemVaDuongThang(d, d2, d3) < 0.0f;
	check3 = XetViTriTuongDoiGiuaDiemVaDuongThang(d, d3, d1) < 0.0f;

	return ((check1 == check2) && (check2 == check3));
}
int DangTamGiac(tamgiac tg)
{
	float AB, BC, AC, P;
	AB = TinhKhoangCachGiua2Diem(tg.A, tg.B);
	BC = TinhKhoangCachGiua2Diem(tg.B, tg.C);
	AC = TinhKhoangCachGiua2Diem(tg.A, tg.C);

	int check = 0;
	if (AB == BC && AC == BC)
	{
		check = 1;  // đều
	}
	else
	{
		if (AB * AB + BC * BC == AC * AC || AC * AC + BC * BC == AB * AB || AB * AB + AC * AC == BC * BC)
		{
			check = 2;  // vuông
		}
		if (AB == BC || AC == BC || AB == AC)
		{
			check = 3;   // cân
		}
		else
		{
			check = 4;   // thường
		}
	}
	return check;
}
