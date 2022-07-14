Viết chương trình nhập vào một ngày (ngày, tháng, năm). Tìm ngày kế ngày vừa nhập (ngày, tháng, năm).

#include <stdio.h>
#include <conio.h>
int main() {
hoang:
	int ngay, thang, nam;
	do{
		printf("nhap ngay: ");
		scanf("%d", &ngay);
		if (ngay < 1 || ngay > 31) {
			printf("Nhap lai, ngay khong hop le!\n");
		}
	} while(ngay <= 0 || ngay > 31);
	do{
		printf("nhap thang: ");
		scanf("%d", &thang);
		if (thang <= 0 || thang > 12) {
			printf("Nhap lai, thang khong hop le!\n");
		}
	}while(thang <= 0 || thang > 12);
	do{
		printf("nhap nam: ");
		scanf("%d", &nam);
		if (nam <= 0) {
			printf("Nhap lai! Nam khong duoc am !\n)";
		}
	}while(nam <= 0);
	printf("\nNgay thang nam vua nhap la: %d/%d/%d\n",ngay,thang,nam);
	int ngayketiep, thangketiep, namketiep;
	if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12) {
		if (ngay >= 2 && ngay <= 30) {
			ngayketiep = ngay + 1;
			thangketiep = thang;
			namketiep = nam;
		}

		else if (ngay == 1) {

			ngayketiep = ngay + 1;
			thangketiep = thang;
			namketiep = nam;
		}
	}
	else if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
		if (ngay >= 2 && ngay <= 29) {
			ngayketiep = ngay + 1;
			thangketiep = thang;
			namketiep = nam;
		}
		else if (ngay == 1) {

			ngayketiep = ngay + 1;
			thangketiep = thang;
			namketiep = nam;
		}
	}
	else {
		if (ngay == 1)
		{
			ngayketiep = 2;
			thangketiep = thang;
			namketiep = nam;
		}
		// nhuận có tối đa 29
		if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
		{
			if (ngay >= 2 && ngay <= 28)
			{
				ngayketiep = ngay + 1;
				thangketiep = thang;
				namketiep = nam;
			}
			else if (ngay == 29)
			{
				ngayketiep = 1;
				thangketiep = 3;
				namketiep = nam;
			}
		}
		else // không nhuận tối đa 28
		{
			if (ngay >= 2 && ngay <= 27)
			{
				ngayketiep = ngay + 1;
				thangketiep = thang;
				namketiep = nam;
			}
			else if (ngay == 28)
			{
				ngayketiep = 1;
				thangketiep = 3;
				namketiep = nam;
			}
		}
	}
	printf("\nNgay thang nam ke tiep la: %d/%d/%d", ngayketiep,thangketiep, namketiep);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
