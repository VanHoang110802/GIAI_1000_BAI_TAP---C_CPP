/*
Liệt kê tất cả các mảng con trong mảng một chiều các số nguyên.

Liệt kê tất cả các mảng con có độ dài lớn hơn 2 trong mảng một chiều các số nguyên

Liệt kê các dãy con tăng trong mảng.

Hãy liệt kê các mảng con tăng có chứa giá trị lớn nhất trong mảng.

Tính tổng từng mảng con tăng trong mảng một chiều các số thực.

Đếm số lượng mảng con tăng có độ dài lớn hơn 1 trong mảng một chiều số thực.

Liệt kê các dãy con toàn dương có độ dài lớn hơn 1 trong mảng một chiều số thực.

Đếm số lượng mảng con giảm trong mảng một chiều các số thực.
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
//----------------------------------------------------------------------------------------------------------------------
/*
mảng: 1 2 3 4 5
các mảng con: 1       | 2       | 3      | 4    | 5
		  1 2     | 2 3     | 3 4    | 4 5
		  1 2 3   | 2 3 4   | 3 4 5
		  1 2 3 4 | 2 3 4 5
		  1 2 3 4 5
Ta cần phải xác định được độ dài mảng, rồi có vòng lặp duyệt các phần của của mảng lồng kèm vòng lặp duyệt các chiều dài 
của mảng, rồi từ đó đi liệt kê các phần tử theo chiều dài của mảng đã duyệt trước đó, ví dụ nếu mảng có chiều dài là 2 thì
gồm có 4 mảng con.
*/

void LietKeTatCaMangCon(int *a, int n) 
{
	int ChieuDai;  // độ dài mảng con
	for (int i = 0; i < n; ++i)
	{
		for (ChieuDai = i; ChieuDai <= n; ++ChieuDai)
		{		// nếu bỏ vòng for này thì sao ? thì chương trình nó sẽ không hiểu chiều dài được khai báo như nào?
			for (int j = i; j < ChieuDai; ++j) 
			{
				cout << a[j] << "  ";
			}
			cout << " \n" ;		// ngăn cách mỗi mảng con ra 
		}
	}
}
//----------------------------------------------------------------------------------------------------------------------
void LietKeTatCaMangConDoDaiLonHon2PhanTu(int *a, int n)
{
	int ChieuDai;  // độ dài mảng con
	for (int i = 0; i < n; ++i) 
	{
		for (ChieuDai = 3 + i; ChieuDai <= n; ++ChieuDai) 
		{	// nếu bỏ vòng for này thì sao ?
			for (int j = i; j < ChieuDai; ++j) 
			{
				cout << a[j] << "  ";
			}
			cout << "\n";
		}
	}
}
//----------------------------------------------------------------------------------------------------------------------
int KiemTraTangDan(int *b, int nb) 
{
	for (int i = 0; i < nb - 1; ++i) 
	{
		if (b[i] > b[i + 1]) 
		{
			return 0;
		}
	}
	return 1;
}

void XuatMangCon(int *b, int nb) 
{
	for (int i = 0; i < nb; ++i) 
	{
		cout << b[i] << "  ";
	}
	cout << "\n";
}

void LietKeDayConTangDan(int *a, int n)
{
	int ChieuDai;
	int *b, nb;
	b = new int[n + n];
	for (int i = 0; i < n; ++i) 
	{
		for (ChieuDai = 1; ChieuDai <= n; ++ChieuDai) 
		{
			nb = 0;
			for (int j = i; j < ChieuDai; ++j) 
			{
				b[nb] = a[j];
				nb++;
			}
			if (KiemTraTangDan(b, nb) == 1) 
			{
				XuatMangCon(b, nb);
			}
		}
	}
	delete[]b;
}

//----------------------------------------------------------------------------------------------------------------------
int TimMax(int *a, int n) 
{
	int max = a[0];
	for (int i = 1; i < n; ++i)
	{
		max = a[i] > max ? a[i] : max;
	}
	return max;
}
//int KiemTraTangDan(int *b, int nb) 
//{
//	for (int i = 0; i < nb - 1; ++i)
//	{
//		if (b[i] > b[i + 1])
//		{
//			return 0;
//		}
//	}
//	return 1;
//}

//void XuatMangCon1(int *b, int nb)
//{
//	for (int i = 0; i < nb; ++i) 
//	{
//		cout << b[i] << "  ";
//	}
//	cout << "\n";
//}

int KiemTraCoMax(int *b, int nb, int max)
{
	for (int i = 0; i < nb; ++i) 
	{
		if (b[i] == max) 
		{
			return 1;
		}
	}
	return 0;
}
void LietKeDayConTangDanVaChuaGiaTriMax(int *a, int n, int max)
{
	int ChieuDai;
	int *b, nb;
	b = new int[n];
	for (int i = 0; i < n; ++i)
	{
		for (ChieuDai = 1; ChieuDai <= n; ++ChieuDai) 
		{
			nb = 0;
			for (int j = i; j < ChieuDai; ++j)
			{
				b[nb] = a[j];
				nb++;
			}
			if (KiemTraTangDan(b, nb) == 1) 
			{
				if (KiemTraCoMax(b, nb, max) == 1)
				{
					XuatMangCon(b, nb);
				}
			}
		}
	}
	delete[]b;
}
//----------------------------------------------------------------------------------------------------------------------
//int KiemTraTangDan(int *b, int nb) 
//{
//	for (int i = 0; i < nb - 1; ++i) 
//	{
//		if (b[i] > b[i + 1])
//		{
//			return 0;
//		}
//	}
//	return 1;
//}

void XuatMangCon2(int *b, int nb) 
{
	for (int i = 0; i < nb; i++) 
	{
		cout << b[i] << "  ";
	}
}

int TongMangCon(int *b, int nb) 
{
	int Tong = 0;
	for (int i = 0; i < nb; ++i) 
	{
		Tong += b[i];
	}
	return Tong;
}
void TinhTongTungMangConTang(int *a, int n) 
{
	int ChieuDaiCon, Tong;
	int *b, nb;
	b = new int[n + n];
	for (int i = 0; i < n; i++) 
	{
		for (ChieuDaiCon = 1; ChieuDaiCon <= n; ++ChieuDaiCon)
		{
			nb = 0;
			for (int j = i; j < ChieuDaiCon; ++j) 
			{
				b[nb] = a[j];
				nb++;
			}
			if (KiemTraTangDan(b, nb) == 1) 
			{
				XuatMangCon2(b, nb);
				Tong = TongMangCon(b, nb);
				if (Tong < 1)
				{
					cout << "\n0";
				}
				else cout << " -> Tong mang nay = " <<  Tong << "\n";
			}
		}
	}
	delete[] b;
}
//----------------------------------------------------------------------------------------------------------------------
//void XuatMangCon(int *b, int nb) 
//{
//	for (int i = 0; i < nb; i++)
//	{
//		cout << b[i] << "  ";
//	}
//	cout << "\n";
//}
//int KiemTraTangDan(int *b, int nb) 
//{
//	for (int i = 0; i < nb - 1; i++)
//	{
//		if (b[i] > b[i + 1])
//		{
//			return 0;
//		}
//	}
//	return 1;
//}

void DemMangConTang(int *a, int n) 
{
	int ChieuDaiCon, dem = 0;
	int *b, nb;
	b = new int[n + n];
	for (int i = 0; i < n; ++i) {
		for (ChieuDaiCon = 2 + i; ChieuDaiCon <= n; ++ChieuDaiCon)
		{ // phải có hơn 2 phần tử
			nb = 0;
			for (int j = i; j < ChieuDaiCon; ++j) 
			{
				b[nb] = a[j];
				nb++;
			}
			if (KiemTraTangDan(b, nb) == 1) 
			{
				XuatMangCon(b, nb);
				dem++;
			}
		}
	}
	printf("\nTong so mang can tim: %d\n", dem);
	delete[] b;
}
//----------------------------------------------------------------------------------------------------------------------
int KiemTraMangDuong(int *b, int nb) 
{
	for (int i = 0; i < nb; i++) 
	{
		if (b[i] < 0) 
		{
			return 0;
		}
	}
	return 1;
}

//void XuatMangCon(int b[], int nb)
//{
//	for (int i = 0; i < nb; i++) 
//	{
//		cout << b[i] << "  ";
//	}
//	cout << "\n";
//}
void LietKeDayConToanDuongVaDoDaiLonHon1(int *a, int n) 
{
	int ChieuDaiCon;
	int *b, nb;
	b = new int[n + n];
	for (int i = 0; i < n; i++) 
	{
		for (ChieuDaiCon = 2 + i; ChieuDaiCon <= n; ChieuDaiCon++) 
		{ // phải có hơn 2 phần tử

			nb = 0;
			for (int j = i; j < ChieuDaiCon; j++) 
			{
				b[nb] = a[j];
				nb++;
			}
			if (KiemTraMangDuong(b, nb) == 1) 
			{
				XuatMangCon(b, nb);
			}
		}
	}
	delete[] b;
}
//----------------------------------------------------------------------------------------------------------------------
//void XuatMangCon(int b[], int nb)
//{
//	for (int i = 0; i < nb; i++) 
//	{
//		cout << b[i] << "  ";
//	}
//	cout << "\n";
//}
int KiemTraGiamDan(int b[], int nb)
{
	for (int i = 0; i < nb - 1; i++) 
	{
		if (b[i] < b[i + 1]) 
		{
			return 0;
		}
	}
	return 1;
}

void DemMangConGiam(int *a, int n)
{
	int ChieuDaiCon, dem = 0;
	int *b, nb;
	b = new int[n + n];
	for (int i = 0; i < n; i++) 
	{
		for (ChieuDaiCon = 1 + i; ChieuDaiCon <= n; ChieuDaiCon++) 
		{
			nb = 0;
			for (int j = i; j < ChieuDaiCon; j++)
			{
				b[nb] = a[j];
				nb++;
			}
			if (KiemTraGiamDan(b, nb) == 1) 
			{
				XuatMangCon(b, nb);
				dem++;
			}
		}
	}
	cout << "\nTong so mang con giam can tim: " << dem << "\n";
	delete[]b;
}
//----------------------------------------------------------------------------------------------------------------------
int KiemTraMangACoPhaiLaMangConCuaMangB(int *a, int *b, int na, int nb) 
{
	int i, j, Check = 0;
	for (i = 0; i < nb; i++) 
	{           // Duyệt mảng b coi
		if (b[i] == a[0]) 
		{       // Nếu mà thấy bất kỳ phần tử nào của mảng b
								 // mà bằng phần tử đầu tiên của mảng a
			int Start = i;      // bắt đầu đếm tại vị trí đó
			Check = 1;
			for (j = 0; j < na; j++) 
			{
				if (a[j] != b[Start++]) 
				{    // Kiểm tra coi có cái nào khác không ?
					Check = 0;               // Nếu có thì biến
					break;
				}
			}
			if (Check == 1) 
			{     // đi hết vòng lặp nếu mà không có cái nào khác
				return Check; // Mảng a là mảng con của b
			}
		}
	}
	return Check;
}

int main()
{
	int n;
	NhapDuLieu(n);
	int* a = new int[n];
	NhapMang(a, n);
	XuatMang(a, n);
	cout << "\n\n";
	LietKeTatCaMangCon(a, n);
	//LietKeDayConTangDan(a, n);
	//LietKeTatCaMangConDoDaiLonHon2PhanTu(a,n);
	//LietKeDayConTangDanVaChuaGiaTriMax(a, n, 4);
	//LietKeDayConToanDuongVaDoDaiLonHon1(a, n);
	//TinhTongTungMangConTang(a,n);
	//DemMangConTang(a,n);
	//DemMangConGiam(a,n);
	delete[]a;
	/*int n, m;
	NhapDuLieu(n);
	int* a = new int[n];
	NhapMang(a, n);
	NhapDuLieu(m);
	int* b = new int[m];
	NhapMang(b, m);
	XuatMang(a, n);
	cout << "\n\n";
	XuatMang(b, m);
	cout << "\n\n";
	int kt = KiemTraMangACoPhaiLaMangConCuaMangB(a, b, n, m);
	cout << kt;
	//XuatMang(a, n);
	delete[]a;
	delete[]b;
	*/
	return 0;
}
