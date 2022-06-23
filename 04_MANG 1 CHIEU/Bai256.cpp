Chương trình tổng hợp đổi cơ số 3 hệ : Đổi số nguyên dương n (hệ 10) sang nhị
phân (hệ 2),sang hệ bát phân (hệ 8) và sang hệ hexa (hệ 16) .
/*
đầu tiên ta sẽ xét với số tự nhiên n. Gỉa sử n = 8 -> đổi sang nhị phân là: 1000
ta sẽ có 1 vòng lặp, lấy n % 2, rồi có 1 biến temp lưu lại số dư đó, rồi chia 2 để xét sang số khác. Sau đó, ta có biến i, i là hệ cơ số 10, mỗi lần chia 2 xét sang số khác ta lấy i đó đem cộng với biến temp, tăng i lên gấp 10 lần đơn vị, chứu như thế cho đến khi vòng lặp lặp đến n <= 0 thì ngừng lại, lúc này ta sẽ có được số cần tìm. Và đổi từ hệ số thập phân sang hệ số bát phân cũng na ná như vậy, nếu làm qua mảng thì chỉ đổi được 1 phần tử mà thôi, còn nếu đổi toàn phần tử trong mảng thì mình không nghĩ ra nổi, tìm gg cũng không có tài liệu tham khảo.

BÀI NÀY VỀ PHẦN CHUYỂN CÁC PHẦN TỬ MANG THÀNH SỐ THẬP LỤC PHÂN MÌNH ĐÉO BIẾT LÀM, CHỊU THUA PHẦN NÀY, NGHĨ KHÔNG RA NỔI, CHỈ NGHĨ RA ĐƯỢC CÁC TRƯỜNG HỢP CÒN LẠI

(Ngày 03/02/2022, đã làm xong ).
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <conio.h>
#include <Windows.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define Max 100

void NhapDuLieu(int& n) {
	do {
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if (n<1 || n>Max) {
			printf("So luong phan tu nhap khong hop le, xin hay kiem tra lai!\n");
		}
	} while (n<1 || n>Max);
}
// cho các phần tử là 1 số ngẫu nhiên
void PhatSinhNgauNhien(int a[], int n) {
	srand(time(0));
	for (int i = 0; i < n; i++) a[i] = 1 + (rand() % 200);
}
void XuatMang(int a[], int n) {
	printf("\t\t\t\t");
	for (int i = 0; i < n; i++) {
		printf("%d\t", a[i]);
	}
}
/*
// Muốn nhập tay thì dùng hàm ở đây :
void NhapMang(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		printf("a[%d]= ", i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n) {
	printf("\t\t\t\t");
	for (int i = 0; i < n; i++) {
		printf("%d\t", a[i]);
	}
}
*/
/*
đổi hệ cơ số 10 -> 16:
992 = 03E0
3045 = 0BE5
1992 = 07C8
191 = 0BF
90 = 05A
45 = 02D
3456 = 0D80
4555 = 011CB
*/
int QuyDoiSangNhiPhan(int n) {
	int temp, i = 1, s = 0;
	if (n <= 0) {
		return 0;
	}
	while (n > 0) {
		temp = n % 2;       // biến phụ lưu lại số dư
		n /= 2;
		s += (i * temp);
		i *= 10;
	}
	return s;
}
void TinhQuyDoiSangNhiPhan(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int qdnp = QuyDoiSangNhiPhan(a[i]);
		printf("%d\t ", qdnp);
	}
}
int QuyDoiSangHeBatPhan(int n) {
	int i = 0, temp;
	int s = 0;
	while (n > 0) {
		temp = n % 8;	// bien temp luu lai so du
		s += temp * pow(10, i);
		i++;
		n /= 8;
	}
	return s;
}
void TinhQuyDoiSangBatPhan(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int qdnp = QuyDoiSangHeBatPhan(a[i]);
		printf("%d\t", qdnp);
	}
}
int QuyDoiSangHeThapLucPhan(int n) {
	int i = 1, temp, s = 0;
	while (n > 0) {
		temp = n % 16;
		s += (i * temp);
		i *= 100;
		n /= 16;
	}
	return s;
}
void TinhQuyDoiSangHeThapLucPhan(int a[], int n) {
	printf("\t");
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			int temp1 = QuyDoiSangHeThapLucPhan(a[i]);
			//printf("%d\t", Tinh1(temp1));
			int demchuso = log10((double)temp1);
			if (demchuso % 2 == 0) {
				demchuso += 2;
			}
			else if (demchuso % 2 != 0) {
				demchuso--;
			}
			while (temp1 != 0) {
				int tinh = pow(10, demchuso);
				int chuso = temp1 / tinh;
				if (chuso < 10) printf("%d", chuso);
				else if (chuso == 10) printf("A");
				else if (chuso == 11) printf("B");
				else if (chuso == 12) printf("C");
				else if (chuso == 13) printf("D");
				else if (chuso == 14) printf("E");
				else if (chuso == 15) printf("F");
				temp1 %= tinh;
				demchuso -= 2;
			}
		}
		printf("\t");
	}
}
int main() {
	int n, a[Max];
hoang:
	NhapDuLieu(n);
	//NhapMang(a,n);
	PhatSinhNgauNhien(a, n);
	printf("\n");
	XuatMang(a, n);
	printf("\n\n -> HE NHI PHAN(2):\t\t");
	TinhQuyDoiSangNhiPhan(a, n);
	printf("\n\n -> HE BAT PHAN(8):\t\t");
	TinhQuyDoiSangBatPhan(a, n);
	printf("\n\n -> HE THAP LUC PHAN(16):");
	TinhQuyDoiSangHeThapLucPhan(a, n);
	printf("\n");
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = _getch();
	if (lc == 'c' || lc == 'C') {
		system("cls");
		goto hoang;
	}
	return 0;
}
