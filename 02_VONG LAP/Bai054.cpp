Viết chương trình nhập vào 2 phân số và tính tổng, hiệu, tích, thương của chúng (kết quả xuất ra phải có dạng phân số và phải được rút gọn)

ps1: 1/2
ps2: 3/4

ps1 + ps2 = 5/4
ps1 - ps2 = -1/4
ps1 * ps2 = 3/8
ps1 / ps2 = 2/3

/*

Ý tuởng: để tính duợc tổng hiệu của 2 phân số, phải cùng mẫu số thì mới thực hiện đượcc. Nếu khác mẫu ta
phải quy đồng chúng lên, để cùng mẫu ta phải di tìm bội số chung của 2 số.

bội số chung nhỏ nhất của hai số nguyên a và b là số nguyên duong nhỏ nhất chia hết cho cả a và b.
Tức là nó có thể chia cho a và b mà không dư lại số du. Nếu a hoặc b là 0, thì không tồn tại số nguyên duong
chia hết cho a và b, khi dó quy uớc rằng LCM là 0

*/


/*
- Để tính được phân số khác mẫu trước hết ta cần rõ thuật toán tìm bội chung của 2 số.

//-----------thuật toán tìm bội số chung của 2 số ------------


5: 5, 10,15,20,25,30,35,40,45.....
8: 8,16,24,32,40,48,54.....


#include <stdio.h>
#include <conio.h>

int main(){
	int a, b;
	do{
		printf("Nhap a= ");
		scanf_s("%d", &a);
		if (a <= 0) {
			printf("a phai luon lon hon 0, xin hay kiem tra lai!\n");
		}
	} while (a <= 0);

	do {
		printf("Nhap b= ");
		scanf_s("%d", &b);
		if (b <= 0) {
			printf("b phai luon lon hon 0, xin hay kiem tra lai!\n");
		}

	} while (b <= 0);

	int min = a < b ? a : b;
	int max = a > b ? a : b;
	int ucln;

	if (max % min == 0) {	// mình chỉ xét min thôi còn max chắc chắn không chia hết được rồi.
		ucln = min;
	}
	else {
		for (int i = min / 2; i >= 1; i--) {
			if (max % i == 0 && min%i==0) {
				ucln = i;
				break;
			}
		}
	}
	printf("UCLN(%d,%d) = %d", a, b, ucln);

	int tich = a * b;
	float bcnn = (float)tich / ucln;
	printf("\nBSCNN = %d", (int)bcnn);

	return 0;
}

*/

#include <stdio.h>
#include <conio.h>

int main() {
	printf("\n\n\t\tCHUONG TRINH TINH 2 PHAN SO \n");
hoang:
	int tuso1, tuso2, mauso1, mauso2;
	do {
		printf("\nNhap tu so 1: ");
		scanf("%d", &tuso1);
		if (tuso1 <= 0) {
			printf("Xin vui long nhap lai tu so! tu so > 0\n");
		}
	} while (tuso1 < 0);
	
	do {
		printf("Nhap mau so1: ");
		scanf("%d", &mauso1);
		if (mauso1 <= 0) {
			printf("Gia tri nhap mau so khong hop le, mau phai lon hon 0 !\n");
		}
	} while (mauso1 <= 0);
	do {
		printf("Nhap tu so 2: ");
		scanf("%d", &tuso2);
		if ("Xin vui long nhap lai tu so! tu so > 0\n");
	} while (tuso2 <= 0);

	do {
		printf("Nhap mau so 2: ");
		scanf("%d", &mauso2);
		if (mauso2 <= 0) {
			printf("Gia tri nhap mau so khong hop le, mau phai lon hon 0 !\n");
		}
	} while (mauso2 <= 0);

	printf("\nPhan so thu nhat: %d / %d", tuso1, mauso1);
	printf("\nPhan so thu hai: %d / %d", tuso2, mauso2);

	// tính 2 phân s?
	int tongquydongtu1, tongquydongmau1, hieuquydongtu1, hieuquydongmau1, tichquydongtu1, tichquydongmau1, thuongquydongtu1, thuongquydongmau1, rutgontu1, rutgonmau1, rutgontu2, rutgonmau2, rutgontu3, rutgonmau3, rutgontu4, rutgonmau4;
	int maxtong, mintong, uclntong, maxhieu, minhieu, uclnhieu, maxtich, mintich, uclntich, maxthuong, minthuong, uclnthuong;
	// cùng m?u s?
	

	if (mauso1 == mauso2) {
		 // phép c?ng

		 tongquydongtu1 = tuso1 + tuso2;
		 tongquydongmau1 = mauso1;

		 // UCLN
		 mintong = tongquydongtu1 < tongquydongmau1 ? tongquydongtu1 : tongquydongmau1;
		 maxtong = tongquydongtu1 > tongquydongmau1 ? tongquydongtu1 : tongquydongmau1;
		
		 if (maxtong % mintong == 0) {		// mình ch? c?n xét min thôi, max ch?c ch?n không chia du?c r?i.
			 uclntong = mintong;
		 }
		 else {
			 for (int i = mintong / 2; i >= 1; i--) {
				 if (maxtong % i == 0 && mintong % i == 0) {
					 uclntong = i;
					 break;
				 }
			 }
		 }
		 rutgontu1 = tongquydongtu1 / uclntong;
		 rutgonmau1 = tongquydongmau1 / uclntong;
		 
		// phép tr?
		 hieuquydongtu1 = tuso1 - tuso2;
		 hieuquydongmau1 = mauso1;		// hai m?u d?u nhu nhau

		 if (hieuquydongtu1 < 0) {
			 hieuquydongmau1 *= -1;
			 hieuquydongtu1 *= -1;
		 }
		
		 // UCLN
		 minhieu = hieuquydongtu1 < hieuquydongmau1 ? hieuquydongtu1 : hieuquydongmau1;
		 maxhieu = hieuquydongtu1 > hieuquydongmau1 ? hieuquydongtu1 : hieuquydongmau1;

		 if (maxhieu % minhieu == 0) {	// mình ch? c?n xét min thôi, max ch?c ch?n không chia du?c r?i.
			 uclnhieu = minhieu;
		 }
		 else {
			 for (int i = minhieu / 2; i >= 1; i--) {
				 if (maxhieu % i == 0 && minhieu % i == 0) {
					 uclnhieu = i;
					 break;
				 }
			 }
		 }


		 rutgontu2 = hieuquydongtu1 / uclnhieu;
		 rutgonmau2 = hieuquydongmau1 / uclnhieu;

		// phép nhân 
		 tichquydongtu1 = tuso1 * tuso2;
		 tichquydongmau1 = mauso1 * mauso2;

		 // UCLN
		 mintich = tichquydongtu1 < tichquydongmau1 ? tichquydongtu1 : tichquydongmau1;
		 maxtich = tichquydongtu1 > tichquydongmau1 ? tichquydongtu1 : tichquydongmau1;

		 if (maxtich % mintich == 0) {	// mình ch? c?n xét min thôi, max ch?c ch?n không chia du?c r?i.
			 uclntich = mintich;
		 }
		 else {
			 for (int i = mintich / 2; i >= 1; i--) {
				 if (maxtich % i == 0 && mintich % i == 0) {
					 uclntich = i;
					 break;
				 }
			 }
		 }
		 rutgontu3 = tichquydongtu1 / uclntich;
		 rutgonmau3 = tichquydongmau1 / uclntich;

		// phép chia
		 thuongquydongtu1 = tuso1 * mauso2;
		 thuongquydongmau1 = tuso2 * mauso1;

		 // UCLN
		 minthuong = thuongquydongtu1 < thuongquydongmau1 ? thuongquydongtu1 : thuongquydongmau1;
		 maxthuong = thuongquydongtu1 > thuongquydongmau1 ? thuongquydongtu1 : thuongquydongmau1;

		 if (maxthuong % minthuong == 0) {	// mình ch? c?n xét min thôi, max ch?c ch?n không chia du?c r?i.
			 uclnthuong = minthuong;
		 }
		 else {
			 for (int i = minthuong / 2; i >= 1; i--) {
				 if (maxthuong % i == 0 && minthuong % i == 0) {
					 uclnthuong = i;
					 break;
				 }
			 }
		 }
		 rutgontu4 = thuongquydongtu1 / uclnthuong;
		 rutgonmau4 = thuongquydongmau1 / uclnthuong;


	}
	else {		// khác m?u
		// phep cong
		 tongquydongtu1 = (tuso1 * mauso2) + (tuso2 * mauso1);
		 tongquydongmau1 = mauso1 * mauso2;

		 // UCLN
		 mintong = tongquydongtu1 < tongquydongmau1 ? tongquydongtu1 : tongquydongmau1;
		 maxtong = tongquydongtu1 > tongquydongmau1 ? tongquydongtu1 : tongquydongmau1;

		 if (maxtong % mintong == 0) {	// mình ch? c?n xét min thôi, max ch?c ch?n không chia du?c r?i.
			 uclntong = mintong;
		 }
		 else {
			 for (int i = mintong / 2; i >= 1; i--) {
				 if (maxtong % i == 0 && mintong % i == 0) {
					 uclntong = i;
					 break;
				 }
			 }
		 }
		 rutgontu1 = tongquydongtu1 / uclntong;
		 rutgonmau1 = tongquydongmau1 / uclntong;


		// phep tru
		 hieuquydongtu1 = (tuso1 * mauso2) - (tuso2 * mauso1);
		 hieuquydongmau1 = mauso1 * mauso2;
		 
		 if ( hieuquydongmau1 < 0) {
			 hieuquydongtu1 *= -1;
			 hieuquydongmau1 *= -1;
			 
		 }

		 // UCLN
		 minhieu = hieuquydongtu1 < hieuquydongmau1 ? hieuquydongtu1 : hieuquydongmau1;
		 maxhieu = hieuquydongtu1 > hieuquydongmau1 ? hieuquydongtu1 : hieuquydongmau1;

		 if (maxhieu % minhieu == 0) {	// mình ch? c?n xét min thôi, max ch?c ch?n không chia du?c r?i.
			 uclnhieu = minhieu;
		 }
		 else {
			 for (int i = minhieu / 2; i >= 1; i--) {
				 if (maxhieu % i == 0 && minhieu % i == 0) {
					 uclnhieu = i;
					 break;
				 }
			 }
		 }


		 rutgontu2 = hieuquydongtu1 / uclnhieu;
		 rutgonmau2 = hieuquydongmau1 / uclnhieu;
		 

		// tich
		 tichquydongtu1 = tuso1 * tuso2;
		 tichquydongmau1 = mauso1 * mauso2;
		 
		// UCLN
		 mintich = tichquydongtu1 < tichquydongmau1 ? tichquydongtu1 : tichquydongmau1;
		 maxtich = tichquydongtu1 > tichquydongmau1 ? tichquydongtu1 : tichquydongmau1;

		 if (maxtich % mintich == 0) {	// mình ch? c?n xét min thôi, max ch?c ch?n không chia du?c r?i.
			 uclntich = mintich;
		 }
		 else {
			 for (int i = mintich / 2; i >= 1; i--) {
				 if (maxtich % i == 0 && mintich % i == 0) {
					 uclntich = i;
					 break;
				 }
			 }
		 }
		 rutgontu3 = tichquydongtu1 / uclntich;
		 rutgonmau3 = tichquydongmau1 / uclntich;

		// thuong
		 thuongquydongtu1 = tuso1 * mauso2;
		 thuongquydongmau1 = mauso1 * tuso2;

		 // UCLN
		 minthuong = thuongquydongtu1 < thuongquydongmau1 ? thuongquydongtu1 : thuongquydongmau1;
		 maxthuong = thuongquydongtu1 > thuongquydongmau1 ? thuongquydongtu1 : thuongquydongmau1;

		 if (maxthuong % minthuong == 0) {	// mình ch? c?n xét min thôi, max ch?c ch?n không chia du?c r?i.
			 uclnthuong = minthuong;
		 }
		 else {
			 for (int i = minthuong / 2; i >= 1; i--) {
				 if (maxthuong % i == 0 && minthuong % i == 0) {
					 uclnthuong = i;
					 break;
				 }
			 }
		 }
		 rutgontu4 = thuongquydongtu1 / uclnthuong;
		 rutgonmau4 = thuongquydongmau1 / uclnthuong;
		}
	printf("\nTong cua hai phan so la: %d/%d + %d/%d = %d/%d", tuso1, mauso1, tuso2, mauso2, rutgontu1, rutgonmau1);
	printf("\nHieu cua hai phan so la: %d/%d - %d/%d = %d/%d", tuso1, mauso1, tuso2, mauso2, rutgontu2, rutgonmau2);
	printf("\nTich cua hai phan so la: %d/%d * %d/%d = %d/%d", tuso1, mauso1, tuso2, mauso2, rutgontu3, rutgonmau3);
	printf("\nThuong cua hai phan so la: %d/%d / %d/%d = %d/%d", tuso1, mauso1, tuso2, mauso2, rutgontu4, rutgonmau4);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
	
}
