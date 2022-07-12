/*
Tam giác trong mặt phẳng Oxy
Khai báo kiểu dữ liệu để biểu diễn tam giác trong mặt phẳng Oxy.
Nhập tam giác.
Xuất tam giác theo định dạng như sau: ((x1,y1;(x2,y2);(x3,y3)).
Kiểm tra tọa độ 3 đỉnh có thật sự lập thành 3 đỉnh của một tam giác hay không?
Tính chu vi tam giác.
Tính diện tích tam giác.
Tính toạ độ trọng tâm của tam giác.
Tìm một đỉnh trong tam giác có hoành độ lớn nhất.
Tìm một đỉnh trong tam giác có tung độ nhỏ nhất.
Tính tổng khoảng cách từ điểm P(x, y) tới 3 đỉnh của tam giác.
Kiểm tra một toạ độ điểm có nằm trong tam giác hay không.
Hãy cho biết dạng của tam giác (đều, vuông, vuông cân, cân, thường).
*/

#include "HinhTamGiac.h"

int main()
{
	tamgiac tg;

	NhapHinhTamGiac(tg);

	XuatHinhTamGiac(tg);

	float ChuVi = TinhChuViTamGiac(tg);
	float DienTich = TinhDienTichTamGiac(tg);

	diem G = TimToaDoTrongTamTamGiac(tg);

	cout << "\nChu vi tam giac la: "<< ChuVi;
	cout << "\nDien tich tam giac la: "<< DienTich;
	cout << "\nToa do trong tam tam giac la <" << G.x << ", " << G.y << ">";

	diem I = TimDinhCoHoanhDoLonNhat(tg);
	cout << "\nDinh co hoanh do lon nhat la: ";
	XuatDiem(I);

	diem J = TimDinhCoTungDoNhoNhat(tg);
	printf("\nDinh co tung do nho nhat la: ");
	XuatDiem(J);

	float KhoangCach = TinhKhoangCachTuPToi3Dinh(tg, G);
	cout << "\nkhoang cach la: " << KhoangCach;

	int  dang = DangTamGiac(tg);

	if (dang == 1)
	{
		cout << "\nTam giac thuong";
	}
	else
	{
		if (dang == 2)
		{
			cout << "\nTam giac vuong ";
		}
		if (dang == 3)
		{
			cout << "\nTam giac can";
		}
		else
		{
			cout << "\nTam giac thuong";
		}
	}

	if (KiemTra1DiemCoNamTrongTamGiac(tg, G))
	{
		cout << "\nCo diem nam trong tam giac";
	}
	else
	{
		cout << "\nKhong co diem nam trong tam giac";
	}
	return 0;
}
