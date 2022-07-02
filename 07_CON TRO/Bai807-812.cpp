/*
Viết hàm sắp xếp các phần tử trong ma trận theo yêu cầu sau :
- Dòng có chỉ số chẵn tăng dần.
- Dòng có chỉ số lẻ giảm dần.

Viết hàm sắp xếp các phần tử trong ma trận theo yêu cầu sau :
- Cột có chỉ số chẵn giảm dần từ trên xuống.
- Cột có chỉ số lẻ tăng dần từ trên xuống.

Sắp xếp các phần tử trong ma trận các số thực tăng dần theo hàng và cột bằng hai phương pháp sử dụng mảng phụ và không dùng mảng phụ.

Sắp xếp các phần tử dương trong ma trận các số thực tăng dần theo hàng và cột bằng hai phương pháp sử dụng mảng phụ và không dùng mảng phụ (các số âm giữ nguyên giá trị và vị trí).

Sắp xếp các phần tử chẵn trong ma trận các số nguyên giảm dần theo hàng và cột bằng hai phương pháp sử dụng mảng phụ và không dùng mảng phụ.

Sắp xếp các giá trị âm của ma trận tăng dần, các giá trị dương giảm và các phần tử có giá trị bằng 0 giữ nguyên vị trí.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void NhapDuLieu(int& n)
{
	do
	{
		cin >> n;
		if (n < 1)
		{
			cout << "\nSo luong phan tu nhap khong hop le, xin hay nhap lai!\n";
		}
	} while (n < 1);
}
template <typename vanhoang>
void CapPhat(vanhoang**& a, int sodong, int socot)
{
	a = new vanhoang * [sodong];
	for (int i = 0; i < sodong; ++i)
	{
		a[i] = new vanhoang[socot];
	}
}
template <typename vanhoang>
void NhapMang(vanhoang** a, int sodong, int socot)
{
	for (int i = 0; i < sodong; ++i)
	{
		for (int j = 0; j < socot; ++j)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
	}
}
template <typename vanhoang>
void XuatMang(vanhoang** a, int sodong, int socot)
{
	for (int i = 0; i < sodong; ++i)
	{
		for (int j = 0; j < socot; ++j)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}
template <typename vanhoang>
void ThuHoi(vanhoang**& a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		delete a[i];
	}
	delete[]a;
}

//-------------------------------------------------------------------------------------------------------
/*
Đặt a = 0101, b = 0011
a = a ^ b = 0110
Lúc này a = 0110, b = 0011
b = b ^ a = 0101 = a
Lúc này a = 0110, b = 0101
a = a ^ b = 0011 = b
*/
void HoanVi(int& a, int& b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void SapXepDongCoChiSoChanTangDanLeGiamDan(int **a, int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot - 1; j++)
		{
			for (int k = j + 1; k < cot; k++)
			{
				if (i % 2 == 0)
				{
					if (a[i][j] > a[i][k])
					{
						HoanVi(a[i][j], a[i][k]);
					}
				}
				else
				{
					if (a[i][j] < a[i][k])
					{
						HoanVi(a[i][j], a[i][k]);
					}
				}
			}
		}
	}
}
//------------------------------------------------------------------------------------

void SapXepCotCoChiSoChanGiamDanLeTangDan(int **a, int dong, int cot)
{
	for (int i = 0; i < cot; i++)
	{
		for (int j = 0; j < dong - 1; j++)
		{
			for (int k = j + 1; k < dong; k++)
			{
				if (i % 2 == 0)
				{
					if (a[j][i] < a[k][i])
					{
						HoanVi(a[j][i], a[k][i]);
					}
				}
				else
				{
					if (a[j][i] > a[k][i])
					{
						HoanVi(a[j][i], a[k][i]);
					}
				}
			}
		}
	}
}
//-----------------------------------------------------------------------------------------

void HoanVi_1(int& a, int& b)
{
	a = a + b; // Cho đại
	b = a - b;  // 
	a = a - b;  // lấy trên trừ dưới
}
void SapXepKhongDungMangPhu(int **a, int dong, int cot)
{
	int n = dong * cot;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i / cot][i % cot] > a[j / cot][j % cot])
			{
				HoanVi_1(a[i / cot][i % cot], a[j / cot][j % cot]);
			}
		}
	}
}
void SapXepDungMangPhu(int **a, int dong, int cot)
{
	// Bước 1: Đổ dữ liệu từ mảng 2 chiều qua mảng 1 chiều (mảng phụ)
	int *temp = new int[dong * cot];
	int idx = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			temp[idx++] = a[i][j];
		}
	}

	// Bước 2: Sắp xếp mảng 1 chiều tăng dần
	for (int i = 0; i < idx - 1; i++)
	{
		for (int j = i + 1; j < idx; j++)
		{
			if (temp[i] > temp[j])
			{
				HoanVi_1(temp[i], temp[j]);
			}
		}
	}

	// Bước 3: Đổ lại dữ liệu từ mảng 1 chiều sang mảng 2 chiều
	idx = 0; // Reset lại chỉ số mảng phụ

	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			a[i][j] = temp[idx++];
		}
	}
	delete[] temp;
}
//--------------------------------------------------------------------------------------

void SapXepKhongDungMangPhu_2(int **a, int dong, int cot)
{
	int n = dong * cot;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i / cot][i % cot] > 0)
			{
				if (a[i / cot][i % cot] > a[j / cot][j % cot])
				{
					HoanVi_1(a[i / cot][i % cot], a[j / cot][j % cot]);
				}
			}
		}
	}
}

void SapXepDungMangPhu_2(int **a, int dong, int cot)
{
	// Bước 1: Đổ dữ liệu từ mảng 2 chiều qua mảng 1 chiều (mảng phụ)
	int *temp = new int[dong * cot];
	int idx = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			temp[idx++] = a[i][j];
		}
	}

	// Bước 2: Sắp xếp mảng 1 chiều tăng dần
	for (int i = 0; i < idx - 1; i++)
	{
		for (int j = i + 1; j < idx; j++)
		{
			if (temp[i] > 0)
			{
				if (temp[i] > temp[j])
				{
					HoanVi(temp[i], temp[j]);
				}
			}
		}
	}

	// Bước 3: Đổ lại dữ liệu từ mảng 1 chiều sang mảng 2 chiều
	idx = 0; // Reset lại chỉ số mảng phụ

	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			a[i][j] = temp[idx++];
		}
	}
	delete[] temp;
}

//------------------------------------------------------------------------------------------
void SapXepKhongDungMangPhu_3(int **a, int dong, int cot)
{
	int n = dong * cot;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i / cot][i % cot] % 2 == 0)
			{
				if (a[i / cot][i % cot] < a[j / cot][j % cot])
				{
					HoanVi_1(a[i / cot][i % cot], a[j / cot][j % cot]);
				}
			}
		}
	}
}

void SapXepDungMangPhu_3(int **a, int dong, int cot)
{
	// Bước 1: Đổ dữ liệu từ mảng 2 chiều qua mảng 1 chiều (mảng phụ)
	int *temp = new int[dong * cot];
	int idx = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			temp[idx++] = a[i][j];
		}
	}

	// Bước 2: Sắp xếp mảng 1 chiều tăng dần
	for (int i = 0; i < idx - 1; i++)
	{
		for (int j = i + 1; j < idx; j++)
		{
			if (temp[i] % 2 == 0)
			{
				if (temp[i] < temp[j])
				{
					HoanVi_1(temp[i], temp[j]);
				}
			}
		}
	}

	// Bước 3: Đổ lại dữ liệu từ mảng 1 chiều sang mảng 2 chiều
	idx = 0; // Reset lại chỉ số mảng phụ

	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			a[i][j] = temp[idx++];
		}
	}
	delete[] temp;
}

//---------------------------------------------------------------------------------------------
void SapXepAmTangDan(int **a, int dong, int cot)
{
	int i, j, Start1, Start2, d = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (a[i][j] < 0)
			{
				for (Start1 = i; Start1 < dong; Start1++)
				{
					if (d == 0)
					{
						Start2 = j;
					}
					else
					{
						Start2 = 0;
					}
					for (; Start2 < cot; Start2++)
					{
						if (a[i][j] > a[Start1][Start2] && a[Start1][Start2] < 0)
						{
							HoanVi_1(a[i][j], a[Start1][Start2]);
						}
					}
					if (Start2 == cot)
					{
						d = 1;
					}
				}
				d = 0;
			}
		}
	}
}

void SapXepDuongGiamDan(int **a, int dong, int cot)
{
	int i, j, Start1, Start2, d = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (a[i][j] > 0)
			{
				for (Start1 = i; Start1 < dong; Start1++)
				{
					if (d == 0)
					{
						Start2 = j;
					}
					else
					{
						Start2 = 0;
					}
					for (; Start2 < cot; Start2++)
					{
						if (a[i][j] < a[Start1][Start2] && a[Start1][Start2] > 0)
						{
							HoanVi_1(a[i][j], a[Start1][Start2]);
						}
					}
					if (Start2 == cot)
					{
						d = 1;
					}
				}
				d = 0;
			}
		}
	}
}

void SapXepAmTangDanDuongGiamDan0GiuNguyenViTri(int **a, int dong, int cot)
{
	SapXepAmTangDan(a, dong, cot);
	SapXepDuongGiamDan(a, dong, cot);
}

int main()
{
	int sodong, socot;
	cout << "Nhap so dong: ";
	NhapDuLieu(sodong);
	cout << "Nhap so cot: ";
	NhapDuLieu(socot);
	int** a, x = 1;
	CapPhat(a, sodong, socot);
	NhapMang(a, sodong, socot);
	XuatMang(a, sodong, socot);
	cout << "\n\n";
	//SapXepDongCoChiSoChanTangDanLeGiamDan(a, sodong, socot);
	//SapXepCotCoChiSoChanGiamDanLeTangDan(a, sodong, socot);

	/* SẮP XẾP CÁC PHẦN TỬ TRONG MẢNG THEO 2 CÁCH */
	//SapXepDungMangPhu(a, sodong, socot);
	//SapXepKhongDungMangPhu(a, sodong, socot);
	
	/* SẮP XẾP CÁC PHẦN TỬ DƯƠNG TRONG MẢNG THEO 2 CÁCH */
	//SapXepDungMangPhu_2(a, sodong, socot);
	//SapXepKhongDungMangPhu_2(a, sodong, socot);
	
	/* SẮP XẾP CÁC PHẦN TỬ CHẴN TRONG MẢNG THEO 2 CÁCH */
	//SapXepDungMangPhu_3(a, sodong, socot);
	//SapXepKhongDungMangPhu_3(a, sodong, socot);
	
	SapXepAmTangDanDuongGiamDan0GiuNguyenViTri(a, sodong, socot);
	XuatMang(a, sodong, socot);
	if (a != NULL)
	{
		ThuHoi(a, sodong);
	}
	return 0;
}
