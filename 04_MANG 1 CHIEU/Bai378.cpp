Cho hai mảng a và b.Hãy đếm số lần xuất hiện của mảng a trong mảng b ? .

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#define Max 100
void NhapDuLieu(int& n) {
	do {
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if (n<1||n>Max) {
			printf("So luong phan tu nhap khong hop le, xin hay kiem tra lai!\n");
		}
	} while (n<1||n>Max);
}
void NhapMang(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		printf("a[%d]= ", i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d  ", a[i]);
	}
}

/*
duyệt mảng b, nếu mà phần tử đầu tiên của mảng a bằng với 1 phần tử bất kỳ của mảng b
và số phần tử mảng b đó trừ đi i lớn hơn hoặc bằng số phần tử mảng a
h = i -> biến h sẽ là biến bắt đầu để đếm, khởi tạo ngay tại i thỏa DK
*/

int DemSoLanXuatHienCuaMangATrongMangB(int a[], int b[], int na, int nb) {
	int i, j, Start, check, dem = 0;
	for (i = 0; i < nb; i++) {
		if (a[0] == b[i] && nb - i >= na) {
			Start = i;
			check = 1;
			for (j = 0; j < na; j++) {
				if (a[j] != b[Start++]) {
					check = 0;
					break;
				}
			}
			if (check == 1) {
				dem++;
			}
		}
	}
	return dem;
}
int main(){
	int n,m, a[Max],b[Max];
hoang:
	printf("\n");
	NhapDuLieu(n);
	NhapMang(a, n);
	printf("\n");
	NhapDuLieu(m);
	NhapMang(b, m);
	printf("\nMang A:\n");
	XuatMang(a, n);
	printf("\nMang B:\n");
	XuatMang(b, m);
	printf("\n");
	int dem = DemSoLanXuatHienCuaMangATrongMangB(a, b,n,m);
	printf("\n-> %d", dem);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
