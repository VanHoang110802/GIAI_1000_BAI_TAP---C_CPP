/*
Dịch xuống xoay vòng các hàng trong ma trận.
Ví dụ :
87 75 62 54
46 40 33 28
20 18 15 10
-20 67 53 23
Kết quả dịch xuống xoay vòng các hàng :
-20 67 53 23
87 75 62 54
46 40 33 28
20 18 15 10

Dịch lên xoay vòng các hàng trong ma trận.

Dịch trái xoay vòng các cột trong ma trận.

Dịch phải xoay vòng theo chiều kim đồng hồ các giá trị nằm trên biên ma trận.

Dịch trái xoay vòng theo chiều kim đồng hồ các giá trị nằm trên biên ma trận.
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
void HoanVi(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
//-------------------------------------------------------------------------------------------------------
/*
dùng thêm mảng phụ, lưu lại hàng cuối, rồi gán từ cuối lên. Cuối cùng là gán mảng vào hàng đầu
*/
void DichXuongXoayVongCacHangTrongMaTran(int **a, int dong, int cot)
{
	// Dùng mảng phụ lưu lại hàng cuối
	int *temp = new int[dong];
	for (int i = 0; i < dong; i++)
	{
		temp[i] = a[cot - 1][i];
	}
	// Gán từ cuối lên
	for (int i = cot - 1; i >= 1; i--)
	{
		for (int j = 0; j < dong; j++)
		{
			a[i][j] = a[i - 1][j];
		}
	}
	// Gán mảng phụ vào hàng đầu
	for (int i = 0; i < dong; i++)
	{
		a[0][i] = temp[i];
	}
	delete[] temp;
}
//----------------------------------------------------------------------------------------------
/*
dùng thêm mảng phụ, lưu lại hàng đầu, rồi gán từ trên xuống. Cuối cùng là gán mảng vào hàng cuối
*/
void DichLenXoayVongCacHangTrongMaTran(int **a, int dong, int cot)
{
	// Gán mảng phụ vào hàng đầu
	int *temp = new int[dong];
	for (int i = 0; i < cot; i++)
	{
		temp[i] = a[0][i];
	}

	// Gán từ trên xuống
	for (int i = 0; i < dong - 1; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			a[i][j] = a[i + 1][j];
		}
	}
	// Dùng mảng phụ lưu lại hàng cuối
	for (int i = 0; i < cot; i++)
	{
		a[dong - 1][i] = temp[i];
	}
	delete[]temp;
}
//-------------------------------------------------------------------------------------------
/*
dùng thêm mảng phụ, lưu lại cột bên trái ngoài cùng, rồi gán từ trái qua phải. Cuối cùng là gán mảng vào cột cuối bên phải
*/
void DichPhaiXoayVongCacCotTrongMaTran(int **a, int dong, int cot)
{
	int*temp = new int[cot];
	for (int i = 0; i < dong; i++)
	{
		temp[i] = a[i][cot - 1];
	}
	for (int j = cot - 1; j > 0; j--)
	{
		for (int i = 0; i < dong; i++)
		{
			a[i][j] = a[i][j - 1];
		}
	}
	for (int i = 0; i < dong; i++)
	{
		a[i][0] = temp[i];
	}
	delete[]temp;
}
//--------------------------------------------------------------------------------------
void DichPhaiXoayVongTheoChieuKimDongHoCacGiaTriNamTrenBien(int **a, int dong, int cot)
{
	int i, j;
	int temp = a[0][0]; // lấy đi 1 ô tạo chỗ trống để dịch chuyển

	// dịch chuyển cột bên trái lên trên
	for (i = 0, j = i; i < dong - 1; i++) // giả sử dòng = 4, cột = 5
	{
		a[i][j] = a[i + 1][j]; // chạy từ i = 0 đến i = 3 thì dừng, j = 0
	}
	// dịch chuyển hàng dưới từ phải qua trái
	for (j, i; j < cot - 1; j++)
	{
		a[i][j] = a[i][j + 1]; // i = 3, j chạy từ 0 đến 4 thì dừng
	}
	// dịch chuyển cột bên phải từ trên xuống
	for (i, j; i > 0; i--)
	{
		a[i][j] = a[i - 1][j]; // i chạy từ 3 về 0 thì dừng, j = 4 
	}
	// dịch chuyển hàng trên từ trái qua phải
	for (i, j; j > 1; j--)
	{
		a[i][j] = a[i][j - 1]; // i = 0, j chạy từ 4 về 1 thì dừng 
	}
	// dịch chuyển xong bỏ ô kia về để lấp đầy ma trận
	a[0][1] = temp;
}
//------------------------------------------------------------------------------------------
void DichTraiXoayVongTheoChieuKimDongHoCacGiaTriNamTrenBien(int **a, int dong, int cot)
{
	int i, j;
	int temp = a[0][0]; // lấy đi 1 ô tạo chỗ trống để dịch chuyển

	for (i = 0, j = 0; j < cot - 1; j++)
	{
		a[i][j] = a[i][j + 1];
	}
	for (i, j; i < dong - 1; i++)
	{
		a[i][j] = a[i + 1][j];
	}
	for (i, j; j > 0; j--)
	{
		a[i][j] = a[i][j - 1];
	}
	for (i, j; i > 1; i--)
	{
		a[i][j] = a[i - 1][j];
	}
	a[1][0] = temp;
}


/*
void ThuHoi(int*** a, int sodong)
{
	for (int i = 0; i < sodong; ++i)
	{
		delete (*a)[i];
	}
	delete[](*a);
}
*/
template <typename vanhoang>
void ThuHoi(vanhoang**& a, int sodong)
{
	for (int i = 0; i < sodong; ++i)
	{
		delete a[i];
	}
	delete[]a;
}
int main()
{
	int sodong, socot;
	cout << "Nhap so dong: ";
	NhapDuLieu(sodong);
	cout << "Nhap so cot: ";
	NhapDuLieu(socot);
	int** a , x = 1;
	CapPhat(a, sodong, socot);
	NhapMang(a, sodong, socot);
	XuatMang(a, sodong, socot);
	cout << "\n\n";
	//DichLenXoayVongCacHangTrongMaTran(a, sodong, socot);
	//DichXuongXoayVongCacHangTrongMaTran(a, sodong, socot);
	//DichPhaiXoayVongCacCotTrongMaTran(a, sodong, socot);
	//DichPhaiXoayVongTheoChieuKimDongHoCacGiaTriNamTrenBien(a, sodong, socot);
	
	DichTraiXoayVongTheoChieuKimDongHoCacGiaTriNamTrenBien(a, sodong, socot);
	XuatMang(a, sodong, socot);
	if (a != NULL)
	{
		//ThuHoi(&a, sodong);
		ThuHoi(a, sodong);
	}
	return 0;
}
