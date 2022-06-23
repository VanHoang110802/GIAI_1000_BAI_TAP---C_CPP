Cho hai số nguyên n,y. Hãy cho biết ngày thứ n của năm y là ngày nào. Biết rằng ngày mùng 1 tháng 1 tính là ngày thứ 1.(1 <= n <=365, 1900 <= y <= 2050)
input: 5 2016		-> ouput: 5 1
input: 34 2012		-> ouput: 3 2

#include <iostream>
using namespace std;
int main()
{
	int n, y;
	cin >> n >> y;
	if ((n >= 1 && n <= 365) && (y >= 1900 && y <= 2050))
	{
		int ngay = n, thang = 1, nam = y;
	check:
		if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12) {
			if (ngay > 31)
			{
				ngay -= 31;
				thang++;
				if (thang > 12)
				{
					thang -= 12;
					nam++;
				}
				goto check;
			}
		}
		else if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
			if (ngay > 30)
			{
				ngay -= 30;
				thang++;
				goto check;
			}
		}
		else if (thang == 2) {
			if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
			{
				if (ngay > 29)
				{
					ngay -= 29;
					thang++;
					goto check;
				}
			}
			else
			{
				if (ngay > 28)
				{
					ngay -= 28;
					thang++;
					goto check;
				}
			}
		}
		cout << ngay << " " << thang;
	}
	return 0;
}
