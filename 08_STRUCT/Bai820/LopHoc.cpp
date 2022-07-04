#include "LopHoc.h"
#define SOTIENMOTCHI 120000
#define KHA 2500000
#define GIOI 3000000
#define XUATSAC 3500000

void NhapLopHoc(LOPHOC& lh)
{
	do {
		cout << "\nNhap vao so luong sinh vien trong lop hoc: ";
		cin >> lh.n;

		if (lh.n < 0)
		{
			cout << "\nSo luong khong hop le. Xin kiem tra lai !\n";
		}
	} while (lh.n < 0);

	// cấp phát bộ nhớ cho con trỏ
	
	lh.arr = new SINHVIEN[lh.n];

	getchar(); // Xóa bộ nhớ đệm.
	for (int i = 0; i < lh.n; i++)
	{
		cout << "\n------- Nhap Sinh Vien Thu " << i + 1 << " ------";
		
		int Check; // chưa bị trùng
		do {
			Check = 0; // reset.

			cout << "\nNhap vao ma so: ";
			
			getline(cin, lh.arr[i].MaSo);
			// Kiểm tra xem mã số của sinh viên sau có bị trùng với mã số của các sinh viên trước đó hay không ?
			for (int j = i - 1; j >= 0; j--)
			{
				if (strcmp((char*)lh.arr[i].MaSo.c_str(), (char*)lh.arr[j].MaSo.c_str()) == 0)
				{
					Check = 1; // Cap nhat bi trung
					break; // thoat ra luon
				}
			}

			if (Check == 1)
			{
				cout << "\nMa so sinh vien nay da ton tai. Xin hay nhap lai ma so moi\n";
			}
		} while (Check == 1);

		// Nhập tiếp các thông tin còn thiếu.
		NhapSinhVien(lh.arr[i]);
	}
}

void XuatLopHoc(LOPHOC lh)
{
	for (int i = 0; i < lh.n; i++)
	{
		cout << "\n\n-------------------------------------------------------------";
		cout << "\n\t\t Thong Tin Sinh Vien Thu " << i + 1;
		XuatSinhVien(lh.arr[i]);
	}
}

void HoanVi(SINHVIEN& a, SINHVIEN& b)
{
	SINHVIEN Temp = a;
	a = b;
	b = Temp;
}

void SapXepLopHoc(LOPHOC& lh, char phanloai)
{
	for (int i = 0; i < lh.n - 1; i++)
	{
		for (int j = i + 1; j < lh.n; j++)
		{
			if (phanloai == 't')
			{
				if (TinhDiemTrungBinh(lh.arr[i]) > TinhDiemTrungBinh(lh.arr[j]))
				{
					HoanVi(lh.arr[i], lh.arr[j]);
				}
			}
			else if (phanloai == 'g')
			{
				if (TinhDiemTrungBinh(lh.arr[i]) < TinhDiemTrungBinh(lh.arr[j]))
				{
					HoanVi(lh.arr[i], lh.arr[j]);
				}
			}

		}
	}
}

int DemSoLuongHocBong(LOPHOC lh)
{
	int dem_1 = 0;
	
	for (int i = 0; i < lh.n; i++)
	{
		if (strcmp((char*)XepLoai(lh.arr[i]).c_str(), "KHA") == 0 ||
			strcmp((char*)XepLoai(lh.arr[i]).c_str(), "GIOI") == 0 ||
			strcmp((char*)XepLoai(lh.arr[i]).c_str(), "XUAT SAC") == 0)
		{
			dem_1++;
		}
	}
	return dem_1;
}

void XuLyHocLai(LOPHOC lh, int& dem, float& tien)
{
	tien = 0; // khởi tạo tiền = 0
	dem = 0;

	// duyệt vào từng sinh viên trong lớp học.
	for (int i = 0; i < lh.n; i++)
	{
		int Check = 0;

		// duyệt vào từng môn học của sinh viên thứ i trong danh sách lớp.
		for (int j = 0; j < lh.arr[i].danhsachmon.n; j++)
		{
			if (lh.arr[i].danhsachmon.arr[j].SoDiem < 5)
			{
				Check = 1;


				// cộng dồn tiền học lại của môn đó.
				tien += lh.arr[i].danhsachmon.arr[j].SoChi * SOTIENMOTCHI;
			}

		}
		if (Check == 1)
		{
			dem++;
		}
	}
}

SINHVIEN* TimKiemThongTin(LOPHOC lh, string MaTimKiem)
{
	for (int i = 0; i < lh.n; i++)
	{
		if (strcmp((char*)lh.arr[i].MaSo.c_str(), (char*)MaTimKiem.c_str()) == 0)
		{
			return &lh.arr[i];
		}
	}
	return NULL;
}

template <typename vanhoang>
// vừa để gia tăng, vừa giảm bớt ô nhớ.
void REALLOC(vanhoang*& a, int OldSize, int NewSize)
{
	// Bước 1: Tạo ra 1 mảng mới là bản sao của mảng cũ rồi đổ dữ liệu từ mảng cũ sang.
	vanhoang* tam = new vanhoang[OldSize];

	for (int i = 0; i < OldSize; i++)
	{
		tam[i] = a[i];
	}

	// Bước 2: Xóa mảng cũ đi và cấp mới lại.
	delete[] a;
	a = new vanhoang[NewSize];

	// Bước 3: Đổ dữ liệu từ mảng tạm sang mảng mới.
	int Min = OldSize < NewSize ? OldSize : NewSize;

	for (int i = 0; i < Min; i++)
	{
		a[i] = tam[i];
	}

	// Bước 4: Xóa mảng tạm đi.
	delete[] tam;
}

// Xóa 1 sinh viên.
void XoaSinhVien(LOPHOC& lh, int vitrixoa)
{
	for (int i = vitrixoa + 1; i < lh.n; i++)
	{
		//a[i - 1] = a[i];
		lh.arr[i - 1] = lh.arr[i];
	}
	lh.n--;

	// để cập nhật bộ nhớ.
	REALLOC(lh.arr, lh.n + 1, lh.n);
}

// Xóa sinh viên dựa trên mã số.
void XoaSinhVienDuaTrenMaSo(LOPHOC& lh, string MaSo)
{
	// duyệt danh sách để tìm ra mã số
	for (int i = 0; i < lh.n; i++)
	{
		if (strcmp((char*)lh.arr[i].MaSo.c_str(), (char*)MaSo.c_str()) == 0)
		{
			XoaSinhVien(lh, i);
			break; // thoát ra khỏi vòng lặp ngay khi vừa xóa xong 1 thằng bởi vì mã số sinh viên sẽ không có chuyện bị trùng.
		}
	}
}

// Xóa tất cả sinh viên bị rớt môn trong danh sách.
void XoaTatCaSinhVienRotMon(LOPHOC& lh)
{
	// duyệt qua danh sách sinh viên.
	for (int i = 0; i < lh.n; i++)
	{
		// thấy thằng nào bị rớt môn => xóa
		if (KiemTraBiRotMon(lh.arr[i]) == 1)
		{
			XoaSinhVien(lh, i);
			i--;
		}
	}
}

// cập nhật sinh viên dựa trên mã số
void CapNhatDuaTrenMaSo(LOPHOC& lh, string MaSo)
{
	// duyệt qua danh sách các sinh viên đang có trong lớp.
	for (int i = 0; i < lh.n; i++)
	{
		// tìm thấy sinh viên có mã số cần cập nhật.
		if (strcmp((char*)lh.arr[i].MaSo.c_str(), (char*)MaSo.c_str()) == 0)
		{
			getchar();
			cout << "\nNhap lai ten: ";
			getline(cin,lh.arr[i].Ten);

			cout << "\nNhap lai danh sach mon hoc: ";
			NhapDanhSachMon(lh.arr[i].danhsachmon);

			break; // Bởi vì mã số chỉ có 1 thôi.
		}
	}
}

/*
ý tưởng 1:
B1: Duyệt qua danh sách các sinh viên trong lớp
B2: Xét vào từng sinh viên, tính ra điểm trung bình
B3: Sau đó dựa vào điểm trung bình để quy ra thuộc loại gì từ đó cộng tiền học bổng.
*/

float TongTienHocBong(LOPHOC lh)
{
	float Tong = 0;

	// B1
	for (int i = 0; i < lh.n; i++)
	{
		// B2
		float Dtb = TinhDiemTrungBinh(lh.arr[i]);

		// B3
		if (Dtb >= 7 && Dtb < 8)
		{
			// khá
			Tong += KHA;
		}
		else if (Dtb >= 8 && Dtb < 9)
		{
			Tong += GIOI;
		}
		else if (Dtb > 9)
		{
			Tong += XUATSAC;
		}
	}
	return Tong;
}

void SapXepTen(LOPHOC& lh, char phanloai)
{
	for (int i = 0; i < lh.n - 1; i++)
	{
		for (int j = i + 1; j < lh.n; j++)
		{
			if (phanloai == 't')
			{
				string Ten1, Ten2;
				// strcpy(Ten1, LocRaTen(lh.arr[i]));
				// strcpy(Ten2, LocRaTen(lh.arr[j]));

				if (strcmp((char*)Ten1.c_str(), (char*)Ten2.c_str()) == 1)
				{
					HoanVi(lh.arr[i], lh.arr[j]);
				}
			}
			else if (phanloai == 'g')
			{
				string Ten1, Ten2;
				// strcpy(Ten1, LocRaTen(lh.arr[i]));
				// strcpy(Ten2, LocRaTen(lh.arr[j]));

				if (strcmp((char *)Ten1.c_str(), (char*)Ten2.c_str()) == -1)
				{
					HoanVi(lh.arr[i], lh.arr[j]);
				}
			}
		}
	}
}
