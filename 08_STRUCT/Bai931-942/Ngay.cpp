#include "Ngay.h"
void NhapNgay(NHAP& nhap)
{
	do
	{
		cout << "\nNhap vao nam: ";
		cin >> nhap.Nam;
		if (nhap.Nam < MinNam)
		{
			cout << "\nDu lieu nam khong hop le. Xin kiem tra lai!\n";
		}
	} while (nhap.Nam < MinNam);

	do
	{
		cout << "\nNhap vao thang: ";
		cin >> nhap.Thang;
		if (nhap.Thang < 1 || nhap.Thang > 12) cout << "\nDu lieu thang khong hop le. Xin kiem tra lai!\n";
	} while (nhap.Thang < 1 || nhap.Thang > 12);

vanhoang:
	cout << "\nNhap ngay: ";
	cin >> nhap.Ngay;
	if (nhap.Thang == 1 || nhap.Thang == 3 || nhap.Thang == 7 || nhap.Thang == 8 || nhap.Thang == 10 || nhap.Thang == 12)
	{
		if ((nhap.Ngay < 1 || nhap.Ngay > 31))
		{
			cout << "\nNgay nhap khong hop le!\n";
			goto vanhoang;
		}
	}

	else if (nhap.Thang == 4 || nhap.Thang == 6 || nhap.Thang == 9 || nhap.Thang == 11)
	{
		if ((nhap.Ngay < 1 || nhap.Ngay > 30))
		{
			cout << "\Ngay nhap khong hop le!\n";
			goto vanhoang;
		}
	}
	else
	{
		if (((nhap.Nam % 4 == 0 && nhap.Nam % 100 != 0) || nhap.Nam % 400 == 0))
		{
			if (nhap.Ngay < 1 || nhap.Ngay > 29)
			{
				cout << "\Ngay nhap khong hop le!\n";
				goto vanhoang;
			}
		}
		else
		{
			if (nhap.Ngay < 1 || nhap.Ngay > 28)
			{
				cout << "\Ngay nhap khong hop le!\n";
				goto vanhoang;
			}
		}
	}
}

void XuatNgay(NHAP nhap)
{
	cout << nhap.Ngay << "/" << nhap.Thang << "/" << nhap.Nam;
}

int KiemTraNamNhuan(NHAP nhap)
{
	return (nhap.Nam % 4 == 0 && nhap.Nam % 100 != 0) || (nhap.Nam % 400 == 0);
}

int TinhSoThuTuNgayTrongNam(NHAP nhap)
{
	int SoNgay = nhap.Ngay;
	for (int i = 1; i < nhap.Thang; i++)
	{
		if (i == 4 || i == 6 || i == 9 || i == 1) SoNgay += 30;
		else if (i == 2) SoNgay += (nhap.Nam % 4 == 0 && nhap.Nam % 100 != 0 || nhap.Nam % 400 == 0) ? 29 : 28;
		else SoNgay += 31;
	}
	return SoNgay;
}
int CheckYear(int i)
{
	if (i % 4 == 0 && i % 100 != 0) return 1;
	if (i % 400 == 0) return 1;
	return 0;
}
int TinhSoThuTuNgayTuNgayChoTruoc(NHAP nhap)
{
	int stt = 0;
	for (int i = 1; i < nhap.Nam; i++)
	{
		if (CheckYear(i))
		{
			stt += 366;
		}
		else
		{
			stt += 365;
		}
	}
	return stt + TinhSoThuTuNgayTrongNam(nhap);
}
int TimNgayKhiBietNamVaSoThuTuNgayTrongNam(int Year, int tim)
{
	int n[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (CheckYear(Year)) n[1] = 29;
	for (int i = 0; i < 12; i++)
	{
		if (n[i] < tim) tim -= n[i];
		else break;
	}
	return tim;
}
int TimNgayKhiBietSoThuTuNgayChoTruoc(int tim)
{
	int Year = 1;
	while (1)
	{
		if (CheckYear(Year))
		{
			if (tim > 366)
			{
				tim -= 366;
			}
			else
			{
				return TimNgayKhiBietNamVaSoThuTuNgayTrongNam(Year, tim);
			}
		}
		else
		{
			if (tim > 365)
			{
				tim -= 365;
			}
			else
			{
				return TimNgayKhiBietNamVaSoThuTuNgayTrongNam(Year, tim);
			}
		}
		Year++;
	}
	return -1;
}

int TimSoNgayTrongThang(NHAP nhap)
{
	int NgayTrongThang;
	if (nhap.Thang == 1 || nhap.Thang == 3 || nhap.Thang == 5 || nhap.Thang == 7 || nhap.Thang == 8 || nhap.Thang == 10 || nhap.Thang == 12)
	{
		NgayTrongThang = 31;
	}
	else if (nhap.Thang == 4 || nhap.Thang == 6 || nhap.Thang == 9 || nhap.Thang == 11)
	{
		NgayTrongThang = 30;
	}
	else
	{
		int Check = KiemTraNamNhuan(nhap);
		if (Check == 1)
		{
			NgayTrongThang = 29;
		}
		else
		{
			NgayTrongThang = 28;
		}
	}
	return NgayTrongThang;
}

NHAP TimNgayKeTiep(NHAP nhap)
{
	int NgayTrongThang = TimSoNgayTrongThang(nhap);
	if (nhap.Ngay < NgayTrongThang)  // Tăng ngày lên
	{
		nhap.Ngay++;
	}
	else if (nhap.Thang < 12)     // Ngày kế tiếp là đầu tháng
	{
		nhap.Ngay = 1;
		nhap.Thang++;
	}
	else                      // Ngày kế là đầu năm mới tức là hiện tai đang là tháng 12
	{
		nhap.Ngay = nhap.Thang = 1;
		nhap.Nam++;
	}
	return nhap;
}
//602 Tìm ngày hôm trước
NHAP TimNgayHomQua(NHAP nhap)
{
	int NgayTrongThang = TimSoNgayTrongThang(nhap);
	if (nhap.Ngay == 1)            // Nếu ngày nhập vào là 1
	{
		nhap.Ngay = NgayTrongThang;        // ngày trước đó là số ngày trong tháng trước 
		if (nhap.Thang == 1)            // Nếu tháng là 1
		{
			nhap.Nam = 12;
			nhap.Nam--;
		}
		else nhap.Thang--;                // Tháng khác 1
	}
	else  nhap.Ngay--;            // Ngày khác 1

	return nhap;
}

NHAP TimNgayKeDoKNgay(NHAP nhap, int k)
{
	while (k > 0)
	{
		nhap = TimNgayKeTiep(nhap);
		k--;
	}
	return nhap;
}

NHAP TimNgayTruocDoKNgay(NHAP nhap, int k)
{
	while (k > 0)
	{
		nhap = TimNgayHomQua(nhap);
		k--;
	}
	return nhap;
}
//605 Khoảng cách giữa 2 ngày
int TimKhoangCach2Ngay(NHAP nhap1, NHAP nhap2)
{
	int tim1 = TinhSoThuTuNgayTrongNam(nhap1);
	int tim2 = TinhSoThuTuNgayTrongNam(nhap2);

	if (tim1 > tim2)
	{
		return tim1 - tim2;
	}
	return tim2 - tim1;
}

int SoSanh2Ngay(NHAP nhap1, NHAP nhap2)
{
	int tim1 = TinhSoThuTuNgayTrongNam(nhap1);
	int tim2 = TinhSoThuTuNgayTrongNam(nhap2);

	if (tim1 > tim2)
	{
		return 1;
	}
	if (tim2 > tim1)
	{
		return 0;
	}
	return -1;
}
/*
Sử dụng công thức Zeller: dayofweek = (d + y + y/4 - y/100 + y/400 + (31*m)/12) % 7
	với a = (14 - month) / 12
	y = year - a;
	m = month + 12*a - 2
*/
void TinhThuTrongTuanCua1NgayBatKyTrongNam(NHAP nhap)
{
	nhap.Nam -= (14 - nhap.Thang) / 12;
	nhap.Thang += 12 * ((14 - nhap.Thang) / 12) - 2;

	int dayofweek = (nhap.Ngay + nhap.Nam + nhap.Nam / 4 - nhap.Nam / 100 + nhap.Nam / 400 + (31 * nhap.Thang) / 12) % 7;

	if (!dayofweek) printf("\nChu nhat");
	else printf("\nThu %d", dayofweek + 1);
}
