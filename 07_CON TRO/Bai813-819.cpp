/*

Sắp xếp các giá trị chẵn của ma trận số nguyên tăng dần, các giá trị lẻ giảm dần.

Sắp xếp các giá trị nằm trên biên ma trận tăng dần theo chiều kim đồng hồ.

Sắp xếp các giá trị dương nằm trên biên ma trận các số thực tăng dần theo chiều kim đồng hồ.

Hãy sắp xếp các dòng trong ma trận theo tiêu chuẩn sau : dòng có tổng dòng nhỏ hơn nằm ở trên và dòng có tổng dòng lớn hơn bằng nằm ở dưới.

Hãy sắp xếp giá trị các phần tử trong ma trận tăng dần theo hình xoắn tròn ốc.

Hãy sắp xếp giá trị các phần tử trong ma trận tăng dần theo hình xoắn ziczac.

Xuất các giá trị âm trong ma trận các số thực giảm dần (ma trận không thay đổi sau khi xuất).
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
void HoanVi(int& a, int& b)
{
	int tam = a;
	a = b;
	b = tam;
}
/*
void HoanVi(int& a, int& b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
*/
void SapXepChanTangDan(int **a, int dong, int cot)
{
	int i, j, Start1, Start2, d = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (a[i][j] % 2 == 0)
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
						if (a[i][j] > a[Start1][Start2] && a[Start1][Start2] % 2 == 0)
						{
							HoanVi(a[i][j], a[Start1][Start2]);
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

void SapXepLeGiamDan(int **a, int dong, int cot)
{
	int i, j, Start1, Start2, d = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (a[i][j] % 2 != 0)
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
						if (a[i][j] < a[Start1][Start2] && a[Start1][Start2] % 2 != 0)
						{
							HoanVi(a[i][j], a[Start1][Start2]);
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

void SapXepChanTangDanLeGiamDan(int **a, int dong, int cot)
{
	SapXepChanTangDan(a, dong, cot);
	SapXepLeGiamDan(a, dong, cot);
}
//---------------------------------------------------------------------------------------------------------------
void GanBienVaoMang(int **a, int dong, int cot, int *temp, int& idx)
{
	int i = 0, j;            // giả sử có 3 dòng, 3 cột
	// biên hàng trên
	for (j = i; j < cot; j++)
	{
		temp[idx++] = a[i][j];   //  i = 0, j chạy từ 0 đến 2
	}
	// biên cột phải
	for (i++, j--; i < dong; i++)  // i chạy từ 1 đến 2, j = 1
	{
		temp[idx++] = a[i][j];
	}
	// biên hàng dưới
	for (i--, j--; j >= 0; j--)
	{
		temp[idx++] = a[i][j];
	}
	// biên cột trái
	for (i--, j++; i > 0; i--)
	{
		temp[idx++] = a[i][j];
	}
}


void SapXepMangTangDan_1(int *temp, int idx)
{
	for (int i = 0; i < idx - 1; i++)
	{
		for (int j = i + 1; j < idx; j++)
		{
			if (temp[i] > temp[j])
			{
				HoanVi(temp[i], temp[j]);
			}
		}
	}
}

void GanMangVaoBien(int **a, int dong, int cot, int *temp)
{
	int i = 0, j, idx = 0;            // giả sử có 3 dòng, 3 cột
	// biên hàng trên
	for (j = i; j < cot; j++)
	{
		a[i][j] = temp[idx++];   //  i = 0, j chạy từ 0 đến 2
	}
	// biên cột phải
	for (i++, j--; i < dong; i++)  // i chạy từ 1 đến 2, j = 1
	{
		a[i][j] = temp[idx++];
	}
	// biên hàng dưới
	for (i--, j--; j >= 0; j--)
	{
		a[i][j] = temp[idx++];
	}
	// biên cột trái
	for (i--, j++; i > 0; i--)
	{
		a[i][j] = temp[idx++];
	}
}

void SapXepCacGiaTriNamTrenBienTangDan(int **a, int dong, int cot)
{
	int *temp, idx = 0;
	temp = new int[dong * cot];
	GanBienVaoMang(a, cot, dong, temp, idx);
	SapXepMangTangDan_1(temp, idx);
	GanMangVaoBien(a, cot, dong, temp);
	delete[] temp;
}
//----------------------------------------------------------------------------------------------
void GanBienVaoMang_1(int **a, int dong, int cot, int temp[], int& idx)
{
	int i = 0, j;
	// biên hàng trên
	for (j = i; j < cot; j++)
	{
		temp[idx++] = a[i][j];
	}
	// biên cột phải
	for (i++, j--; i < dong; i++)
	{
		temp[idx++] = a[i][j];
	}
	// biên hàng dưới
	for (i--, j--; j >= 0; j--)
	{
		temp[idx++] = a[i][j];
	}
	// biên cột trái
	for (i--, j++; i > 0; i--)
	{
		temp[idx++] = a[i][j];
	}
}

void SapXepMangTangDan_2(int temp[], int idx)
{
	for (int i = 0; i < idx - 1; i++)
	{
		for (int j = i + 1; j < idx; j++)
		{
			if (temp[i] > temp[j])
			{
				HoanVi(temp[i], temp[j]);
			}
		}
	}
}

void GanMangVaoBien_2(int **a, int dong, int cot, int temp[])
{
	int i = 0, j, idx = 0;
	// biên hàng trên
	for (j = i; j < cot; j++)
	{
		a[i][j] = temp[idx++];
	}
	// biên cột phải
	for (i++, j--; i < dong; i++)
	{
		a[i][j] = temp[idx++];
	}
	// biên hàng dưới
	for (i--, j--; j >= 0; j--)
	{
		a[i][j] = temp[idx++];
	}
	// biên cột trái
	for (i--, j++; i > 0; i--)
	{
		a[i][j] = temp[idx++];
	}
}

void SapXepCacGiaTriNamTrenBienTangDan_2(int **a, int dong, int cot)
{
	int *temp, idx = 0;
	temp = new int[dong * cot];
	GanBienVaoMang_1(a, cot, dong, temp, idx);
	SapXepMangTangDan_2(temp, idx);
	GanMangVaoBien_2(a, cot, dong, temp);
	delete[]temp;
}
//----------------------------------------------------------------------------------------------------------
void TinhTongCacDong(int **a, int dong, int cot, int *b)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			b[i] += a[i][j];
		}
	}
}

void HoanVi2Dong(int **a, int cot, int dong1, int dong2)
{
	for (int j = 0; j < cot; j++)
	{
		HoanVi(a[dong1][j], a[dong2][j]);
	}
}

void SapXepCacDongDuaVaoTongCacPhanTuTrong1Dong(int **a, int dong, int cot)
{
	int *b = new int[dong * cot];
	TinhTongCacDong(a, dong, cot, b);
	for (int i = 0; i < dong - 1; i++)
	{
		for (int j = i + 1; j < dong; j++)
		{
			if (b[i] > b[j])
			{
				HoanVi2Dong(a, cot, i, j);
				HoanVi(b[i], b[j]);
			}
		}
	}
	delete[] b;
}
//-----------------------------------------------------------------------------------------------
void TaoMaTranXoanOc(int **a, int dong, int cot)
{
	int trai = 0, tren = 0, duoi = dong, phai = cot, dem = 0, n = dong * cot;
	while (dem < n)
	{
		// chạy hàng trên
		for (int i = trai; i < phai; i++)
		{
			if (dem < n)
			{
				a[tren][i] = dem++;
			}
		}
		tren++;
		// chạy cột phải
		for (int i = tren; i < duoi; i++)
		{
			if (dem < n)
			{
				a[i][phai - 1] = dem++;
			}
		}
		phai--;
		// chạy hàng dưới
		for (int i = phai - 1; i >= trai; i--)
		{
			if (dem < n)
			{
				a[duoi - 1][i] = dem++;
			}
		}
		duoi--;
		// chạy cột trái
		for (int i = duoi - 1; i >= tren; i--)
		{
			if (dem < n)
			{
				a[i][trai] = dem++;
			}
		}
		trai++;
	}
}
//-------------------------------------------------------------------------------------------------
void TaoMaTranZicZacNgang(int **a, int dong, int cot)
{
	int dem = 1;
	for (int i = 0; i < dong; i++)
	{
		// Với mỗi dòng chẵn, dem sẽ được gán vào từng phần tử của các cột từ trái sang phải
		if (i % 2 == 0)
		{
			for (int j = 0; j < cot; j++)
			{
				a[i][j] = dem++;
			}
		}
		// Với mỗi dòng lẻ, dem sẽ được gán vào từng phần tử của các cột từ phải sang trái
		else
		{
			for (int j = cot - 1; j >= 0; j--)
			{
				a[i][j] = dem++;
			}
		}
	}
}
//--------------------------------------------------------------------------------------------------------

void XuatCacGiaTriAmTheoThuTuGiamDan_2(int **a, int dong, int cot)
{
	int n = dong * cot;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i / cot][i % cot] < 0)
			{
				if (a[i / cot][i % cot] < a[j / cot][j % cot])
				{
					HoanVi(a[i / cot][i % cot], a[j / cot][j % cot]);
				}
			}
		}
	}

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

	//SapXepChanTangDanLeGiamDan(a, sodong, socot);
	//SapXepCacGiaTriNamTrenBienTangDan(a, sodong, socot);
	//SapXepCacGiaTriNamTrenBienTangDan_2(a, sodong, socot);
	//SapXepCacDongDuaVaoTongCacPhanTuTrong1Dong(a, sodong, socot);
	//TaoMaTranXoanOc(a, sodong, socot);
	//TaoMaTranZicZacNgang(a, sodong, socot);
	XuatCacGiaTriAmTheoThuTuGiamDan_2(a, sodong, socot);
	XuatMang(a, sodong, socot);
	if (a != NULL)
	{
		ThuHoi(a, sodong);
	}
	return 0;
}
