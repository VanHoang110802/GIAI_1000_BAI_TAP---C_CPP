Viết chương trình cho phép tính diện tích các hình: Hình vuông; Hình chữ nhật; Hình
tròn;Tam giác; Hình thang. Người dùng chọn hình cần tính diện tích từ bảng chọn, sau đó khai báo các
thông số liên quan và nhận được diện tích của hình:
MOI BAN CHON HINH CAN TINH  DIEN TICH

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#define pi 3.14
int main() {
	int luachon;
	printf("\n---------------- MENU ------------------");
	printf("\n- Tinh dien tich hinh:                 -");
	printf("\n-    1. Hinh vuong                     -");
	printf("\n-    2. Hinh chu nhat                  -");
	printf("\n-    3. Hinh tron                      -");
	printf("\n-    4. Hinh tam giac                  -");
	printf("\n-    5. Hinh thang                     -");
	printf("\n----------------------------------------");
	printf("\nMOI BAN CHON HINH CAN TINH  DIEN TICH: ");
	scanf_s("%d", &luachon);
	if (luachon == 1) {
		int a;
		printf("Nhap canh cua hinh vuong: ");
		scanf("%d", &a);
		printf("Dien tich hinh vuong la: %d", a * a);
		return 0;
	}
	else if (luachon == 2) {
		int a, b;
		printf("Nhap chieu rong: ");
		scanf("%d", &a);
		printf("Nhap chieu dai: ");
		scanf("%d", &b);
		if (b <= a) {
			printf("Xin vui long kiem tra lai chieu dai!");
			return 0;
		}
		printf("Dien tich hinh chu nhat la: %d", a * b);
		return 0;
	}
	else if (luachon == 3) {
		float r;
		printf("Nhap ban kinh hinh tron: ");
		scanf("%f", &r);
		printf("Dien tich hinh tron: %.3f", (float)(pi * r * r));
		return 0;
	}
	else if (luachon == 4) {
		float canhday, chieucao, dientich;
		printf("Nhap canh day: ");
		scanf("%f", &canhday);
		printf("Nhap chieu cao: ");
		scanf("%f", &chieucao);
		dientich =  (float)1/2*(canhday * chieucao);
		printf("Dien tich hinh tam giac la: %.3f", dientich);
		return 0;
	}
	else if(luachon ==5){
		float canhtren,canhduoi, chieucao, dientich;
		printf("Nhap canh tren: ");
		scanf("%f", &canhtren);
		printf("Nhap canh day: ");
		scanf("%f", &canhduoi);
		printf("Nhap chieu cao: ");
		scanf("%f", &chieucao);
		dientich = (float)chieucao*(canhtren + canhduoi)/2;
		printf("Dien tich hinh tam giac la: %.3f", dientich);
		return 0;
	}
	return 0;
}
