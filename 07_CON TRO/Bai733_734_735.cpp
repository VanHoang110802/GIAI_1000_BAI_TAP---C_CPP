/*
Cho hai mảng số thực a, b. Đếm số lượng giá trị chỉ xuất hiện một trong hai mảng.

Cho hai mảng a, b. Liệt kê các giá trị chỉ xuất hiện một trong hai mảng.

Cho hai mảng a, b. Hãy cho biết số lần xuất hiện của mảng a trong mảng b.
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
template <typename vanhoang>
int DemPhanTuChiXuatHien1Trong2Mang(vanhoang*a, vanhoang *b, int na, int nb)
{
	int check, dem = 0;
	for (int i = 0; i < na; i++)
	{
		check = 1;
		for (int j = 0; j < nb; j++)
		{
			if (a[i] == b[j]) 
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
	for (int i = 0; i < nb; i++)
	{
		check = 1;
		for (int j = 0; j < na; j++) 
		{
			if (b[j] == a[i]) 
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
//----------------------------------------------------------------------------------
template <typename vanhoang>
void LietKePhanTuXuatHien1Trong2Mang(vanhoang *a, vanhoang *b, int n, int m)
{
	int i, j, check;
	for (i = 0; i < n; i++)
	{
		check = 1;
		for (j = 0; j < m; j++) 
		{
			if (a[i] == b[j])
			{
				check = 0;
				printf("Trong mang A co phan tu a[%d] = %d nam trong mang B\n", i, a[i]);
				break;
			}
		}
		if (check == 1) printf("Trong mang A co phan tu a[%d] = %d khong nam trong mang B\n", i, a[i]);
	}
	for (i = 0; i < m; i++) 
	{
		check = 1;
		for (j = 0; j < n; j++) 
		{
			if (b[i] == a[j])
			{
				check = 0;
				printf("Trong mang B co phan tu a[%d] = %d nam trong mang A\n", i, b[i]);
				break;
			}
		}
		if (check == 1) printf("Trong mang B co phan tu a[%d] = %d khong nam trong mang A\n", i, b[i]);
	}
}
//----------------------------------------------------------------------------------

/*
duyệt mảng b, nếu mà phần tử đầu tiên của mảng a bằng với 1 phần tử bất kỳ của mảng b
và số phần tử mảng b đó trừ đi i lớn hơn hoặc bằng số phần tử mảng a
h = i -> biến h sẽ là biến bắt đầu để đếm, khởi tạo ngay tại i thỏa DK
*/
template <typename vanhoang>
int DemSoLanXuatHienCuaMangATrongMangB(vanhoang *a, vanhoang *b, int na, int nb)
{
	int i, j, Start, check, dem = 0;
	for (i = 0; i < nb; i++) 
	{
		if (a[0] == b[i] && nb - i >= na) 
		{
			Start = i;
			check = 1;
			for (j = 0; j < na; j++) 
			{
				if (a[j] != b[Start++])
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
	}
	return dem;
}

int main()
{
	int na, nb;
	NhapDuLieu(na);
	int* a = new int[na];
	NhapMang(a, na);
	NhapDuLieu(nb);
	int* b = new int[nb];
	NhapMang(b, nb);
	XuatMang(a, na);
	cout << "\n\n";
	XuatMang(b, nb);
	//int dem = DemSoLanXuatHienCuaMangATrongMangB(a, b, na, nb);
	//cout << "\n" << dem;
	int dem = DemSoLanXuatHienCuaMangATrongMangB(a, b, na, nb);
	cout << "\n" << dem;
	delete[]a;
	delete[]b;
	return 0;
}
