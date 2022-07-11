/*
Ngày
Khai báo kiểu dữ liệu để biểu diễn ngày.
Nhập ngày.
Xuất ngày theo định dạng (ngày/tháng/năm).
Kiểm tra năm nhuận.
Tính số thứ tự ngày trong năm.
Tính số thứ tự ngày kể từ ngày 1/1/1.
Tìm ngày khi biết năm và số thứ tự của ngày trong năm.
Tìm ngày khi biết số thứ tự ngày kể từ ngày 1/1/1.
Tìm ngày kế tiếp.
Tìm ngày hôm qua.
Tìm ngày kế đó k ngày.
Tìm ngày trước đó k ngày.
Khoảng cách giữa hai ngày.
So sánh hai ngày.
Tính thứ trong tuần của 1 ngày bất kì
*/

#include "Ngay.h"
int main()
{
	NHAP nhap, nhap1;
	NhapNgay(nhap);
	XuatNgay(nhap);

	if (KiemTraNamNhuan(nhap)) printf("\nNam %d la nam nhuan", nhap.Nam);
	else printf("\nNam %d la nam thuong", nhap.Nam);


	int TinhSTT = TinhSoThuTuNgayTrongNam(nhap);
	printf("\nNgay thu %d trong nam", TinhSTT);

	TinhSTT = TinhSoThuTuNgayTuNgayChoTruoc(nhap);
	printf("\nNgay thu %d trong nam tu ngay 1/1/1", TinhSTT);

	int Tim = TimNgayKhiBietNamVaSoThuTuNgayTrongNam(2015, 365);
	printf("\nNgay thu %d trong nam %d la ngay %d", 365, 2015, Tim);

	NhapNgay(nhap1);
	nhap1 = TimNgayKeTiep(nhap1);
	printf("\nNgay ke tiep la ngay %d/%d/%d", nhap1.Ngay, nhap1.Thang, nhap1.Nam);

	nhap1 = TimNgayHomQua(nhap1);
	printf("\nNgay hom qua la ngay %d/%d/%d", nhap1.Ngay, nhap1.Thang, nhap1.Nam);

	printf("\nNgay ke tiep 5 ngay: ");
	XuatNgay(TimNgayKeDoKNgay(nhap1, 5));
	printf("\nNgay hom truoc 5 ngay: ");
	XuatNgay(TimNgayTruocDoKNgay(nhap1, 5));

	TinhThuTrongTuanCua1NgayBatKyTrongNam(nhap1);

	return 0;
}
