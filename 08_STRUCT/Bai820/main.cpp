#include "LopHoc.h"

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

int main()
{
	int luachon;
	LOPHOC lh;
	while (true)
	{
		cout << "\t\tCHUONG TRINH QUAN LY SINH VIEN C/C++\n";
		cout << "\t*******************************************************\n";
		cout << "\t*   0. Thoat.                                         *\n";
		cout << "\t*   1. Nhap thong tin sinh vien.                      *\n";
		cout << "\t*   2. Xuat thong tin sinh vien.                      *\n";
		cout << "\t*   3. Sap xep lop hoc dua tren DTB.                  *\n";
		cout << "\t*   4. Dem so luong hoc bong cua sinh vien.           *\n";
		cout << "\t*   5. Dem so luong sinh vien hoc lai.                *\n";
		cout << "\t*   6. Tim kiem sinh vien dua tren ma so.             *\n";
		cout << "\t*   7. Them 1 sinh vien.                              *\n";
		cout << "\t*   8. Xoa 1 sinh vien.                               *\n";
		cout << "\t*   9. Cap nhat lai thong tin sinh vien.              *\n";
		cout << "\t*******************************************************\n";
		cout << "Nhap tuy chon: ";
		cin >> luachon;
		switch (luachon)
		{
		case 0:
		{
			exit(0);
		}
		break;
		case 1:
		{
			system("cls");
			NhapLopHoc(lh);
			system("cls");
		}

		break;
		case 2:
		{
			if (lh.n > 0)
			{
				system("cls");
				XuatLopHoc(lh);
				system("pause");
				system("cls");
			}
			else
			{
				system("cls");
				cout << "\n\nXin hay nhan lua chon 1 de nhap thong tin!\n\n";
				system("pause");
				system("cls");
			}
		}

		break;
		case 3:
		{
			if (lh.n < 1)
			{
				system("cls");
				cout << "\n\nXin hay nhan lua chon 1 de nhap thong tin!\n\n";
				system("pause");
				system("cls");
			}
			else
			{

				system("cls");
				cout << "Ban muon sap xep kieu tang dan hay giam dan?\n(t - sap tang, g - sap giam, x - quay lai): ";
				char c;
				cin >> c;
				while (1)
				{
					if (c == 't' || c == 'T')
					{
						system("cls");
						SapXepLopHoc(lh, 't');
						XuatLopHoc(lh);
						system("pause");
						system("cls");
						break;
					}
					else if (c == 'g' || c == 'G')
					{
						system("cls");
						SapXepLopHoc(lh, 'g');
						XuatLopHoc(lh);
						system("pause");
						system("cls");
						break;
					}
					else if (c == 'x' || c == 'X')
					{
						system("cls");
						break;
					}
					else
					{
						system("cls");
						cout << "\nKhong co chuc nang nay!";
						cout << "\nHay chon chuc nang trong hop menu.";
						system("pause");
						system("cls");
						break;
					}
				}
			}
		}
		break;
		case 4:
		{
			system("cls");
			int demsoluong = DemSoLuongHocBong(lh);

			cout << "\nSo luong hoc bong: " << demsoluong;
			system("pause");
			system("cls");
		}break;
		case 6:
		{
			string MaTimKiem;
			getchar();
			cout << "\nNhap vao ma tim kiem la: ";
			getline(cin, MaTimKiem);

			system("cls");
			SINHVIEN* sv = TimKiemThongTin(lh, MaTimKiem);

			if (sv == NULL)
			{
				printf("\nKhong tim thay thong tin sinh vien");
			}
			else
			{
				printf("\nTim thay thong tin sinh vien la\n");
				XuatSinhVien(*sv);
			}

			system("pause");
			system("cls");
		}
		break;

		case 7:
		{
			if (lh.n < 1)
			{
				system("cls");
				cout << "\n\nXin hay nhan lua chon 1 de nhap thong tin!\n\n";
				system("pause");
				system("cls");
			}
			else
			{
				SINHVIEN them; // thêm vào cuối danh sách lớp.

				// Nhập thông tin sinh viên cần thêm
				getchar();
				do
				{
					cout << "\nNhap vao ma so: ";
					getline(cin, them.MaSo);

					TimKiemThongTin(lh, them.MaSo);
					if (TimKiemThongTin(lh, them.MaSo) != NULL)
					{
						cout << "\nMa so nay da ton tai! Xin hay nhap ma khac!";
					}
				} while (TimKiemThongTin(lh, them.MaSo) != NULL);


				NhapSinhVien(them);
				REALLOC(lh.arr, lh.n, lh.n + 1);

				// Đưa thông tin sinh viên thêm vào cuối cùng.
				lh.arr[lh.n] = them;

				lh.n++; // Tăng số lượng sinh viên lên.
				system("cls");
				cout << "\nDanh sach lop hoc sau khi them la\n";
				XuatLopHoc(lh);
				system("pause");
				system("cls");
			}
		}
		break;
		case 8:
		{
			if (lh.n < 1)
			{
				system("cls");
				cout << "\n\nXin hay nhan lua chon 1 de nhap thong tin!\n\n";
				system("pause");
				system("cls");
			}
			else
			{
				system("cls");
				int lc_1;
				do
				{
					cout << "\n\t*   1. Xoa 1 sinh vien.                  *\n";
					cout << "\n\t*   2. Xoa 1 sinh vien theo Ma so.       *\n";
					cout << "\n\t*   3. Xoa het sinh vien bi rot mon.     *\n";
					cout << "\n\t*   0. Thoat.                            *\n";
					cout << "\n\nXin nhap lua chon: ";
					cin >> lc_1;
					if (lc_1 < 0 || lc_1 > 3)
					{
						cout << "\nLua chon khong hop le!\n";
					}
					else if (lc_1 == 1)
					{
						system("cls");
						int stt;
						XuatLopHoc(lh);
						do
						{
							cout << "\n\nVui long nhap so thu tu (TU 0 -> " << lh.n - 1 << ") de xoa : ";
							cin >> stt;
							if (stt < 0 || stt > lh.n)
							{
								cout << "\nSo thu tu de xoa khong hop le. Xin kiem tra lai!";
							}
						} while (stt < 0 || stt > lh.n);
						if (stt > 0)
						{
							XoaSinhVien(lh, stt);
							system("cls");
							cout << "\nDanh sach lop sau khi xoa la:\n\n";
							XuatLopHoc(lh);
						}
						system("pause");
					}
					else if (lc_1 == 2)
					{
						system("cls");
						string ms;
						getchar();
						do
						{
							cout << "\n\nVui long nhap ma so de xoa\n(Hoan nhan enter lien tiep de quay lai!): ";
							getline(cin, ms);

							int len_ms = ms.length();
							if (TimKiemThongTin(lh, ms) == NULL )
							{
								cout << "\nKhong tim thay ma so de xoa!";
							}
							if (len_ms < 1)
							{
								break;
							}
						} while (TimKiemThongTin(lh, ms) == NULL );
						if (ms != "")
						{
							XoaSinhVienDuaTrenMaSo(lh, ms);
							system("cls");
							cout << "\nDanh sach lop sau khi xoa la:\n\n";
							XuatLopHoc(lh);
						}
						system("pause");
					}
					else if (lc_1 == 3)
					{
						XoaTatCaSinhVienRotMon(lh);
						system("cls");
						cout << "\nTHANH CONG!\n\n";
						system("pause");
					}
					system("cls");
				} while (lc_1 < 0 || lc_1 > 3);
			}
		}
		case 9:
		{
			if (lh.n < 1)
			{
				system("cls");
				cout << "\n\nXin hay nhan lua chon 1 de nhap thong tin!\n\n";
				system("pause");
				system("cls");
			}
			else
			{
				system("cls");
				string ms_2;
				do
				{
					getchar();
					cout << "\nNhap ma so cua sinh vien can cap nhat lai\n(Nhan tiep enter de quay lai): ";
					getline(cin, ms_2);
					int len_11 = ms_2.length();
					if (TimKiemThongTin(lh, ms_2) == NULL)
					{
						cout << "\nMa so khong ton tai! Xin hay kiem tra lai!\n";
					}
					if (len_11 == 0)
					{
						break;
					}
				} while (TimKiemThongTin(lh, ms_2) == NULL);
				if (ms_2 != "")
				{
					CapNhatDuaTrenMaSo(lh, ms_2);
					cout << "\nDanh sach sau khi cap nhat la:\n";
					XuatLopHoc(lh);
				}
				system("pause");
				system("cls");
			}
		}
		}
	}
	// giải phóng bộ nhớ.
	delete[]lh.arr;
	return 0;
}
