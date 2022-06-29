Viết chương trình nhập vào mảng các số nguyên và hiện ra 1 Menu như sau:

----------------- Menu -----------------
1. Them 1 phan tu vao mang.
2. Xoa 1 phan tu khoi mang.
3. Xuat mang.
0. Ket thuc.
-------------------------------------------
LƯU Ý: DÙNG CON TRỎ ĐỂ LÀM.
- Ở lựa chọn 1 sẽ cho phép người dùng nhập vào phần tử thêm & vị trí thêm
- Ở lựa chọn 2 sẽ cho phép người dùng nhập vào vị trí cần xóa.

#include <stdio.h>
#include <conio.h>
#include <windows.h>
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
}
int main()
{
    int n, phantuthem, vitrithem, vitrixoa;
    printf("Vui long nhap so luong phan tu: ");
    scanf("%d",&n);
    int *a = (int *)realloc(NULL,n * sizeof(int));
    NhapMang(a,n);
    while(true)
    {
        system("cls");
        printf("\n----------------- Menu -----------------\n\tVui long lua chon: \n1.Them 1 phan tu vao mang.\n2.Xoa 1 phan tu ra khoi mang.\n3.Xuat mang.\n----------------------------------------\nLua chon cua ban: ");
        char luachon = getch();
        if(luachon == '1')
        {
            system("cls");
            printf("Nhap phan tu can them: "); scanf("%d",&phantuthem);
            printf("Nhap vi tri phan tu can them: "); scanf("%d",&vitrithem);
            ThemPhanTu(a,n,phantuthem,vitrithem);
            printf("\nDa them!");
            getch();
        }
        else if(luachon == '2')
        {
            system("cls");
            printf("Nhap vi tri phan tu can xoa: "); scanf("%d",&vitrixoa);
            XoaPhanTu(a,n,vitrixoa);
            printf("\nDa xoa!");
            getch();
        }
        else if(luachon == '3')
        {
            system("cls");
            printf("\nMang la: ");
            XuatMang(a,n);
            getch();
        }
        else
        {
            break;
        }
    }
    free(a);
    return 0;
}
