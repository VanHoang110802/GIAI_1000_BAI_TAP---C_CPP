#include <cstdio>
#include <stdlib.h>
void NhapMang(int *a, int n){
    for(int i=0;i<n;i++){
        printf("a[%d]= ",i);
        scanf("%d",&a[i]);
    }
}

void XuatMang(int *a, int n){
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
}

int TinhTong(int *a, int n){
    int tong = 0;
    for(int i=0;i<n;i++){
        tong +=a[i];
    }
    return tong;
}
int TimMax(int *a, int n){
    int max = a[0];
    for(int i=1;i<n;i++){
        if(a[i] > max){
            max =a[i];
        }
    }
    return max;
}
int *TimMin(int *a, int n){
    int *min = &a[0];   // cho con tro min tro toi phan tu chua dia chi dau tien
    for(int i=1;i<n;i++){
        if(a[i] < *min){
            min = &a[i];    // cho con tro tro den dia chi moi
        }
    }
    return min;
}
void HoanVi(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void SapXep(int *a, int n, char phanloai){
    for(int i=0;i<n - 1;i++){
        for(int j= i+1;j<n;j++){
            if (phanloai == 't' || phanloai =='T')
            {
                if (a[i] > a[j])
                {
                    HoanVi(&a[i], &a[j]);
                }
            }
            else if (phanloai == 'g' || phanloai == 'G')
            {
                if (a[i] < a[j])
                {
                    HoanVi(&a[i], &a[j]);
                }
            }
        }
    }
}
void ThemPhanTu(int *&a, int &n, int vitrithem, int phantucanthem){
    /* vì trước đó, ta không dùng con trỏ mảng, nên ta sẽ phải tự tạo ra thừa những ô trong mảng, vậy nên khi thêm 1 ohần tử, phần tử sau 
     cùng sẽ phải lùi xuống, nhưng ở đây, ta dùng con trỏ, vậy nên ta sẽ phải realloc lại vùng nhớ ra, có thêm 1 vùng nhớ thì mới thêm được
     phần tử vào mảng
    */
   // cấp dư ra 1 ô vùng nhớ, phải cấp trước rồi mới thêm nhé:
    realloc(a,(n + 1) * sizeof(int));   
    for(int i =n-1;i>=vitrithem;i--){
        a[i+1]=a[i];
    }
    a[vitrithem] = phantucanthem;
    n++;
}
// thêm 0 vào sau các số chẵn 
void Them0VaoSauSoChan(int *&a, int &n, int soluongphantuthem){
    for(int i =0;i<n;i++){
        if(a[i] % 2 == 0){
            for(int j = 1;j<=soluongphantuthem;j++){
                ThemPhanTu(a, n, i + 1, 0);
                i++; // phải tăng lên vì nếu không chẳng may phần tử thêm nó là số chẵn thì sẽ có thêm thừa số 0.
            }
        }
    }
}
void XoaPhanTu(int *&a, int &n, int vitricanxoa){
    for(int i = vitricanxoa+ 1;i<n;i++){
        a[i - 1] = a[i];
    }
    n--;
    realloc(a, n * sizeof(int));
    // hoặc cũng có thể bỏ n-- đi, viết : realloc(a, (--n)*sizeof(int));
}
int main(){
   int n;
   do{
       printf("Nhap so luong phan tu: ");
       scanf("%d", &n);
       if(n<0){
           printf("\nSo luong phan tu nhap khong hop le!");
       }
   }while(n<0);
   int *a = (int *)realloc(NULL, n *sizeof(int));   // neu vung nho ban dau chua co gi thi NULL
   NhapMang(a,n);
   XuatMang(a,n);
   int tinh = TinhTong(a,n);
   printf("\n%d",tinh);

   int max = TimMax(a,n);
   printf("\n%d",max);

    int min = *TimMin(a,n);
   printf("\n%d",min);

   SapXep(a,n,'t');
   printf("\nSap xep tang dan: \n");
   XuatMang(a,n);
   SapXep(a,n,'g');
   printf("\nSap xep giam dan: \n");
   XuatMang(a,n);

    printf("\nMang sau khi them: ");
   int vitrithem = 2, phantuthem = 1108;
   ThemPhanTu(a,n,vitrithem,phantuthem);
  
   XuatMang(a,n);
    int vitrixoa = 4;
    printf("\nMang sau khi xoa: ");
    XoaPhanTu(a,n,vitrixoa);
    XuatMang(a,n);

    printf("\nThem 0 vao sau cac so chan: ");
    Them0VaoSauSoChan(a,n,3);
    XuatMang(a,n);
   free(a);
   return 0;
}
