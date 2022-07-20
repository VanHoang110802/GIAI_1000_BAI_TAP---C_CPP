/*
Con trỏ chỉ vị trên file
fseek(<tên biến con trỏ file>, <Độ dịch tính theo byte>, <Vị trí bắt đầu tính>);
trong đó:
<Độ dịch tính theo byte>:
- Nếu là số dương thì là dịch chuyển lên
- Nếu là số âm thì dịch chuyển xuống
- Nếu là số 0 thì không dịch
<Vị trí bắt đầu tính>:
- Nếu muốn bắt đầu từ đàu file, ta để là SEEK_SET hoặc 0.
- Nếu muốn bắt đầu 1 vị trí hiện tại con trỏ đang đứng, ta để là SEEK_CUR hoặc 1.
- Nếu muốn bắt đầu từ cuối file, ta để là SEEK_END hoặc 2.

Lưu ý: Nếu phạm vi byte dịch chuyển bị rơi vào 1 vùng không hợp lệ thì chương trình sẽ văng lỗi.

Ví dụ: Cho cấu trúc file input chứa thông tin 2 phân số. Yêu cầu đọc thông tin 2 phân số và tính các tính toán cần thiết
cho 2 phân số đó.
input:	1/2
		3/4
*/
#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
struct PhanSo
{
	int tuso, mauso;
};
typedef struct PhanSo phanso;

void DocFile(FILE *&FileIn, phanso &a, phanso &b)
{
	FileIn = fopen("input.txt", "r");
	if (!FileIn)
	{
		printf("\nKhong tim thay file de doc!\n");
		exit(0);
	}

	// xử lí đọc
	fscanf(FileIn, "%d", &a.tuso);
	// tuy nhiên lại có kí tự '/', vậy nên ta sẽ dùng dịch con trỏ chỉ vị
	fseek(FileIn, 1, SEEK_CUR);
	fscanf(FileIn, "%d", &a.mauso);
	fscanf(FileIn, "%d", &b.tuso);
	fseek(FileIn, 1, SEEK_CUR);
	fscanf(FileIn, "%d", &b.mauso);
	// làm gì thì làm, đã mở file thì cứ phải đóng lại đi đã
	fclose(FileIn);
}
int gcd(int a, int b)
{
	if (a < 0) a *= -1;
	if (b < 0) b *= -1;
	while (a != b)
	{
		if (a > b) a -= b;
		else b -= a;
	}
	return a;
}
phanso RutGonPS(phanso& x)
{
	int ucln = gcd(x.tuso, x.mauso);
	x.tuso /= ucln;
	x.mauso /= ucln;
	return x;
}
phanso operator + (phanso ps1, phanso ps2)
{
	phanso Tong;
	Tong.tuso = ps1.tuso * ps2.mauso + ps1.mauso * ps2.tuso;
	Tong.mauso = ps1.mauso * ps2.mauso;
	return RutGonPS(Tong);
}
phanso operator - (phanso ps1, phanso ps2)
{
	phanso Hieu;
	Hieu.tuso = ps1.tuso * ps2.mauso - ps1.mauso * ps2.tuso;
	Hieu.mauso = ps1.mauso * ps2.mauso;
	return RutGonPS(Hieu);
}
phanso operator * (phanso ps1, phanso ps2)
{
	phanso Tich;
	Tich.tuso = ps1.tuso * ps2.tuso;
	Tich.mauso = ps1.mauso * ps2.mauso;
	return RutGonPS(Tich);
}
phanso operator / (phanso ps1, phanso ps2)
{
	phanso NghichDaoLai, ketqua;
	NghichDaoLai.tuso =  ps2.mauso;
	NghichDaoLai.mauso = ps2.tuso;
	ketqua = ps1 * NghichDaoLai;
	return RutGonPS(ketqua);
}

void GhiFile(FILE* &FileOut, phanso ps1, phanso ps2)
{
	FileOut = fopen("output.txt", "w");
	phanso tong, hieu, tich, thuong;
	tong = ps1 + ps2;
	hieu = ps1 - ps2;
	tich = ps1 * ps2;
	thuong = ps1 / ps2;
	fprintf(FileOut, "Tong: %d/%d\n",tong.tuso, tong.mauso );
	fprintf(FileOut, "Hieu: %d/%d\n", hieu.tuso, hieu.mauso);
	fprintf(FileOut, "Tich: %d/%d\n", tich.tuso, tich.mauso);
	fprintf(FileOut, "Thuong: %d/%d\n", thuong.tuso, thuong.mauso);

	fclose(FileOut);
}
int main()
{
	phanso ps1, ps2;
	FILE* FileIn, *FileOut;
	DocFile(FileIn, ps1, ps2);
	GhiFile(FileOut, ps1, ps2);
	return 0;
}
