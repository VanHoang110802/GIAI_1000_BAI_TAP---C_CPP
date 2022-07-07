/*

Viết chương trình nhập toạ độ tâm và bán kính của một đường tròn trong mặt phẳng Oxy. 
Tính diện tích và chu vi của nó và xuất ra kết quả.
S = r * r * 3.14
Cv = 2 * 3.14 * r

*/
#include <conio.h>
#include"DuongTron.h"

int main()
{
	while (_getch())
	{
		cout << "\n\n";
		DIEM d;
		DUONGTRON dt;
		NhapDuongTron(dt);
		XuatDuongTron(dt);
		float DienTich = TinhDienTich(dt);
		float ChuVi = TinhChuVi(dt);

		cout << "\nDien tich hinh tron la: " << DienTich;
		cout << "\nChu vi hinh tron la: " << ChuVi;
	}
	return 0;
}
