/*
(*) Đếm số lượng phần tử cực đại trong ma trận các số thực. Một phần tử được gọi là cực đại khi nó lớn hơn các phần tử xung quanh.

(*) Đếm số lượng phần tử cực trị trong ma trận các số thực. Một phần tử được gọi là cực trị khi nó lớn hơn các phần tử xung quanh hoặc nhỏ hơn các phần tử xung quanh.

(*) Đếm số lượng giá trị có trong ma trận các số thực. Lưu ý: Nếu có k phần tử (k >= 1) trong ma trận bằng nhau thì ta chỉ tính là 1.

(*) Đếm số lượng giá trị “Hoàng Hậu” trên ma trận. Một phần tử được gọi là Hoàng Hậu khi nó lớn nhất trên dòng, trên cột và hai đường chéo đi qua nó.

(*) Đếm số lượng giá trị “Yên Ngựa” trên ma trận. Một phần tử được gọi là Yên Ngựa khi nó lớn nhất trong dòng và nhỏ nhất trên Cột.
*/
#include <iostream>
#include <cstdlib>
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
	for (int i = 0; i < sodong; i++)
	{
		a[i] = new vanhoang[socot];
	}
}
template <typename vanhoang>
void NhapMang(vanhoang** a, int sodong, int socot)
{
	for (int i = 0; i < sodong; i++)
	{
		for (int j = 0; j < socot; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
	}
}
template <typename vanhoang>
void XuatMang(vanhoang** a, int sodong, int socot)
{
	for (int i = 0; i < sodong; i++)
	{
		for (int j = 0; j < socot; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}
//-------------------------------------------------------------------------------------------------------
/*			Chỉ số
			-1
 Chỉ số: -1 0 | 1   2   3
			--------------
			1 |	1	2	3
			2 |	4	5	6
			3 |	7	8	9
	// phần tử cực đại là 9

Đầu tiên đặt check =1 tức là mặc định giá trị ô a[d][c] là cực đại, nếu như 1 trong các ô xung quanh ô a[d][c] này có giá trị lớn
hơn nó (a[d][c]<=a[d+i][c+j]) thì đặt check =0 tức là nó ko phải điểm cực đại loại trừ trường hợp i=0 và j=0 như trong lệnh
if có ghi vì nó trùng với tọa độ của a[d][c].
*/
int KiemTraPhanTuCucDai(float **a, int sodong, int socot, int dong, int cot)
{
	int check = 1; // Khởi đầu mặc định ô a[dong][cot] là cực đại
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			if (dong + i >= 0 && cot + j >= 0 && dong + i < sodong && cot + j < socot && !(i == 0 && j == 0))
			{
				if (a[dong][cot] <= a[dong + i][cot + j])
				{
					check = 0;
				}
			}
		}
	}
	return check;
}

void DemSoPhanTuCucDai(float **a, int sodong, int socot)
{
	int dem = 0;
	cout << "\nCac phan tu cuc dai la: \n";
	for (int i = 0; i < sodong; ++i)
	{
		for (int j = 0; j < socot; ++j)
		{
			if (KiemTraPhanTuCucDai(a, sodong, socot, i, j) == 1)
			{
				cout << a[i][j] << "  ";
				dem++;
			}
		}
	}
	cout << "\nSo phan tu cuc dai la: " << dem;
}
//-------------------------------------------------------------------------------------------------------
/*
 Chỉ số: -1 0 |  1   2   3
			--------------
			1 |	1	2	3
			2 |	4	5	6
			3 |	7	8	9
-> 1, 9
*/
int KiemTraPhanTuCucTri(float **a, int sodong, int socot, int dong, int cot)
{
	int CucDai = 1, CucTieu = 1;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (dong + i >= 0 && cot + j >= 0 && dong + i < sodong && cot + j < socot && !(i == 0 && j == 0))
			{
				if (a[dong][cot] <= a[dong + i][cot + j])
				{
					CucDai = 0;
				}
				if (a[dong][cot] >= a[dong + i][cot + j])
				{
					CucTieu = 0;
				}
				if (!CucDai && !CucTieu) break;
			}
		}
	}
	if (!CucDai && !CucTieu) return 0;
	return 1;
}
int DemSoPhanTuCucTri(float **a, int dong, int cot)
{
	int dem = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (KiemTraPhanTuCucTri(a, dong, cot, i, j))
			{
				dem++;
			}
		}
	}
	return dem;
}
//--------------------------------------------------------------------------------------------
/*
			0 |  1   2   3
			--------------
			1 |	1	2	3
			2 |	2	3	4
			3 |	3	4	5
	-> 1 2 3 4 5
*/
int DemSoLuongCacGiaTriPhanBiet(float **a, int dong, int cot)
{
	int n = dong * cot;
	int dem = 0, check;
	for (int i = 0; i < n; i++)
	{
		check = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j / cot][j % cot] == a[i / cot][i % cot])
			{
				check = 0;
				break;
			}
		}
		if (check == 1)
		{
			dem++;
		}
	}
	return dem;
}
//-----------------------------------------------------------------------------------
/*
- Kiểm tra phần tử đó có lớn nhất trên dòng nó đang đứng hay không ?
- Kiểm tra phần tử đó có lớn nhất trên cột nó đang đứng hay không ?
- Kiểm tra phần tử đó có lớn nhất trên 2 đường chéo hay không (Đây là hàm khá phức tạp). Trường hợp này mình sẽ cho duyệt theo 4 hướng (4 while):
+ từ vị trí phần tử hiện tại, i--, j-- (giảm qua trái)
+ từ vị trí phần tử hiện tại i--,j++ (giảm phải)
+ // i++,j++ (tăng phải)
+ // i++,j-- (tăng trái)

Sau khi thực hiện 3 hàm trên, duyệt ma trận sẽ tìm được phần tử "Hoàng Hậu"
*/
int KiemTraCoPhaiPhanTuHoangHau(int **a, int vtdong, int vtcot, int dong, int cot)
{
	int x = a[vtdong][vtcot];

	// kiểm tra dòng
	for (int i = 0; i < cot; i++)
	{
		if (a[vtdong][i] > x)
		{
			return 0;
		}
	}
	// kiểm tra cột
	for (int j = 0; j < dong; j++)
	{
		if (a[j][vtcot] > x)
		{
			return 0;
		}
	}
	//ktra duong cheo thu nhat
	int vtdong1 = vtdong + 1;
	int vtcot1 = vtcot + 1;
	while (vtcot1 + 1 < cot && vtdong1 < vtdong)
	{
		if (a[vtcot1][vtdong1] > x)
			return 0;
		// tăng phải
		vtcot1++;
		vtdong1++;
	}
	vtdong1 = vtdong - 1;
	vtcot1 = vtcot - 1;
	while (vtcot1 - 1 >= 0 && vtdong1 >= 0)
	{
		if (a[vtcot1][vtdong1] > x)
			return 0;
		//giảm qua trái
		vtcot1--;
		vtdong1--;
	}
	// duong cheo thu 2
	vtdong1 = vtdong + 1;
	vtcot1 = vtcot - 1;
	while (vtcot1 - 1 >= 0 && vtdong1 < dong)
	{
		if (a[vtcot1][vtdong1] > x)
			return 0;
		// tăng trái
		vtdong1++;
		vtcot1--;
	}
	vtdong1 = vtdong - 1;
	vtcot1 = vtcot + 1;

	while (vtdong1 - 1 >= 0 && vtcot1 < cot)
	{
		if (a[vtcot1][vtdong1] > x)
			return 0;
		// giảm phải
		vtdong1--;
		vtcot1++;
	}
	return 1;
}

int DemSoLuongPhanTuHoangHau(int **a, int dong, int cot)
{
	int dem = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (KiemTraCoPhaiPhanTuHoangHau(a, i, j, dong, cot) == 1)
			{
				dem++;
			}
		}
	}
	return dem;
}
//----------------------------------------------------------------------------------------------
int TimPhanTuNhoNhatDong(int **a, int vtdong, int vtcot, int dong, int cot)
{
	int x = a[vtdong][vtcot];
	for (int i = 0; i < cot; i++)
	{
		if (a[vtdong][i] < x)
		{
			return 0;
		}
	}
	return 1;
}

int TimPhanTuLonNhatCot(int **a, int vtdong, int vtcot, int dong, int cot)
{
	int x = a[vtdong][vtcot];
	for (int j = 0; j < dong; j++)
	{
		if (a[j][vtcot] > x)
		{
			return 0;
		}
	}
	return 1;
}

void DemSoPhanTuYenNgua(int **a, int dong, int cot)
{
	int dem = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (TimPhanTuNhoNhatDong(a, i, j, dong, cot) && TimPhanTuLonNhatCot(a, i, j, dong, cot))
			{
				printf("A[%d][%d] = %d la mot diem yen ngua.\n", i, j, a[i][j]);
				dem++;
			}
		}
	}
	cout << "\nSo phan tu yen ngua la: "<< dem;
}

/*
void ThuHoi(int*** a, int sodong)
{
	for (int i = 0; i < sodong; i++)
	{
		delete (*a)[i];
	}
	delete[](*a);
}
*/
template <typename vanhoang>
void ThuHoi(vanhoang**& a, int sodong)
{
	for (int i = 0; i < sodong; i++)
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
	int** a;
	CapPhat(a, sodong, socot);
	NhapMang(a, sodong, socot);
	XuatMang(a, sodong, socot);
	//DemSoPhanTuCucDai(a, sodong, socot);
	//DemSoPhanTuCucTri(a, sodong, socot);
	//DemSoLuongCacGiaTriPhanBiet(a, sodong, socot);
	//DemSoLuongPhanTuHoangHau(a, sodong, socot);
	//DemSoPhanTuYenNgua(a, sodong, socot);
	cout << "\n";
	DemSoPhanTuYenNgua(a, sodong, socot);
	
	if (a != NULL)
	{
		//ThuHoi(&a, sodong);
		ThuHoi(a, sodong);
	}
	return 0;
}
