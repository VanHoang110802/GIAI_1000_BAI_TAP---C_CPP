/*
Hãy đưa các số chẵn trong mảng về đầu mảng, số lẻ về cuối mảng và các phần tử 0 năm ở giữa.

Hãy đảo ngược mảng ban đầu.

Hãy đảo ngược thứ tự các số chẵn có trong mảng.

Hãy đảo ngược thứ tự các số dương có trong mảng.

Hãy đảo ngược thứ tự các số chẵn và các số lẻ trong mảng mà vẫn giữ nguyên vị trí tương đối của chúng.

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
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << "  ";
	}
}
//----------------------------------------------------------------------------------
void DoiChoDuaChanVeDau(int *a, int ViTriDoi) 
{
	int tam = a[ViTriDoi];           // biến tạm lưu tất cả các giá trị thỏa ĐK đổi
	for (int i = ViTriDoi; i > 0; --i)
	{
		a[i] = a[i - 1];
	}
	a[0] = tam;
}
void Dua0VaoGiua(int *a, int ViTriDoi, int ViTriChanCuoi) 
{
	// Do 0 nằm giữa mảng nên 0 sẽ là giá trị chẵn cuối để thỏa yêu cầu bài toán
	for (int i = ViTriDoi; i > ViTriChanCuoi; --i)
	{
		a[i] = a[i - 1];
	}
	a[ViTriChanCuoi] = 0;
}
void DuaChanVeDauLeVeCuoi(int *a, int n) 
{
	int i, dem;
	int ViTriChanCuoi = 0;
	for (i = 0; i < n; ++i) 
	{
		if (a[i] % 2 == 0 && a[i] != 0) 
		{
			DoiChoDuaChanVeDau(a, i);
		}
	}
	for (i = 0; i < n; ++i) 
	{
		if (a[i] % 2 != 0)
		{
			ViTriChanCuoi = i;
			break;
		}
	}
	for (i; i < n; i++) 
	{	// bỏ khởi tạo i để tránh dư 1 số 0 
		if (a[i] == 0) 
		{
			Dua0VaoGiua(a, i, ViTriChanCuoi);
		}
	}
}
//--------------------------------------------------------------------------------
/*
mảng: 1 2 3 4 5
	  5 4 3 2 1
khởi tạo i là vị trí của phần tử đầu tiên, j là vị trí của phần tử cuối cùng, nếu phần tử i còn nhỏ hơn j thì hoán vị lại vị trí cho nhau, cứ như thế xét duyệt cho đến hết các phần tử trong mảng thì được mảng mới sẽ bị đảo ngược.
*/
void HoanVi(int& a, int& b)
{
	int tam = a;
	a = b;
	b = tam;
}

void DaoMang(int *a, int n) 
{
	for (int i = 0; i < n - 1; ++i) 
	{
		for (int j = i + 1; j < n; ++j) 
		{
			HoanVi(a[i], a[j]);
		}
	}
}
//--------------------------------------------------------------------------------
void DaoMangCacSoChan(int *a, int n) 
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j) 
		{
			if (a[j] % 2 == 0 && a[i] % 2 == 0) 
			{
				HoanVi(a[i], a[j]);
			}
		}
	}
}
//--------------------------------------------------------------------------------
void DaoMangSoDuong(int *a, int n) 
{
	for (int i = 0; i < n - 1; ++i) 
	{
		for (int j = i + 1; j < n; ++j) 
		{
			if (a[j] > 0 && a[i] > 0)
			{
				HoanVi(a[i], a[j]);
			}
		}
	}
}
//--------------------------------------------------------------------------------
void TimMinMax(int *a, int n, int& max, int& min)
{
	max = a[0];
	min = a[0];
	for (int i = 1; i < n; ++i) 
	{
		max = (a[i] > max) ? a[i] : max;
		min = (a[i] < min) ? a[i] : min;
	}
}

void DoiMaxBangMinVaNguocLai(int *a, int n, int max, int min)
{
	for (int i = 0; i < n; ++i) 
	{
		if (a[i] == max) 
		{
			a[i] = min;
		}
		else if (a[i] == min) 
		{
			a[i] = max;
		}
	}
}
int main()
{
	int n;
	NhapDuLieu(n);
	int* a = new int[n];
	NhapMang(a, n);
	XuatMang(a, n);
	cout << "\n\n";
	//DuaChanVeDauLeVeCuoi(a, n);
	//DoiChoDuaChanVeDau(a, n);
	//DaoMang(a,n);
	//DaoMangCacSoChan(a, n);
	//DaoMangSoDuong(a, n);
	DoiMaxBangMinVaNguocLai(a, n, 5, 1);
	XuatMang(a, n);
	delete[]a;
	return 0;
}
