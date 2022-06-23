Nhập vào thông tin 1 ngày (ngày - tháng - năm). Kiểm tra ngày có hợp lệ hay không ? Nếu hợp lệ hãy tìm ra ngày
kế tiếp (ngày - tháng - năm) & ngày trước đó (ngày - tháng - năm).

#include <iostream>
using namespace std;

int main() {
	int ngay, thang, nam;
	cout << "nhap ngay: ";
	cin >> ngay;
	if (ngay < 0 || ngay > 31) {
		cout << "Nhap lai, ngay khong le!";
		return 0;
	}
	cout << "nhap thang: ";
	cin >> thang;
	if (thang < 0 || thang > 12) {
		cout << "Nhap lai, thang khong le!";
		return 0;
	}
	cout << "nhap nam: ";
	cin >> nam;
	if (nam < 0) {
		cout << "Nhap lai! Nam khong duoc am!";
		return 0;
	}

	cout << "\nNgay thang nam vua nhap la: " << ngay << "/" << thang << "/" << nam << endl;

	int ngaytruocdo, thangtruocdo, namtruocdo;
	int ngayketiep, thangketiep, namketiep;

	if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12) {
		if (ngay >= 2 && ngay <= 30) {
			ngayketiep = ngay + 1;
			thangketiep = thang;
			namketiep = nam;

			ngaytruocdo = ngay - 1;
			thangtruocdo = thang;
			namtruocdo = nam;
		}

		else if (ngay == 1) {
			ngayketiep = ngay + 1;
			thangketiep = thang;
			namketiep = nam;

			thangtruocdo = thang - 1;
			namtruocdo = nam;
			if (thangtruocdo == 1 || thangtruocdo == 3 || thang == 5 || thangtruocdo == 7 || thangtruocdo == 8 || thangtruocdo == 10 || thangtruocdo == 12) {
				ngaytruocdo = 31;
			}
			if (thangtruocdo == 4 || thangtruocdo == 6 || thangtruocdo == 9 || thangtruocdo == 11) {
				ngaytruocdo = 30;
			}

		}
	}
	else if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
		if (ngay >= 2 && ngay <= 29) {
			ngayketiep = ngay + 1;
			thangketiep = thang;
			namketiep = nam;

			ngaytruocdo = ngay - 1;
			thangtruocdo = thang;
			namtruocdo = nam;
		}
		else if (ngay == 1) {

			ngayketiep = ngay + 1;
			thangketiep = thang;
			namketiep = nam;

			namtruocdo = nam;
			thangtruocdo = thang - 1;
			if (thangtruocdo == 1 || thangtruocdo == 3 || thang == 5 || thangtruocdo == 7 || thangtruocdo == 8 || thangtruocdo == 10 || thangtruocdo == 12) {
				ngaytruocdo = 31;
			}
			if (thangtruocdo == 4 || thangtruocdo == 6 || thangtruocdo == 9 || thangtruocdo == 11) {
				ngaytruocdo = 30;
			}

		}
	}
	else {
		if (ngay == 1)
		{
			ngayketiep = 2;
			thangketiep = thang;
			namketiep = nam;

			ngaytruocdo = 31;
			thangtruocdo = 1;
			namtruocdo = nam;
		}

		// nhuận có tối đa 29
		if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
		{

			if (ngay >= 2 && ngay <= 28)
			{
				ngayketiep = ngay + 1;
				thangketiep = thang;
				namketiep = nam;

				ngaytruocdo = ngay - 1;
				thangtruocdo = thang;
				namtruocdo = nam;
			}
			else if (ngay == 29)
			{
				ngayketiep = 1;
				thangketiep = 3;
				namketiep = nam;

				ngaytruocdo = 28;
				thangtruocdo = thang;
				namtruocdo = nam;
			}


		}
		else // không nhuận tối đa 28
		{
			if (ngay >= 2 && ngay <= 27)
			{
				ngayketiep = ngay + 1;
				thangketiep = thang;
				namketiep = nam;

				ngaytruocdo = ngay - 1;
				thangtruocdo = thang;
				namtruocdo = nam;
			}
			else if (ngay == 28)
			{
				ngayketiep = 1;
				thangketiep = 3;
				namketiep = nam;

				ngaytruocdo = 27;
				thangtruocdo = thang;
				namtruocdo = nam;
			}
		}

	}

	cout << "\nNgay thang nam ke tiep la: " << ngayketiep << "/" << thangketiep << "/" << namketiep << endl;
	cout << "\nNgay thang nam truoc do la: " << ngaytruocdo << "/" << thangtruocdo << "/" << namtruocdo << endl;
	return 0;
}
