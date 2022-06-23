Viết chương trình tính lương của nhân viên dựa theo thâm niên công tác (TNCT) như sau:
Lương = hệ số * lương căn bản, trong đó lương căn bản là 650000 đồng.
• Nếu TNCT < 12 tháng: hệ số = 1.92
• Nếu 12 <= TNCT < 36 tháng: hệ số = 2.34
• Nếu 36 <= TNCT < 60 tháng: hệ số = 3
• Nếu TNCT >= 60 tháng: hệ số = 4.5

#include <iostream>
using namespace std;
#define luongcanban 650000
int main() {
	int tnct;
	float heso;
	cout << "Nhap so tham nien cong tac : ";
	cin >> tnct;
	if (tnct <= 0) {
		cout << "So tham nien cong tac khong hop le, vui long nhap lai!";
		return 0;
	}
	if (tnct < 12) {
		heso = 1.92;
	} 
	if (tnct >= 12 && tnct < 36) {
		heso = 2.34;
	}
	if (tnct >= 36 && tnct < 60) {
		heso = 3.0;
	}
	if (tnct >= 60) {
		heso = 4.5;
	}
	int luong;
	luong = heso * luongcanban;
	cout << "Luong cua nhan vien: " << luong;
	return 0;
}
