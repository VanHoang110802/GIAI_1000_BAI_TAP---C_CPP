/*
Viet chuong trinh quan ly danh sach cac sinh vien trong lop hoc biet thong moi sinh vien gom co:
Ma so, ho ten, ngay sinh, diem toan, li, hoa. Tinh diem trung binh va xuat thong tin sinh vien 
co diem trung binh cao nhat lop.

xac dinh xem, minh can nhung cai lop struct gi?
- Lop ngay, sinh vien, lop hoc.
 */

#include "Sinh_Vien.h"
int main()
{
	 SINHVIEN sv;
	 NhapSinhVien(sv);
	 XuatSinhVien(sv);
	 float dtb = DiemTB(sv);
	 cout << "\nDiem trung binh mon : " << dtb;
	 return 0;
}
