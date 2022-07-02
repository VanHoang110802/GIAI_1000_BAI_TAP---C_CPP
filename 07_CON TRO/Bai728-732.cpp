/*
Hãy xác định số lượng các phần tử kề nhau mà cả hai đều chẵn.

Hãy xác định số lượng các phần tử kề nhau mà cả hai số trái dấu nhau.

Hãy xác định số lượng các phần tử kề nhau mà số đứng sau cùng dấu số đứng trước và có giá trị tuyệt đối lớn hơn.

Hãy liệt kê tần suất xuất hiện của các giá trị xuất hiện trong mảng. (Lưu ý: mỗi giá trị liệt kê một lần).
Mảng: 1 2 5 2 3 10 4 2 2 5 10 4 3
-> có 6 phần tử phân biệt
- phần tử 1 xuất hiện 1 lần
- phần tử 2 xuất hiện 4 lần
- phần tử 5 xuất hiện 2 lần
- phần tử 3 xuất hiện 2 lần
- phần tử 10 xuất hiện 2 lần
- phần tử 4 xuất hiện 2 lần
Từ 1 vị trí i hiện tại sẽ lùi về trước đó (i - 1) để kiểm tra xem có bị trùng chưa? Nếu có thì sẽ không xét i hiện tại
mà xét sang lần lặp khác, nếu không bị trùng thì từ vị trí i hiện tại sẽ lui về đằng sau nó (i+1) để đếm xem có bao nhiêu
giá trị đó xuất hiện và cuối cùng in kết quả đếm ra.

Hãy liệt kê các giá trị xuất hiện trong mảng một chiều các số nguyên đúng một lần.

Hãy liệt kê các giá trị xuất hiện trong dãy quá một lần. Lưu ý: mỗi giá trị liệt kê một lần.
Ví dụ:
12 43 12 34 43 12 5
Các giá trị xuất hiện quá một lần 12, 43.
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
vanhoang DemSoLuongPhanTuKeNhauMaCa2DeuChan(vanhoang *a, int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++) 
	{
		if (a[i] % 2 == 0 && a[i + 1] % 2 == 0) 
		{
			dem++;
		}
	}
	if (dem != 0) 
	{
		dem++;
	}
	return dem;
}
//----------------------------------------------------------------------------------
template <typename vanhoang>
vanhoang DemSoLuongPhanTuKeNhauMaCa2TraiDau(vanhoang *a, int n) 
{
	vanhoang dem = 0;
	for (int i = 0; i < n; i++) 
	{
		if (a[i] * a[i + 1] < 0) 
		{
			dem++;
		}
	}
	if (dem != 0)
	{
		dem++;
	}
	return dem;
}
//----------------------------------------------------------------------------------
template <typename vanhoang>
vanhoang DemSoPhanTuKeNhau(vanhoang *a, int n) 
{
	int dem = 0;
	for (int i = 0; i < n; i++) 
	{
		if (a[i] * a[i - 1] > 0 && abs(a[i - 1]) < abs(a[i]))
		{
			dem++;
		}
	}
	return dem;
}
//----------------------------------------------------------------------------------
template <typename vanhoang>
//hàm từ vị trí hiện tại xét lùi xuống, để xét xem phần tử đó có bị trùng hay không?
int KiemTraBiTrung(vanhoang *a, int n, int vitridangxet)
{
	for (int i = vitridangxet - 1; i >= 0; i--) 
	{
		if (a[i] == a[vitridangxet])
		{
			return 1;
		}
	}
	return 0;
}
template <typename vanhoang>
// hàm đếm vị trí hiện tại lùi xuống về cuối mảng để đếm xem phần tử đó xuất hiện bao nhiêu lần
int DemSoLanXuatHien(vanhoang *a, int n, int vitridangxet)
{
	int dem = 1;
	for (int i = vitridangxet + 1; i < n; i++) 
	{
		if (a[i] == a[vitridangxet]) 
		{
			dem++;
		}
	}
	return dem;
}
template <typename vanhoang>
void GiaoHop2Ham(vanhoang *a, int n)
{
	for (int i = 0; i < n; i++) 
	{
		int check = KiemTraBiTrung(a, n, i);
		if (check == 1)
		{
			continue;
		}
		int dem = DemSoLanXuatHien(a, n, i);
		printf("\nPhan tu %d xuat hien %d", a[i], dem);
	}
}
//----------------------------------------------------------------------------------
template <typename vanhoang>
int KiemTraBiTrung1(vanhoang* a, int n, int ViTri)
{
	for (int i = ViTri - 1; i >= 0; i--)
	{
		if (a[i] == a[ViTri]) {
			return 0;  // bị trùng
		}
	}
	return 1;         // không bị trùng
}

// Đếm xem từ vị trí hiện tại trở về sau có bao nhiêu phần tử bị trùng
int DemSoLuongPhanTuTrung(int *a, int n, int ViTri)
{
	int dem = 1;
	for (int i = ViTri + 1; i < n; i++) 
	{
		if (a[i] == a[ViTri])
		{
			dem++;
		}
	}
	return dem;
}
void LietKeCacGiaTriXuatHienDung1Lan(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int CheckTrung = KiemTraBiTrung1(a, n, i);
		if (CheckTrung == 1)
		{
			int dem = DemSoLuongPhanTuTrung(a, n, i);
			if (dem == 1) 
			{
				printf("%d ", a[i]);
			}
		}
	}
}
//----------------------------------------------------------------------------------
template <typename vanhoang>
vanhoang kiemtrabitrung2(vanhoang*a, int n, int vitri)
{
	for (int i = vitri - 1; i >= 0; i--) 
	{
		if (a[i] == a[vitri])
		{
			return 0;  // bị trùng
		}
	}
	return 1;         // không bị trùng
}
template <typename vanhoang>
// Đếm xem từ vị trí hiện tại trở về sau có bao nhiêu phần tử bị trùng
vanhoang DemSoLuongPhanTuTrung(vanhoang *a, int n, int ViTri)
{
	vanhoang dem = 1;
	for (int i = ViTri + 1; i < n; i++) 
	{
		if (a[i] == a[ViTri]) 
		{
			dem++;
		}
	}
	return dem;
}
template <typename vanhoang>
void LietKeCacGiaTriXuatHienQua1Lan(vanhoang*a, int n)
{
	for (int i = 0; i < n; i++) 
	{
		int CheckTrung = kiemtrabitrung2(a, n, i);
		if (CheckTrung == 1) 
		{
			int dem = DemSoLuongPhanTuTrung(a, n, i);
			if (dem > 1) 
			{
				printf("\n%d ", a[i]);
			}
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
	//DemSoLuongPhanTuKeNhauMaCa2DeuChan(a, n);
	//DemSoLuongPhanTuKeNhauMaCa2TraiDau(a,n);
	//DemSoPhanTuKeNhau(a,n);
	//GiaoHop2Ham(a,n);
	//LietKeCacGiaTriXuatHienDung1Lan(a,n);
	//LietKeCacGiaTriXuatHienQua1Lan(a,n);
	int dem = DemSoLuongPhanTuKeNhauMaCa2DeuChan(a, n);
	cout << "\n" << dem;
	delete[]a;
	return 0;
}
