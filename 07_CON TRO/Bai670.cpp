Viết lại hàm realloc bên C (bên C++ không có hỗ trợ hàm này - MẢNG 1 CHIỀU)

#include <iostream>
using namespace std;
void NhapMang(int *a, int n)
{
    for(int i = 0;i<n;++i)
    {
       cout << "a[" << i << "]= ";
       cin >> a[i];
    }
}
void XuatMang(int *a, int n)
{
    for(int i =0;i<n;++i)
    {
        cout << " " << a[i];
    }
}
void REALLOC(int *&a, int SizeCu, int SizeMoi)
{
	int *temp = new int[SizeCu]; // khởi tạo mảng phụ
	// lưu từng phần tử mảng chính sang mảng phụ
	for(int i =0;i<SizeCu;++i)
	{
		temp[i] = a[i];
		
	}	
	delete[] a;	// xóa mảng chính này đi
	a = new int[SizeMoi]; // tạo lại mảng chính mới và cấp dư ra 1 ô
	// chuyển lại từng phần tử ở mảng phụ sang lại mảng chính mới
	for(int i =0;i<SizeCu;++i)
	{
		a[i] = temp[i];
		
	}	
	delete[] temp;	// xóa mảng phụ không cần thiết này đi
}
void ThemPhanTu(int *&a, int &n, int phantuthem, int vitrithem)
{
    //realloc(a, (n+1) * sizeof(int));
    REALLOC(a,n,n+1);
    for(int i = n -1;i>= vitrithem; --i)
    {
        a[i+1] = a[i];
    }
    a[vitrithem] = phantuthem;
    n++;
}
void XoaPhanTu(int *&a, int &n, int vitrixoa)
{
    for(int i = vitrixoa + 1;i<n; ++i)
    {
        a[i-1] = a[i];
    }
    n--;
    //realloc(a, n * sizeof(int));
    REALLOC(a,n,n);
    // nếu không có realloc thì thực chất n-- là không cho chạy đến cuối cùng mà thôi (Số đó chưa mất hoàn toàn).
}
int main()
{
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    int *a = new int[n];
    NhapMang(a,n);
    XuatMang(a,n);
    ThemPhanTu(a,n,69,3);
    cout << "\n";
    XuatMang(a,n);
    XoaPhanTu(a,n,3);
    cout << "\n";
    XuatMang(a,n);
    delete[] a;
    return 0;
}
