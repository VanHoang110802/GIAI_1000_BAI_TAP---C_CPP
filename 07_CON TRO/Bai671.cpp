Viết chương trình đổi nhiều số sang các hệ cơ số khác nhau (hệ 2,8,16).

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void NhapDuLieu(int& n) {
	do {
		printf("Nhap so luong phan tu can quy doi: ");
		scanf("%d", &n);
		if (n<1) {
			printf("So luong phan tu nhap khong hop le, xin hay kiem tra lai!\n");
		}
	} while (n<1);
}
/*
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
*/
// Muốn nhập tay thì dùng hàm ở đây :
void NhapMang(int *a, int n) {
	for (int i = 0; i < n; ++i) {
		printf("Nhap so can do thu [%d] = ", i + 1);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int *a, int n) {
	printf("\t\t");
	for (int i = 0; i < n; i++) {
		printf("%d\t", a[i]);
	}
}

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
void TinhQuyDoiSangNhiPhan(int *a, int n) {
	for (int i = 0; i < n; i++) {
		int qdnp = QuyDoiSangNhiPhan(a[i]);
		printf("%d\t ", qdnp);
	}
}
void TinhQuyDoiSangBatPhan(int *a, int n) {
	for (int i = 0; i < n; i++) {
		int qdnp = QuyDoiSangHeBatPhan(a[i]);
		printf("%d\t", qdnp);
	}
}
void TinhQuyDoiSangHeThapLucPhan(int *a, int n) {
	printf("\t");
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			int temp1 = QuyDoiSangHeThapLucPhan(a[i]);
			//printf("%d\t", Tinh1(temp1));
			int demchuso = log10((double)temp1);
			if (demchuso % 2 == 0) 
			{
				demchuso += 2;
			}
			else if (demchuso % 2 != 0) 
			{
				demchuso--;
			}
			while (temp1 != 0) 
			{
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
	int n;
	int *a = (int *)realloc(NULL, n * sizeof(int));
hoang:
    printf("\n\t\tChuong trinh doi nhieu so sang he co so 2 - 8 - 16\n");
	NhapDuLieu(n);
	NhapMang(a,n);
	printf("\n\tSO CAN DOI: ");
	XuatMang(a, n);
	printf("\n\n -> HE NHI PHAN(2):\t\t");
	TinhQuyDoiSangNhiPhan(a, n);
	printf("\n\n -> HE BAT PHAN(8):\t\t");
	TinhQuyDoiSangBatPhan(a, n);
	printf("\n\n -> HE THAP LUC PHAN(16):");
	TinhQuyDoiSangHeThapLucPhan(a, n);
	free(a);
	printf("\n");
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if (lc == 'c' || lc == 'C') {
		system("cls");
		goto hoang;
	}
	return 0;
}
