/*
Hình cầu trong không gian Oxyz
Khai báo kiểu dữ liệu để biểu diễn hình câu trong không gian Oxyz.
Nhập hình cầu.
Xuất đường cầu theo định dạng ((x,y,z), r).
Tính diện tích xung quanh hình cầu.
Tính thể tích hình cầu.
Xét vị trí tương đối giữa hai hình câu (không cát nhau, tiếp xúc, cắt nhau).
Kiểm tra một toạ độ điểm có nằm bên trong hình cầu hay không.
*/

#include "HinhCau.h"

int main()
{
	hinhcau hc1, hc2;
	diem d;
	NhapHinhCau(hc1);
	NhapHinhCau(hc2);
	XuatHinhCau(hc1);
	cout << "\n";
	XuatHinhCau(hc2);

	float Sxq = TinhDienTichXungQuanhHinhCau(hc1);
	cout << "\nSxq (hc1)= " << Sxq;
	Sxq = TinhDienTichXungQuanhHinhCau(hc2);
	cout << "\nSxq (hc2)= " << Sxq;
	float V = TinhTheTichHinhCau(hc1);
	cout << "\nV (hc1)= "<< V;
	V = TinhTheTichHinhCau(hc2);
	cout << "\nV (hc2)= " << V;
	int flag = XetViTriTuongDoi2HinhCau(hc1, hc2);
	if (flag == 1) cout << "\n2 hinh cau khong cat nhau";
	else if (flag == 2) cout << "\n2 hinh cau tiep xuc nhau";
	else if (flag == 3) cout << "\n2 hinh cau cat nhau";
	NhapDiem(d);

	if (KiemTra1DiemCoNamTrongHinhCau(hc1, d))
	{
		cout << "\nDiem nam trong hinh cau (hc1)";
	}
	else
	{
		cout << "\nDiem nam ngoai hinh cau (hc1)";
	}
	if (KiemTra1DiemCoNamTrongHinhCau(hc2, d))
	{
		cout << "\nDiem nam trong hinh cau (hc2)";
	}
	else
	{
		cout << "\nDiem nam ngoai hinh cau (hc2)";
	}

	return 0;
}
