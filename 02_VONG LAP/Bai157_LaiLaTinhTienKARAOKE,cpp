/*
Viết chương trình thực hiện các công việc sau ( KHÔNG ĐƯỢC DÙNG HÀM CON)
Viết chương trình thực hiện việc tính tiền cho 1 nhà hàng karaoke với quy định sau:
- Từ thứ 2 tới thứ 6 giá hát 25.000
- Thứ 7 giá hát 1 giờ 35.000
- Chủ nhật giá hát 1 giờ 50.000
Từ thứ 2, sẽ giảm giá với quy tắc sau: sau 2 giờ sẽ giảm 1000đ(tính với giá ngày thường)
- Giờ thứ 3: tiền = 2 giờ đầu + 24000đ = 74000
- Giờ thứ 4: tiền = 3 giờ đầu + 24000đ = 98000
- Giờ thứ 5: tiền = 4 giờ đầu + 23000đ = 121000
- Giờ thứ 6: tiền = 5 giờ đầu + 23000đ = 145000
- Giờ thứ 7: tiền = 6 giờ đầu + 22000đ = 166000
- Giờ thứ 8: tiền = 7 giờ đầu + 22000đ = 188000
...
Yêu cầu :
	1.Nhập số nguyên t ( 2 <= t <=8) cho biết khách hàng đã sử dụng vào thứ mấy.Nếu nhập sai yêu cầu nhập lại.
	2.Nhập số nguyên x thể hiện số giờ mà khách đã sử dụng dịch vụ với 0 < x <= 24 (Không sử dụng quá 24 giờ),nếu nhập sai yêu cầu nhập lại.
	3.Cho biết số tiền khách phải trả.
	4.Nếu số tiên khách trả / 1000 là số chính phương chia hết cho 5 thì khách phải trả thêm 10% thuế, nếu không thì giảm cho khách 15%. Cho biết số tiên thực tế khách phải trả.

	
	-> Viết bằng ngôn ngữ C/C++.

*/

#include <stdio.h>
#include <conio.h>

int GiaHatTuThu2DenThu6 = 25000;
int sogioseduocgiamgia = 2;
int GiaHatTrongThu7 = 35000;
int GiaHatTrongChuNhat = 50000;

int main() {
hoang:
	int thu, sogiokhachdasudung;
	do {
		printf("Nhap thu: ");
		scanf("%d", &thu);
		if (thu < 2 || thu > 8) {
			printf("Thu nhap khong hop le, xin hay kiem tra lai!\n");
		}

	} while (thu < 2 || thu > 8);

	do {
		printf("Nhap so gio khach da su dung: ");
		scanf("%d", &sogiokhachdasudung);
		if (sogiokhachdasudung <= 0 || sogiokhachdasudung > 24) {
			printf("Gio khach su dung nhap khong hop le, xin hay kiem tra lai!\n");
		}
	} while (sogiokhachdasudung <= 0 || sogiokhachdasudung > 24);
	if (thu >= 2 && thu <= 7) {
		printf("\nHom nay la thu %d, khach da su dung het %d gio!", thu, sogiokhachdasudung);
	}
	else {
		printf("\nHom nay la chu nhat, khach da su dung het %d gio!", sogiokhachdasudung);
	}

	int giatien;
	int tong = 0;
	int giatien2giodau = GiaHatTuThu2DenThu6 * sogioseduocgiamgia;
	int giatien2giodau1 = GiaHatTrongThu7 * sogioseduocgiamgia;
	int giatien2giodau2 = GiaHatTrongChuNhat * sogioseduocgiamgia;
	int giosaukhigiam = sogiokhachdasudung - sogioseduocgiamgia;

	if (thu >= 2 && thu <= 6) {
		if (sogiokhachdasudung == 1) {
			giatien = GiaHatTuThu2DenThu6;
			printf("\nGia tien: %d", giatien);
			return 0;
		}
		int temp = GiaHatTuThu2DenThu6;
		for (int i = 1; i <= giosaukhigiam; i++) {
			if (i % 2 != 0) {
				temp -= 1000;
			}
			// printf("\n %d ", temp);
			tong += temp;
			//  printf("\n%d ",i);
		}
		//printf("\n%d",tong);
		giatien = tong + giatien2giodau;
		printf("\nGia tien: %d", giatien);
	}
	else if (thu == 7) {
		if (sogiokhachdasudung == 1) {
			giatien = GiaHatTrongThu7;
			printf("\nGia tien: %d", giatien);
			return 0;
		}
		int temp = GiaHatTrongThu7;
		for (int i = 1; i <= giosaukhigiam; i++) {
			if (i % 2 != 0) {
				temp -= 1000;
			}
			tong += temp;
		}
		giatien = tong + giatien2giodau1;
		printf("\nGia tien: %d", giatien);
	}
	else {
		if (sogiokhachdasudung == 1) {
			giatien = GiaHatTrongChuNhat;
			printf("\nGia tien: %d", giatien);
			return 0;
		}
		int temp = GiaHatTrongChuNhat;
		for (int i = 1; i <= giosaukhigiam; i++) {
			if (i % 2 != 0) {
				temp -= 1000;
			}
			tong += temp;
		}
		giatien = tong + giatien2giodau2;
		printf("\nGia tien: %d", giatien);
	}
	printf("\nBan co muon di tinh tiep khong \n(Nhan phim c de tiep tuc, khong thi an phim bat ki de thoat)\n");
	char lc = getch();
	if (lc == 'c' || lc == 'C') {
		goto hoang;
	}
	return 0;
}
