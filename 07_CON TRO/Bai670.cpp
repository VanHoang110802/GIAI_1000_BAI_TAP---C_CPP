Viết chương trình đổi 1 số x sang hệ 2,8,16.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

void NhapDuLieu(int& n) {
	do {
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if (n<1) {
			printf("So luong phan tu nhap khong hop le, xin hay kiem tra lai!\n");
		}
	} while (n<1);
}
void NhapMang(int *a, int n) {
	for (int i = 0; i < n; ++i) {
		printf("a[%d]= ", i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int *a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\t", a[i]);
	}
}
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
void LietKe(int *a, int n, int luachon) {
	for (int i = 0; i < n; i++) {
		if (luachon == 2) {
			int qdnp = QuyDoiSangNhiPhan(a[i]);
			printf("%d\t", qdnp);
		}
		else if(luachon == 8)
		{
		    int qdnp = QuyDoiSangHeBatPhan(a[i]);
            printf("%d\t", qdnp);
		}
		else if(luachon == 16)
		{
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
            	printf("\t");
		}
	}
}
int main() {
	int n, luachon;
	int *a = (int *)realloc(NULL, n * sizeof(int));
hoangdeptrai:
	NhapDuLieu(n);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\nNhap he co so muon doi (2 - 8 - 16): ");
	scanf("%d",&luachon);
	LietKe(a, n, luachon);
	free(a);
	printf("\nBan co muon tiep tuc chuong trinh hay khong?\nNeu co xin hay bam c, neu khong bat phim bat ki de thoat\n");
	char lc = getch();
	if(lc == 'c' || lc =='C'){
        system("cls");
		goto hoangdeptrai;
	}
	return 0;
}
