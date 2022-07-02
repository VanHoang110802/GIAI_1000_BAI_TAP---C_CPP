/*
Viet chuong trinh quan ly danh sach cac sinh vien trong lop hoc biet thong moi sinh vien gom co:
Ma so, ho ten, ngay sinh, diem toan, li, hoa. Tinh diem trung binh va xuat thong tin sinh vien 
co diem trung binh cao nhat lop.

xac dinh xem, minh can nhung cai lop struct gi?
- Lop ngay, sinh vien, lop hoc.
 */

#include "Lop_Hoc.h"
int main()
{
	 LOPHOC lh;
	 NhapLop(lh);
	 XuatLop(lh);
	 cout << "\nThong tin sinh vien co diem trung binh cao nhat: \n";
	 XuatThongTinCacSinhVienDTBMax(lh);
	 return 0;
}
