#include "HonSo.h"
void NhapHonSo(HONSO& hs)
{
	cout << "Nhap phan nguyen: ";
	cin >> hs.PhanNguyen;
	cout << "Nhap phan tu so: ";
	cin >> hs.TuSo;
	do
	{
		cout << "Nhap phan mau so: ";
		cin >> hs.MauSo;
		if (hs.MauSo == 0)
		{
			cout << "\nMau so khong hop le!\n";
		}
	} while (hs.MauSo == 0);
}
void XuatHonSo(HONSO hs)
{
	cout << hs.PhanNguyen << "("  << hs.TuSo << "/" << hs.MauSo << ")";
}
int TimUCLN(int a, int b)
{
	if (a < 0)
	{
		a = a * -1;
	}
	if (b < 0)
	{
		b = b * -1;
	}

	if (a == 0 && b != 0)
	{
		return b;
	}
	else if (b == 0 && a != 0)
	{
		return a;
	}

	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
			b = b - a;
	}
	return a;
}
HONSO RutGonHonSo(HONSO hs)
{
	//đổi hỗn số về phân số rồi thực hiện phép chia tử cho mẫu của phân số vừa đưa về
	if (hs.TuSo > hs.MauSo)
	{
		int temp = hs.TuSo / hs.MauSo;
		hs.PhanNguyen += temp;
		hs.TuSo -= hs.MauSo * temp;
	}
	int UCLN = TimUCLN(hs.TuSo, hs.MauSo);
	hs.TuSo /= UCLN;
	hs.MauSo /= UCLN;
	return hs;
}
HONSO TinhTong(HONSO hs1, HONSO hs2)
{
	/* để tính được tổng hỗn số thì ta phải:
	Phần nguyên cộng phần nguyên, tử = tử nhân mẫu rồi cộng với nhau
	phần mẫu nhân với nhau thôi.
	*/
	HONSO temp;
	temp.PhanNguyen = hs1.PhanNguyen + hs2.PhanNguyen;
	temp.TuSo = hs1.TuSo * hs2.MauSo + hs1.MauSo * hs2.TuSo;
	temp.MauSo = hs1.MauSo * hs2.MauSo;
	temp = RutGonHonSo(temp);
	return temp;
}
HONSO TinhHieu(HONSO hs1, HONSO hs2)
{
	HONSO temp;
	temp.PhanNguyen = hs1.PhanNguyen - hs2.PhanNguyen;
	temp.TuSo = hs1.TuSo * hs2.MauSo - hs1.MauSo * hs2.TuSo;
	temp.MauSo = hs1.MauSo * hs2.MauSo;
	temp = RutGonHonSo(temp);
	return temp;
}
HONSO TinhTich(HONSO hs1, HONSO hs2)
{
	// Đưa về dạng phân số
	hs1.TuSo = hs1.TuSo + hs1.PhanNguyen * hs1.MauSo;
	hs2.TuSo = hs2.TuSo + hs2.PhanNguyen * hs2.MauSo;

	HONSO temp;
	temp.PhanNguyen = 0;
	temp.TuSo = hs1.TuSo * hs2.TuSo;
	temp.MauSo = hs1.MauSo * hs2.MauSo;
	temp = RutGonHonSo(temp);
	return temp;
}
HONSO TinhThuong(HONSO hs1, HONSO hs2)
{
	// Đưa về dạng phân số
	hs1.TuSo = hs1.TuSo + hs1.PhanNguyen * hs1.MauSo;
	hs2.TuSo = hs2.TuSo + hs2.PhanNguyen * hs2.MauSo;

	HONSO temp;
	temp.PhanNguyen = 0;
	temp.TuSo = hs1.TuSo * hs2.MauSo;
	temp.MauSo = hs1.MauSo * hs2.TuSo;
	temp = RutGonHonSo(temp);
	return temp;
}
int KiemTraToiGian(HONSO hs)
{
	int UCLN = TimUCLN(hs.TuSo, hs.MauSo);
	if (UCLN == 1)
	{
		return 1;
	}
	return 0;
}
void QuyDong2HS(HONSO &hs1, HONSO &hs2)
{
	HONSO temp = hs1;
	hs1.TuSo = hs1.TuSo * hs2.MauSo;
	hs1.MauSo = hs1.MauSo * hs1.MauSo;
	hs2.TuSo = hs2.TuSo * temp.MauSo;
	hs2.MauSo = temp.MauSo * hs2.MauSo;
}
