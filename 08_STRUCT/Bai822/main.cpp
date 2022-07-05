/*
Hãy khai báo kiểu dữ liệu biểu diễn khái niệm phân số trong toán học và đi tính toán:cộng, trừ
nhân, chia nhiều phân số cùng 1 lúc. 
*/

#include"XuLy.h"

int main()
{
	int x = 1;
	PHANSO ps1, ps2, ps3;
	cin >> ps1 >> ps2 >> ps3;
	cout << ps1 << " " << ps2 << " " << ps3;
	
	PHANSO tong = ps1 + ps2 + ps3 + x;
	
	RutGonPS(tong);
	cout << "\nTong = " << tong;

	PHANSO hieu = ps1 - ps2;
	RutGonPS(hieu);
	cout << "\nHieu = " << hieu;

	PHANSO tich = ps1 * ps2;
	RutGonPS(tich);
	cout << "\nTich = " << tich;

	PHANSO thuong = ps1 / ps2;
	RutGonPS(thuong);
	cout << "\nThuong = " << thuong;
	return 0;
}
