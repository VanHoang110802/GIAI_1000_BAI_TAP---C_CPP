/*

Viết chương trình nhập toạ độ 3 đỉnh của một tam giác trong mặt phẳng Oxy. 
Tính diện tích, chu vi và toạ độ trọng tâm của tam giác và xuất kết quả.

S = sqrt(p * (p - a) * (p - b) * (p - c))
Cv = a + b + c
Tọa độ trọng tâm G: lấy từng tọa độ 3 điểm cộng lại / 3 
G.x = (Ax + Bx + Cx) / 3
G.y = (Ay + By + Cy) / 3;
-> có được G(x,y)

*/
#include"TamGiac.h"

int main()
{
	DIEM G;
	TAMGIAC tg;
	NhapTamGiac(tg);
	XuatTamGiac(tg);

	float ChuVi = TinhChuVi(tg);
	float DienTich = TinhDienTich(tg);
	G = TimTrongTam(tg);

	cout << "\nChu vi tam giac la: " << ChuVi;
	cout << "\nDien tich tam giac la: "<< DienTich;

	cout << "\nToa do trong tam G cua tam giac la: (" << G.x << ", " << G.y  << ")";

	return 0;
}
