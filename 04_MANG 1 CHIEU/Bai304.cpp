Cho mảng một chiều các số nguyên dương.Hãy viết hàm tìm bội chung nhỏ nhất của tất cả các phần tử trong mảng .
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(int& n) {
    do {
        printf("Nhap so luong phan tu: ");
        scanf("%d", &n);
        if (n<1||n>Max) {
            printf("Phan tu nhap khong hop le, xin hay kiem tra lai!\n");
        }
    } while (n<1||n>Max);
}
void NhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("a[%d]= ", i);
        scanf("%d", &a[i]);
    }
}
void XuatMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d  ", a[i]);
    }
}
int TimSoLonNhatCuaMang(int a[], int n){
    int max = a[0];
    for (int i = 1; i < n; i++){
        if (a[i] > max){
            max = a[i];
        }
    }
    return max;
}
/*
Tìm BCNN  1 2 3
vị trí i  0 1 2
Khởi tạo BCNN = 3
i = 0: 3 % 1 == 0 -> BCNN = 3
i = 1: 3 % 2 != 0 -> 3 không thể là bội số của 2 được nên ta sẽ tăng thêm biến max lên
rồi xét lại từ đầu xem số max đó có chia hết cho các số trong mảng hay không và nhớ đặt cho i <= 0
i lúc này lại reset lại từ 0 và BCNN là 6
BCNN += max = 3+3= 6
i = 0: 6 % 1 == 0 -> BCNN = 6
i = 1: 6 % 2 == 0 -> BCNN = 6
i = 2: 6 % 3 == 0 -> BCNN = 6
-> BCNN cần tìm là 6. Bài này với bài tìm ước chung khá khoai :vv
*/
int TimBCNN(int a[], int n)
{
    int max = TimSoLonNhatCuaMang(a, n);
    int boiso = max;
    for (int i = 0; i < n; i++){
        if (boiso % a[i] != 0){
            boiso += max;
            i = 0;
        }
    }
    return boiso;
}
int main() {
    int a[Max], n;
hoang:
    NhapDuLieu(n);
    NhapMang(a, n);
    XuatMang(a, n);
    int tim = TimBCNN(a,n);
    printf("\nBCNN cua cac phan tu trong mang: %d", tim);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    return 0;
}
