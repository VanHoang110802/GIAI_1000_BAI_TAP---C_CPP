// Đọc số thành chữ
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
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
		cout <<"bon ";
	else if(x == 5)
		cout <<"nam ";
	else if(x == 6)
		cout <<"sau ";
	else if(x == 7)
		cout <<"bay ";
	else if(x == 8)
		cout <<"tam ";
	else if(x == 9)
		cout <<"chin ";
}

void DocSoCo2ChuSo(int x)
{
	int HangChuc = x / 10;
	int HangDonVi = x % 10;

	if(HangChuc != 1)
	{
		DocSoCo1ChuSo(HangChuc);
		cout <<"muoi ";
	}
	else
		cout <<"muoi ";

	if(HangDonVi != 0)
	{
		if(HangDonVi == 5)
			cout <<"lam ";
		else if(HangChuc > 1 && HangDonVi == 1)
			cout <<"mot ";
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

	cout <<"tram ";

	if(HangChuc != 0)
		DocSoCo2ChuSo(HangChucVaDonVi);
	else
	{
		if(HangDonVi != 0)
		{
			cout <<"le ";
			DocSoCo1ChuSo(HangDonVi);
		}
	}
}

void DocPhuAm(int SoDauPhay)
{
	//if(SoDauPhay == 1 || SoDauPhay == 4 || SoDauPhay == 7 || SoDauPhay == 10 || SoDauPhay == 13)
	if(SoDauPhay % 3 == 1)
		cout <<"nghin ";
	//else if(SoDauPhay == 2 || SoDauPhay == 5 || SoDauPhay == 8 || SoDauPhay == 11 || SoDauPhay == 14)
	else if(SoDauPhay % 3 == 2)
		cout <<"trieu ";
	//else if(SoDauPhay == 3 || SoDauPhay == 6 || SoDauPhay == 9 || SoDauPhay == 12 || SoDauPhay == 15)
	else if(SoDauPhay % 3 == 0 && SoDauPhay != 0)
		cout <<"ty ";
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

void DocSo(long long int n)
{
	if(n < 0)
	{
		n *= -1; // nhân để cho nó thành số dương
		cout <<"am ";
	}
	
	//int SoChuSo = temp_n == 0 ? 1 : (long long int)log10((double)temp_n) + 1; // Dùng hàm log10 này để đi tính số chữ số của 1 số sẽ bị sai với trường hợp 999... (15 chữ số 9) nó quá gần với 10^16 => nó tính ra luôn kết quả là 16 chữ số thay vì chỉ có 15 chữ số
	//cout << "\nSo chu so = " << SoChuSo << endl;

	int SoChuSo = DemSoChuSo(n);

	int SoDauPhay = (SoChuSo - 1) / 3;

	long long int LuyThua = pow(10, 3 * SoDauPhay);
		
	int CumSo = n / LuyThua;
	//cout << CumSo << " => ";

	if(CumSo < 10)
		DocSoCo1ChuSo(CumSo);
	else if(CumSo < 100)
		DocSoCo2ChuSo(CumSo);
	else if(CumSo < 1000)
		DocSoCo3ChuSo(CumSo);

	DocPhuAm(SoDauPhay);

	//cout << endl;
	n %= LuyThua;

	SoDauPhay--;
	
	while(SoDauPhay >= 0)
	{
		LuyThua = pow(10, 3 * SoDauPhay);
		
		//cout << temp_n / LuyThua << endl;
		CumSo = n / LuyThua;
		//cout << CumSo << " => ";

		if(CumSo != 0)
		{
			DocSoCo3ChuSo(CumSo);

			DocPhuAm(SoDauPhay);
		}
		else
		{
			if(SoDauPhay == 3 || SoDauPhay == 6)
				cout <<"ty ";
		}

		//cout << endl;

		n %= LuyThua;

		SoDauPhay--;
	}
}

int main()
{
quaylai:
	// [a, b] => a + rand() % (b - a + 1)
	// [0, 10 tỷ] => 0 + rand() % 1000000001
	long long int n;
	cout << "Nhap vao gia tri so can doc: ";
	cin >> n;
	cout << n << ": ";
	DocSo(n);

	cout <<"\n\nBan co muon tiep tuc khong? Nhan c de tiep tuc!";
	char c = getch();
	if(c == 'c' || c == 'C')
	{
		system("cls");
		goto quaylai;
	}
	return 0;
}
