/*
Nhập vào 1 số nguyên dương, sau đó sắp xếp các chữ số ở trong số nguyên dương đó tăng dần. Kết quả là 
được 1 số nguyên dương mới.

vd: Nhập vào 31685127
=> Số mới sẽ là: 11235678

Yêu cầu: Không dùng mảng, chỉ dùng các kiến thức về if else, vòng lặp & hàm.
*/

/* 
Ý TƯỞNG: 
Tách các chữ số trong số ban đầu ra. Tìm Min trong các chữ số đó.
Sau khi tìm được Min ta đề phòng có nhiều biến Min giống nhau cho nên ta đặt 1 biến đếm để duyệt hết Min.
Sau đó bắt đầu tìm sang Biến MIn tiếp theo nhưng thỏa là phải lớn hơn biến Min ban đầu.
Cứ thế nhân biến Min tìm được lần lượt cho 10^(Số lượng chữ số - 1) và cộng dồn lại.

Điều kiện dừng sẽ là khi biến Min tìm được nó chính là chữ số lớn nhất của số ban đầu.

31685127

Đầu tiên ra được Min = 1
Sau đó lấy 1 * 10^7 lưu vào S

Sau đó đếm xem số 1 vừa tìm được có mấy số 1 ? 
=> đếm ra đc có 2 số 1.
=> mình còn thiếu 1 số 1 chưa làm.
S += 1 * 10^6

Tiếp tục tìm 1 biến Min tiếp theo nhưng phải lớn hơn biến Min ban đầu.
=> Min = 2
S += 2 * 10^5

Đếm xem có tồn tại bao nhiêu chữ số 2 ?
=> chỉ có 1 (chính là số ban đầu).

Tiếp tục tìm 1 biến Min tiếp theo nhưng phải lớn hơn biến Min vừa tìm được.
=> Min = 3
S += 3 * 10^4

Đếm xem có tồn tại bao nhiêu chữ số 3 ?
=> chỉ số 1 chữ số (chính là số ban đầu).

Tiếp tục tìm biến Min tiếp theo ... và cứ thế cộng dồn lại sẽ ra kết quả.
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

// Hàm trả về số lượng chữ số đang có của số x.
int DemSoLuongChuSo(int x)
{
	int dem = 0;
	while(x != 0)
	{
		x /= 10; // Loại bỏ đi chữ số cuối.
		dem++; // Tăng biến đếm lên.
	}
	return dem; // Trả về số lượng chữ số.
}

// Hàm tìm chữ số Max của số ban đầu.
int ChuSoMax(int x)
{
	int Max = 0;
	while(x != 0)
	{
		int chuso = x % 10;
		x /= 10;
		if(chuso > Max)
		{
			Max = chuso;
		}
	}
	return Max;
}

// Hàm này trả về số sau khi đã được sắp xếp tăng dần các chữ số.
int XuLyDuLieu(int x)
{
	int Sum = 0;
	int dem = DemSoLuongChuSo(x);
	int dem1 = dem;

	int chusomax = ChuSoMax(x);
	// Lặp dem lần.

	int Min1 = -1;
	while(true)
	{
		int Min = 10;
		int Temp = x;
		while(Temp != 0)
		{
			int chuso = Temp % 10;
			Temp /= 10;

			if(chuso < Min && chuso > Min1)
			{
				Min = chuso;
			}
		}
		
		Sum += Min * pow(10.0, dem1 - 1);
		dem1--;

		Temp = x;
		// Kiểm tra tiếp xem có bao nhiêu chữ số trùng với Min.
		int dem2 = 0;
		while(Temp != 0)
		{
			int chuso = Temp % 10;
			Temp /= 10;

			if(chuso == Min)
			{
				dem2++;			
			}
		}
		for(int i = 2; i <= dem2; i++)
		{
			Sum += Min * pow(10.0, dem1 - 1);
			dem1--;
		}
		Min1 = Min;

		if(Min1 == chusomax)
		{
			break; // Điều kiện dừng.
		}
	}
	return Sum;
}

int main(int argc, char **argv)
{
	int n = 46423891;
	int KetQua = XuLyDuLieu(n);
	printf("\nKet qua la: %d", KetQua);
	return 0;
}
