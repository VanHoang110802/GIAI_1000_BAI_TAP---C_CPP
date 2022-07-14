Một điểm KARAOKE tính tiền khách hàng theo công thức sau:
• Mỗi giờ trong 3 giờ đầu tiên tính 30 000 đồng/giờ,
• Mỗi giờ tiếp theo có đơn giá giảm 30% so với đơn giá trong 3 giờ đầu tiên.
• Ngoài ra nếu thời gian thuê phòng từ 8 – 17 giờ thì được giảm giá 10%.
Viết chương trình nhập vào giờ bắt đầu, giờ kết thúc và in ra số tiền khách hàng 
phải trả biết
rằng 8 ≤ giờ bắt đầu < giờ kết thúc ≤ 24.

#include <iostream>
using namespace std;

#define giatiencuamoigiodautien 30000
#define sotientinhtheophut giatiencuamoigiodautien/60
#define giamgiachogiosudungtieptheo 0.7
#define giamgiachokhunggiovang 0.9
#define giomocua 8
#define giodongcua 24
#define giobatdaukhunggiovang 8
#define gioketthuckhunggiovang 17

int main() {
	int giovao, phutvao, giora, phutra, sogiodasudung, sophutdasudung;
	cout << "Nhap so gio da vao: ";
	cin >> giovao;
	if (giovao < giomocua || giovao > giodongcua) {
		cout << "Xin loi quy khach! Cua hang chung toi hoat dong tu 8h - 24h, xin vui long kiem tra lai thoi gian!";
		return 0;
	}
	cout << "Nhap so phut da vao: ";
	cin >> phutvao;
	if (phutvao < 0 || phutvao > 60) {
		cout << "Nhap phut khong hop le! Xin nhap lai!";
		return 0;
	}
	cout << "Nhap so gio da ra: ";
	cin >> giora;
	if (giora < giovao || giora > giodongcua ) {
		cout << "Nhap gio khong hop le! Xin nhap lai!";
		return 0;
	}
	cout << "Nhap so phut da ra: ";
	cin >> phutra;
	if (phutra > 60 || phutra < 0 || giora == giovao && phutra < phutvao) {
		cout << "Nhap phut khong hop le! Xin nhap lai!";
		return 0;
	}

	// ----------------------------- Tính số giờ đã sử dụng -----------------------------
	sogiodasudung = giora - giovao;
	sophutdasudung = phutra - phutvao;
	if (sophutdasudung < 0) {
		sogiodasudung--;
		sophutdasudung += 60;
	}


	// ----------------------------- Quy đổi ra tổng số phút -----------------------------
	int tongsophutdasudungall, sophutdavao, sophutdara;
	sophutdavao = giovao * 60;
	sophutdara = giora * 60;
	tongsophutdasudungall = sogiodasudung * 60 + sophutdasudung;

	cout << "So gio phut da su dung: " << sogiodasudung << ":" << sophutdasudung;
	cout << "\nSo phut da su dung la: " << tongsophutdasudungall;

	//----------------------------- Xử Lí -----------------------------

	int tinhtien, tinhtientruoc17gio, tinhtiensau17gio, tongsophuttruoc17gio, tongsophutsau17gio;

	if (tongsophutdasudungall < 180) { 
		if (sophutdavao < (gioketthuckhunggiovang *60)) {
			tinhtien = tongsophutdasudungall * (sotientinhtheophut * giamgiachokhunggiovang);
		}
		if (sophutdavao > (gioketthuckhunggiovang *60)) {
			tinhtien = tongsophutdasudungall * sotientinhtheophut;
			
		}
		if (sophutdavao < (gioketthuckhunggiovang * 60) && sophutdara > (gioketthuckhunggiovang * 60)) {
			tongsophuttruoc17gio = (gioketthuckhunggiovang * 60) - sophutdavao;
			tongsophutsau17gio = sophutdara - (gioketthuckhunggiovang * 60);
			tinhtientruoc17gio = tongsophuttruoc17gio * sotientinhtheophut * giamgiachokhunggiovang;
			tinhtiensau17gio = tongsophutsau17gio * sotientinhtheophut;
			tinhtien = tinhtientruoc17gio + tinhtiensau17gio;
			/*cout << "\nTong so phut da su dung truoc 17 gio: " << tongsophuttruoc17gio;
			cout << "\nTong so phut da su dung sau 17 gio: " << tongsophutsau17gio;
			cout << "\nSo tien truoc 17 gio la: " << tinhtientruoc17gio;
			cout << "\nSo tien sau 17 gio la: " << tinhtiensau17gio;*/
			
		}
	}

	if (tongsophutdasudungall >= 180) {
		if (sophutdavao < (gioketthuckhunggiovang*60)) {
			tinhtien = tongsophutdasudungall * ((sotientinhtheophut * giamgiachokhunggiovang) * giamgiachogiosudungtieptheo);
			
		}
		if (sophutdavao > (gioketthuckhunggiovang * 60)) {
			tinhtien = tongsophutdasudungall * (sotientinhtheophut *giamgiachogiosudungtieptheo);
		}
		if (sophutdavao < (gioketthuckhunggiovang * 60) && sophutdara >(gioketthuckhunggiovang * 60)) {
			tongsophuttruoc17gio = (gioketthuckhunggiovang * 60) - sophutdavao;
			tongsophutsau17gio = sophutdara - (gioketthuckhunggiovang * 60);
			tinhtientruoc17gio = tongsophuttruoc17gio * (sotientinhtheophut * giamgiachokhunggiovang * giamgiachogiosudungtieptheo);
			tinhtiensau17gio = tongsophutsau17gio * (sotientinhtheophut*giamgiachogiosudungtieptheo);
			tinhtien = tinhtientruoc17gio + tinhtiensau17gio;
			/*cout << "\nTong so phut da su dung truoc 17 gio: " << tongsophuttruoc17gio;
			cout << "\nTong so phut da su dung sau 17 gio: " << tongsophutsau17gio;
			cout << "\nSo tien truoc 17 gio la: " << tinhtientruoc17gio;
			cout << "\nSo tien sau 17 gio la: " << tinhtiensau17gio;*/
		}
	}
	cout << "\nSo tien khach phai tra tat ca la: " << tinhtien;
	return 0;
}
