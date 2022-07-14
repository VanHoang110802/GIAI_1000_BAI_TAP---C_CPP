Viết chương trình nhập vào một ngày (ngày, tháng, năm). Tìm ngày trước ngày vừa nhập (ngày, tháng, năm).

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
	int ngaytruocdo, thangtruocdo, namtruocdo;
	if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12) {
		if (ngay >= 2 && ngay <= 30) {
			ngaytruocdo = ngay - 1;
			thangtruocdo = thang;
			namtruocdo = nam;
		}
		else if (ngay == 1) {
			namtruocdo = nam - 1;
			thangtruocdo = thang - 1;
			if(thangtruocdo == 0){
				ngaytruocdo =31;
				thangtruocdo = 12;
			}
			else if(thangtruocdo == 3){
				if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0){
					thangtruocdo =2;
					ngaytruocdo = 29;
				} else {
					thangtruocdo =2;
					ngaytruocdo = 28;
				}
			}
			else if ( thangtruocdo == 1 || thang == 5 || thangtruocdo == 7 || thangtruocdo == 8 || thangtruocdo == 10 || thangtruocdo == 12) {
				ngaytruocdo = 31;
			}
			else if (thangtruocdo == 4 || thangtruocdo == 6 || thangtruocdo == 9 || thangtruocdo == 11) {
				ngaytruocdo = 30;
			}
		}
	}
	else if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
		if (ngay >= 2 && ngay <= 29) {
			ngaytruocdo = ngay - 1;
			thangtruocdo = thang;
			namtruocdo = nam;
		}
		else if (ngay == 1) {
			namtruocdo = nam - 1;
			thangtruocdo = thang - 1;
			
			if (thangtruocdo == 1  ||thang == 3 || thang == 5 || thangtruocdo == 7 || thangtruocdo == 8 || thangtruocdo == 10 || thangtruocdo == 12) {
				ngaytruocdo = 31;
			}
			else if (thangtruocdo == 4 || thangtruocdo == 6 || thangtruocdo == 9 || thangtruocdo == 11) {
				ngaytruocdo = 30;
			}
		}
	}
	else {
		if (ngay == 1)
		{
			ngaytruocdo = 31;
			thangtruocdo = 1;
			namtruocdo = nam;
		}
		// nhuận có tối da 29
		if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
		{
			if (ngay >= 2 && ngay <= 28)
			{
				ngaytruocdo = ngay - 1;
				thangtruocdo = thang;
				namtruocdo = nam;
			}
			else if (ngay == 29)
			{
				ngaytruocdo = 28;
				thangtruocdo = thang;
				namtruocdo = nam;
			}
		}
		else // không nhuận tối đa 28
		{
			if (ngay >= 2 && ngay <= 27)
			{
				ngaytruocdo = ngay - 1;
				thangtruocdo = thang;
				namtruocdo = nam;
			}
			else if (ngay == 28)
			{
				ngaytruocdo = 27;
				thangtruocdo = thang;
				namtruocdo = nam;
			}
		}
	}
	printf("\nNgay thang nam truoc do la: %d/%d/%d",ngaytruocdo,thangtruocdo,namtruocdo);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
