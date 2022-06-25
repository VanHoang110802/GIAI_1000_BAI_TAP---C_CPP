/* 
Khi xuất ra số cần đọc thành chữ thì số xuất ra phải tự ngăn cách những dấu phẩy để cho người sử dụng chương trình dễ dò bằng mắt thay vì phải ngồi duyệt tay
vd: Nhập vào số: 123456789987654321
Kết quả xuất ra màn hình sẽ trông như thế này:
123,456,789,987,654,321: mot tram hai muoi ba trieu bon tram nam muoi sau nghin bay tram tam muoi chin ty chin tram tam muoi bay trieu sau tram nam muoi bon nghin ba tram hai muoi mot
*/

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
using namespace std;

void DocSoCo1ChuSo(int x)
{
	if(x == 0)
		cout << "khong ";
	else if(x == 1)
		cout << "mot ";
	else if(x == 2)
		cout << "hai ";
	else if(x == 3)
		cout << "ba ";
	else if(x == 4)
		cout << "bon ";
	else if(x == 5)
		cout << "nam ";
	else if(x == 6)
		cout << "sau ";
	else if(x == 7)
		cout << "bay ";
	else if(x == 8)
		cout << "tam ";
	else if(x == 9)
		cout << "chin ";
}

void DocSoCo2ChuSo(int x)
{
	int HangChuc = x / 10;
	int HangDonVi = x % 10;

	if(HangChuc != 1)
	{
		DocSoCo1ChuSo(HangChuc);
		cout << "muoi ";
	}
	else
		cout << "muoi ";

	if(HangDonVi != 0)
	{
		if(HangDonVi == 5)
			cout << "lam ";
		else if(HangChuc > 1 && HangDonVi == 1)
			cout << "mot ";
		else
			DocSoCo1ChuSo(HangDonVi);
	}
}

void DocSoCo3ChuSo(int x)
{
	int HangTram = x / 100;
	int HangChucVaDonVi = x % 100;
	int HangChuc = HangChucVaDonVi / 10;
	int HangDonVi = HangChucVaDonVi % 10;

	DocSoCo1ChuSo(HangTram);

	cout << "tram ";

	if(HangChuc != 0)
		DocSoCo2ChuSo(HangChucVaDonVi);
	else
	{
		if(HangDonVi != 0)
		{
			cout << "le ";
			DocSoCo1ChuSo(HangDonVi);
		}
	}
}

void DocPhuAm(int SoDauPhay)
{
	//if(SoDauPhay == 1 || SoDauPhay == 4 || SoDauPhay == 7 || SoDauPhay == 10 || SoDauPhay == 13)
	if(SoDauPhay % 3 == 1)
		cout << "nghin ";
	//else if(SoDauPhay == 2 || SoDauPhay == 5 || SoDauPhay == 8 || SoDauPhay == 11 || SoDauPhay == 14)
	else if(SoDauPhay % 3 == 2)
		cout << "trieu ";
	//else if(SoDauPhay == 3 || SoDauPhay == 6 || SoDauPhay == 9 || SoDauPhay == 12 || SoDauPhay == 15)
	else if(SoDauPhay % 3 == 0 && SoDauPhay != 0)
		cout << "ty ";
}

int DemSoChuSo(long long int x)
{
	/*int dem = 0;
	
	if(x == 0)
		dem = 1;*/

	int dem = x == 0 ? 1 : 0;

	while(x != 0)
	{
		x /= 10;
		dem++;
	}
	return dem;
}

void PhanCachDauPhayGiuaCacCumSo(long long int n)
{
	if(n < 0)
	{
		n *= -1; // nhân để cho nó thành số dương
		cout << "-";
	}

	int SoChuSo = DemSoChuSo(n);

	int SoDauPhay = (SoChuSo - 1) / 3;

	long long int LuyThua = pow(10, 3 * SoDauPhay);
		
	int CumSo = n / LuyThua;
	cout << CumSo;

	n %= LuyThua;

	SoDauPhay--;
	
	while(SoDauPhay >= 0)
	{
		LuyThua = pow(10, 3 * SoDauPhay);
		
		CumSo = n / LuyThua;
		cout << ",";
		printf("%03d", CumSo); // %03d nghĩa là xuất ra số phải đủ 3 chữ số, nếu không đủ 3 chữ số thì xuất kèm theo ở trước đó những chữ số 0 sao cho gom đủ thành 3 chữ số
		
		/*
		// Đoạn code này sẽ dùng nếu như không nhớ được hay không biết hàm wprintf với định dạng %03d ở trên
		if(DemSoChuSo(CumSo) == 1)
			cout << "00";
		else if(DemSoChuSo(CumSo) == 2)
			cout << "0";

		cout << CumSo;
		*/

		n %= LuyThua;

		SoDauPhay--;
	}
}

void DocSoThanhChu(long long int n)
{
	if(n < 0)
	{
		n *= -1; // nhân để cho nó thành số dương
		cout << "am ";
	}

	int SoChuSo = DemSoChuSo(n);

	int SoDauPhay = (SoChuSo - 1) / 3;

	long long int LuyThua = pow(10, 3 * SoDauPhay);
		
	int CumSo = n / LuyThua;

	if(CumSo < 10)
		DocSoCo1ChuSo(CumSo);
	else if(CumSo < 100)
		DocSoCo2ChuSo(CumSo);
	else if(CumSo < 1000)
		DocSoCo3ChuSo(CumSo);

	DocPhuAm(SoDauPhay);

	n %= LuyThua;

	SoDauPhay--;
	
	while(SoDauPhay >= 0)
	{
		LuyThua = pow(10, 3 * SoDauPhay);
		
		CumSo = n / LuyThua;
	
		if(CumSo != 0)
		{
			DocSoCo3ChuSo(CumSo);

			DocPhuAm(SoDauPhay);
		}
		else
		{
			if(SoDauPhay == 3 || SoDauPhay == 6)
				cout << "ty ";
		}

		n %= LuyThua;

		SoDauPhay--;
	}
}

int main()
{
	cout << "Moi ban nhap vao gia tri so: " << endl;
	char c;
	long long int number = 0;
	long long int Maximum_Value_Type = (long long int)pow(2, 8 * sizeof(number) - 1) - 1;
	while(true)
	{
		c = getch();
		
		if((c >= '0' && c <= '9') || c == 8)
		{
			if(c >= '0' && c <= '9')
			{
				if(number > (Maximum_Value_Type - ((int)c - 48)) / 10)
				{
					cout << "\nBan da vuot qua luu tru!";
					Sleep(1000);
				}
				else
					number = number * 10 + (c - 48);
			}
			else if(c == 8) // back space
			{
				number /= 10; // bỏ đi chữ số cuối
			}
			system("cls");
			cout << "Moi ban nhap vao gia tri so: " << endl;
			PhanCachDauPhayGiuaCacCumSo(number);
			cout << endl;
			DocSoThanhChu(number);
		}
	}
	return 0;
}
