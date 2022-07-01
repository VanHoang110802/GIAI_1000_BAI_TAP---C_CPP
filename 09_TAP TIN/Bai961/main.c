/* 
- Dòng đầu tiên là họ tên sinh viên
- Dòng tiếp theo lần lượt 3 điểm toán, lí, hóa
-> Đọc dữ liệu vào chương trình và tính điểm trung bình, rồi xếp loại sinh viên
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float TinhDiemTrungBinh(float toan, float ly, float hoa)
{
	return (toan + ly + hoa) / 3;
}

const char* XepLoai(float Dtb)
{
	// 0 --> <2: Kém
	// 2 --> <5: Yếu
	// 5 --> <7: Trung Bình
	// 7 --> <8: Khá
	// 8 --> <9: Giỏi
	// 9 --> 10: Xuất Sắc

	if (Dtb < 2)
	{
		return "Kem";
	}

	if (Dtb < 5)
	{
		return "Yeu";
	}

	if (Dtb < 7)
	{
		return "Trung Binh";
	}

	if (Dtb < 8)
	{
		return "Kha";
	}

	if (Dtb < 9)
	{
		return "Gioi";
	}
	return "Xuat Sac";
}

// Mở con trỏ thông qua 1 hàm thì con trỏ đó phải truyền vào dạng tham chiếu.
void MoFile(FILE** FileIn)
{
	*FileIn = fopen("INPUT.TXT", "r");

	// Kiểm tra xem file co ton tai hay khong ?
	if (!FileIn)
	{
		printf("\nKhong tim thay tap tin.");
		exit(0); // kết thúc toàn bộ chương trình.
	}
}

int main()
{
	// Mở file
	FILE* FileIn;

	MoFile(&FileIn);

	// Đọc file
	char *ten;
	ten = (char*)realloc(NULL, 30 * sizeof(char*));
	float toan, ly, hoa;

	fgets(ten, 30 * sizeof(char*), FileIn);
	fscanf(FileIn, "%f%f%f", &toan, &ly, &hoa);

	// Đóng file
	fclose(FileIn);

	FILE* FileOut = fopen("OUTPUT.TXT", "w");

	fprintf(FileIn, "%s", ten);
	float Dtb = TinhDiemTrungBinh(toan, ly, hoa);
	char *xeploai;
	xeploai = (char*)realloc(NULL, 30 * sizeof(char*));
	strcpy(xeploai, XepLoai(Dtb));

	fprintf(FileOut, "\nDtb = %.2f", Dtb);
	fprintf(FileOut, "\nXep loai: %s", xeploai);

	// đóng file lai.
	fclose(FileOut);
	free(ten);
	free(xeploai);
	return 0;
}
