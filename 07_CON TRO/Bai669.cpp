Thêm, xóa nhiều phần tử đằng sau số chẵn

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void NhapMang(int *a, int n)
{
    for(int i =0;i<n;++i)
    {
        printf("a[%d]= ",i);
        scanf("%d",&a[i]);
    }
}
void XuatMang(int *a, int n)
{
    for(int i =0;i<n;++i)
    {
        printf("%d ",a[i]);
    }
}
void ThemPhanTu(int *&a, int &n, int phantuthem, int vitrithem)
{
    realloc(a, (n+1) * sizeof(int));
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
    realloc(a, n * sizeof(int));
    // nếu không có realloc thì thực chất n-- là không cho chạy đến cuối cùng mà thôi (nghĩa là số đó chưa mất hoàn toàn).
}
void ThemNhieuPhanTu(int *&a, int &n, int soluongphantuthem)
{
    for(int i =0;i<n;++i)
    {
        if(a[i] % 2 == 0)
        {
            for(int j = 1;j<= soluongphantuthem;++j)
            {
                ThemPhanTu(a,n,2002,i+1);
                i++; // bỏ qua phần tử trước đó không cần xét thêm lần nữa
            }
        }
    }
}
void XoaNhieuPhanTu(int *&a, int &n)
{
    for(int i =0;i<n;++i)
    {
        if(a[i] % 2 == 0)
        {
            {
                XoaPhanTu(a,n,i);
                i--; // bỏ qua phần tử trước đó không cần xét thêm lần nữa
            }
        }
    }
}
int main()
{
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d",&n);
    int *a = (int *) realloc(NULL, n * sizeof(int));
    NhapMang(a,n);
    XuatMang(a,n);
    ThemNhieuPhanTu(a,n,3);
    printf("\n");
    XuatMang(a,n);
    XoaNhieuPhanTu(a,n);
    printf("\n");
    XuatMang(a,n);
    free(a);
    return 0;
}
