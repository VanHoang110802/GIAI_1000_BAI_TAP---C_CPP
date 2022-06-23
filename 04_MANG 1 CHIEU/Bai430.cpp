Cho hai mảng a và b.Hãy cho biết mảng a có phải là mảng con của mảng b hay không ?

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <conio.h>
#include<math.h>
#define Max 100

void NhapDuLieu(int& n) {
	do {
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if (n<0 || n>Max) {
			printf("So luong phan tu nhap khong hop le, xin hay kiem tra lai!\n");
		}
	} while (n<0 || n>Max);
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
int KiemTraMangACoPhaiLaMangConCuaMangB(int a[], int b[], int na, int nb){
	int i, j, Check = 0;
	for (i = 0; i < nb; i++) {           // Duyệt mảng b coi
		if (b[i] == a[0]) {       // Nếu mà thấy bất kỳ phần tử nào của mảng b
		                         // mà bằng phần tử đầu tiên của mảng a
			int Start = i;      // bắt đầu đếm tại vị trí đó
			Check = 1;
			for (j = 0; j < na; j++){
				if (a[j] != b[Start++]) {    // Kiểm tra coi có cái nào khác không ?
					Check = 0;               // Nếu có thì biến
					break;
				}
			}
			if (Check == 1) {     // đi hết vòng lặp nếu mà không có cái nào khác
				return Check; // Mảng a là mảng con của b
			}
		}
	}
	return Check;
}
int main() {
	int na,nb, a[Max],b[Max];
hoang:
	NhapDuLieu(na);
	NhapMang(a, na);
	NhapDuLieu(nb);
	NhapMang(b, nb);
	printf("\n");
	XuatMang(a, na);
	printf("\n");
	XuatMang(b, nb);
	printf("\n(1- La co, 0 - La khong co)\n");
	int kt = KiemTraMangACoPhaiLaMangConCuaMangB(a, b,na,nb);
	printf("%d", kt);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
