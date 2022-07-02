/*
- Animals Race là cuộc đua thường niên diễn ra vào mùa xuân tại khu làng Ankoslus của các con vật sinh sống.
Cuộc đua Animals Race 2015 năm nay sẽ có 3 loại con vật tham dự với thông tin cơ bản của một con vật bao gồm:
• m_Code (Mã số): Kiểu chuỗi.
• m_Speed (Tốc độ): Kiểu số nguyên. (số km/h)
• m_Equiment (Trang bị): Kiểu số nguyên. (1 là có trang bị, 0 là không có trang bị)
- Đường đua năm nay dài 210 km từ Thung Lũng Busa xinh đẹp đi đến Thảo Nguyên Hasga mộng mơ được bắt đầu lúc: 
7 giờ sáng và kết thúc lúc 12 giờ trưa. Những con vật nào tới đích sau 12 giờ sẽ bị cho là bỏ cuộc.
- Mỗi loại con vật đều quy định riêng như sau:
• Lion (Sư tử): Khởi hành lúc 9 giờ. Nếu sư tử có trang bị thêm “móng sắt” tốc độ sẽ được tăng lên gấp đôi.
• Rabbit (Thỏ): Khởi hành sớm lúc 8 giờ. Nếu thỏ có trang bị thêm “tai thông minh” tốc độ sẽ tăng thêm 30 km/h.
• Tortoise (Rùa): Được ưu tiên khởi hành lúc 7 giờ và được ưu tiên bắt đầu đi từ Khu vườn Taka cách Thung Lũng Busa 75 km.
Nếu rùa có trang bị thêm “mai vàng” tốc độ sẽ tăng gấp 5 lần.
- Viết chương trình nhập từ file vào danh sách các con vật tham gia cuộc đua và tìm ra danh sách các con vật về đích:
• Dòng đầu tiên là 1 số n (1 <= n <= 10.000) là số lượng con vật tham gia cuộc đua (mỗi loại con vật có thể tham gia nhiều con), 
các dòng nhập tiếp theo lần lượt là thông tin nhập của từng con vật trên mỗi dòng.
• Thông tin xuất chứa những con vật chạy được hết đoạn đường trên và xếp hạng từ cao đến thấp (dựa theo con nào về đích sớm 
nhất sẽ xếp cao nhất). Những con vật không hoàn thành đường đua sẽ không nằm trong danh sách này. Nếu 2 con vật tới đích cùng
một lúc thì sẽ xếp hạng theo Alphabet của mã số.
Áp dụng struct để giải quyết những việc sau:
- Xây dựng trò chơi có các chức năng sau:
a. Xây dựng các struct và đọc thông tin các con vật từ file theo mẫu nhập bên dưới:
	6
	L001 50 1
	R001 70 0
	T001 10 1
	T002 15 0
	T003 20 1
	R003 35 0
b. Viết các hàm xử lý tìm ra những con vật về đích và sắp xếp chúng. Vd: xử lý của các con vật trên thì kết quả sẽ là:
	4
	1.	T003 20 1
	2.	T001 10 1
	3.	R001 70 0
	4.	L001 50 1
Lưu ý:
- Các hàm phải được chú thích rõ ràng.
- Phải dùng con trỏ hoặc vector
*/
#include <iostream>
#include <fstream> 
#include <string> 
#include <vector>
using namespace std;
#define SUTU_THOIGIANBATDAU 9
#define THO_THOIGIANBATDAU 8
#define RUA_THOIGIANBATDAU 7

#define SUTU_QUANGDUONGCHAY 210
#define THO_QUANGDUONGCHAY 210
#define RUA_QUANGDUONGCHAY 135

// Thông tin 1 con vật
struct ConVat
{
	string MaSo;
	int TocDo, TrangBi;
};
typedef struct ConVat CONVAT;

void NhapConVat(ifstream& FileIn, CONVAT& cv)
{
	FileIn >> cv.MaSo >> cv.TocDo >> cv.TrangBi;
}

void XuatConVat(ofstream& FileOut, CONVAT cv)
{
	FileOut << cv.MaSo << " " << cv.TocDo << " " << cv.TrangBi;
}

void NhapDanhSach(ifstream& FileIn, vector<CONVAT>& DanhSach)
{
	int n;
	FileIn >> n;

	for (int i = 1; i <= n; i++)
	{
		CONVAT cv;
		NhapConVat(FileIn, cv);

		DanhSach.push_back(cv);
	}
}

void XuatDanhSach(ofstream& FileOut, vector<CONVAT> DanhSach)
{
	int n = DanhSach.size();

	for (int i = 0; i < n; i++)
	{
		XuatConVat(FileOut, DanhSach[i]);
		FileOut << endl;
	}
}

int TimVanTocThucSu(CONVAT cv)
{
	if (cv.TrangBi == 0)
	{
		return cv.TocDo;
	}
	else
	{
		if (cv.MaSo[0] == 'L')
		{
			return cv.TocDo * 2;
		}
		else if (cv.MaSo[0] == 'R')
		{
			return cv.TocDo + 30;
		}
		else if (cv.MaSo[0] == 'T')
		{
			return cv.TocDo * 5;
		}
	}
}

double TimThoiGianDiHetQuangDuong(CONVAT cv)
{
	int tocdothucsu = TimVanTocThucSu(cv);

	if (cv.MaSo[0] == 'L')
	{
		return (double)SUTU_QUANGDUONGCHAY / tocdothucsu;
	}
	else if (cv.MaSo[0] == 'T')
	{
		return (double)RUA_QUANGDUONGCHAY / tocdothucsu;
	}
	else if (cv.MaSo[0] == 'R')
	{
		return (double)THO_QUANGDUONGCHAY / tocdothucsu;
	}
}

double TimThoiGianVeDich(CONVAT cv)
{
	double ThoiGianChay = TimThoiGianDiHetQuangDuong(cv);

	if (cv.MaSo[0] == 'L')
	{
		return SUTU_THOIGIANBATDAU + ThoiGianChay;
	}
	else if (cv.MaSo[0] == 'T')
	{
		return RUA_THOIGIANBATDAU + ThoiGianChay;
	}
	else if (cv.MaSo[0] == 'R')
	{
		return THO_THOIGIANBATDAU + ThoiGianChay;
	}
}

void HoanVi(CONVAT& a, CONVAT& b)
{
	CONVAT Temp = a;
	a = b;
	b = Temp;
}

void SapXepDanhSach(vector<CONVAT>& DanhSach)
{
	int n = DanhSach.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double ThoiGianVeDich_1 = TimThoiGianVeDich(DanhSach[i]);
			double ThoiGianVeDich_2 = TimThoiGianVeDich(DanhSach[j]);


			if (ThoiGianVeDich_1 > ThoiGianVeDich_2)
			{
				HoanVi(DanhSach[i], DanhSach[j]);
			}

		}
	}
}

int main()
{
	ifstream FileIn("INPUT.TXT");

	if (!FileIn)
	{
		cout << "\nKhong tim thay tap tin INPUT.TXT";
		return 0;
	}

	vector<CONVAT> DanhSach;
	NhapDanhSach(FileIn, DanhSach);

	FileIn.close(); // đóng lại.

	ofstream FileOut("OUTPUT.TXT");

	// Sap xep tang dan
	SapXepDanhSach(DanhSach);

	int dem = 0;
	int n = DanhSach.size();
	FileOut << "f" << endl;
	for (int i = 0; i < n; i++)
	{
		if (TimThoiGianVeDich(DanhSach[i]) <= 12)
		{
			FileOut << i + 1 << ". ";
			XuatConVat(FileOut, DanhSach[i]);
			FileOut << endl;
			dem++;
		}
	}

	FileOut.seekp(0, SEEK_SET);
	FileOut << dem << endl;

	FileOut.close();

	return 0;
}
