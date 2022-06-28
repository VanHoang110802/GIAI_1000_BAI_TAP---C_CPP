/*
Con trỏ bên C++:
Cấp phát: dùng new
Giải phóng: delete.
 - malloc,calloc,realloc: là hàm tạo ra vùng nhớ và cho con trỏ trỏ tới vùng nhớ được trả về
 - new: là toán tử hỗ trợ cấp phát bộ nhớ.
Công nghệ lập trình bây giờ có 3 thời kì: lập trình tuyến tính, lập trình thủ tục hàm, lập trình hướng đối tượng. Thì thời kì mới nhất bây giờ là hướng đối tượng. Trong hướng đối tượng có những tính chất đặc biệt cần quan tâm:
+ Tính đóng gói
+ Tính kế thừa
+ Tính đa hình
Để sử dụng, xây dựng được tính đa hình, thì phải dùng đến toán tử new, còn các hàm trên sẽ không xây dựng được.

Lưu ý: Nếu cấp phát theo kiểu của C thì phải giải phóng theo kiểu của C và C++ cũng thế.
-> Nếu lấy cái này dùng cho cái kia -> lỗi ngầm 1 số trường hợp.

realloc bên C hỗ trợ cho ta tăng hay giảm bớt số lượng vùng nhớ nhưng bên C++ thì không có hỗ trợ, vì vậy, ta không thể sử dụng realloc ở bên C++ mà bắt buộc phải viết 1 hàm realloc (Tốt hơn hết, để tên nên tránh tên mặc định có sẵn, có 2 chữ hoa là ổn nhất chứ không phải cứ toàn hoa là ổn nhất).
*/

// giờ ta sẽ viết lại realloc bên c++ nha:
#include <iostream>
using namespace std;
void NhapMang(int *a, int n){
    for(int i=0;i<n;i++){
        cout << "a[" << i<<"]= ";
        cin >> a[i];
    }
}

void XuatMang(int *a, int n){
    for(int i=0;i<n;i++){
        cout << " " <<a[i];
    }
}
void REALLOC(int *&a, int OldSize, int NewSize){
    // B1: Tạo ra 1 mảng mới là bản sao của bản cũ, đổ dữ liệu từ mảng cũ sang:
    int *temp = new int[OldSize];
    for (int i = 0; i < OldSize; i++)
    {
        temp[i] = a[i];
    }
    // B2: Xoas mảng cũ đi và cấp mới lại:
    delete[] a;
    a = new int[NewSize];

    // B3: Đổ dữ liệu từ mảng tạm sang mảng mới:
    int min = OldSize < NewSize ? OldSize : NewSize;
    for (int i = 0; i < min; i++)
    {
        a[i] = temp[i];
    }
    // B4: Xóa mảng tạm đi
    delete[] temp;
}
void ThemPhanTu(int *&a, int &n, int vitrithem, int phantucanthem){
    REALLOC(a,n,n+1);
   for (int i = n- 1; i >= vitrithem; i--)
    {
        a[i + 1] = a[i];
    }
    a[vitrithem] = phantucanthem;
    n++;
}
void XoaPhanTu(int *&a, int &n, int vitrixoa){
   for (int i = vitrixoa + 1; i < n; i++)
    {
        a[i - 1] = a[i];
    }
    REALLOC(a,n,n - 1);
    n--;
    
}
int main()
{
    int *a , n =5;
    a = new int[n];
    NhapMang(a,n);
    XuatMang(a,n);
   cout << endl;
    int vitrithem = 2, phantucanthem = 1108;
    ThemPhanTu(a,n,vitrithem,phantucanthem);
    XuatMang(a,n);

    cout << endl;
    int vitrixoa = 2;
    XoaPhanTu(a,n,vitrixoa);
    XuatMang(a,n);
    // giải phóng tất cả:
    delete []a;
    return 0;
} 
