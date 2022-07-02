/*

Cho hai mảng a, b. Hãy cho biết mảng b có phải là hoán vị của mảng a hay không?

Hãy sắp xếp các số dương trong mảng các số thực tăng dần các số âm giữ nguyên vị trí của chúng trong mảng.
Ví dụ:
14.0 -45.7 23.0 13.5 43.1 -12.9
Mảng sau khi sắp các số dương tăng
13.5 -45.7 14.0 23.0 43.1 -12.9

Hãy sắp xếp các số chẵn trong mảng các số nguyên tăng dần, các số lẻ cũng tăng dần. Vị trí tương đối giữa các số chẵn 
và số lẻ không đổi.

Hãy sắp xếp các số dương trong mảng tăng dần, các số âm giảm dần, vị trí tương đối giữa các số âm và số dương không đổi.
*/
#include <iostream>
using namespace std;
template <typename vanhoang>
void NhapDuLieu(vanhoang& n)
{
	do 
	{
		cout << "Nhap so luong phan tu: ";
		cin >> n;
		if (n<1) 
		{
			cout << "\nSo luong phan tu nhap khong hop le, xin hay kiem tra lai!\n";
		}
	} while (n<1);
}
template <typename vanhoang>
void NhapMang(vanhoang *a, int n)
{
	for (int i = 0; i < n; ++i) 
	{
		cout << "a[" << i<<"] = ";
		cin >> a[i];
	}
}
template <typename vanhoang>
void XuatMang(vanhoang *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
}
//----------------------------------------------------------------------------------
/*
nếu số lượng phần tử không bằng nhau thì không phải luôn
còn nếu số lượng bằng nhau thì ta sẽ sắp xếp các phần tử theo hoặc tăng dần hoặc giảm dần, rồi so sánh xem các phần tử trong 2 mang sau khi sắp xếp đó, nếu có 1 phần tử nào khác nhau thì cũng kết luận là cũng không phải luôn.
*/
template <typename vanhoang>
void HoanVi(vanhoang& a, vanhoang& b)
{
	vanhoang temp = a;
	a = b;
	b = temp;
}
template <typename vanhoang>
void SapXepTangDan(vanhoang *a, int n)
{
	for (int i = 0; i < n - 1; i++) 
	{
		for (int j = i + 1; j < n; j++) 
		{
			if (a[i] > a[j]) {
				HoanVi(a[i], a[j]);
			}
		}
	}
}
template <typename vanhoang>
int KiemTraBCoPhaiLaHoanViCuaA(vanhoang *a, vanhoang *b, int na, int nb)
{
	if (na != nb) 
	{      // Số lượng phần tử phải bằng nhau
		return 0;
	}
	SapXepTangDan(a, na);           // Sắp xếp mảng a
	SapXepTangDan(b, nb);           // Sắp xếp mảng b
	for (int i = 0; i < na; i++)
	{
		if (a[i] != b[i]) 
		{
			return 0;
		}
	}
	return 1;
}
//--------------------------------------------------------------------------------
void SapXepSoDuongTangDan(int *a, int n) 
{
	for (int i = 0; i < n - 1; i++) 
	{
		if (a[i] > 0) 
		{
			for (int j = i + 1; j < n; j++) 
			{
				if (a[i] > 0 && a[i] > a[j]) 
				{
					HoanVi(a[i], a[j]);
				}
			}
		}
	}
}
//--------------------------------------------------------------------------------
void SapXepChanLeTangDan(int *a, int n)
{
	for (int i = 0; i < n - 1; i++) 
	{
		if (a[i] > 0)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (((a[i] % 2 == 0 && a[j] % 2 == 0) || (a[i] % 2 != 0 && a[j] % 2 != 0)) && a[i] > a[j]) 
				{
					HoanVi(a[i], a[j]);
				}
			}
		}
	}
}
//-------------------------------------------------------------------------------
void SapXepSoDuongTangDanVaSoAmGiamDan(int *a, int n) 
{
	for (int i = 0; i < n - 1; i++) 
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > 0 && a[j] > 0 && a[i] > a[j])
			{
				HoanVi(a[i], a[j]);
			}
			else if (a[i] < 0 && a[j] < 0 && a[i] < a[j])
			{
				HoanVi(a[i], a[j]);
			}
		}
	}
}
int main()
{
	/*int na, nb;
	NhapDuLieu(na);
	int* a = new int[na];
	NhapMang(a, na);
	NhapDuLieu(nb);
	int* b = new int[nb];
	NhapMang(b, nb);
	XuatMang(a, na);
	cout << "\n\n";
	XuatMang(b, nb);
	cout << "\n\n";
	int kt = KiemTraBCoPhaiLaHoanViCuaA(a, b, na, nb);
	cout << kt;
	delete[]a;
	delete[]b;*/
	int n;
	NhapDuLieu(n);
	int* a = new int[n];
	NhapMang(a, n);
	XuatMang(a, n);
	//SapXepSoDuongTangDan(a, n);
	//SapXepChanLeTangDan(a, n);
	SapXepSoDuongTangDanVaSoAmGiamDan(a, n);
	cout << "\n\n";
	XuatMang(a, n);
	delete[]a;
	return 0;
}
