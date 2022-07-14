Nhập vào 1 chuỗi hệ 2, hệ 8, hệ 16 và chỉ dùng 1 hàm duy nhất: 
Đổi số đó sang nhị phân (hệ 2),sang hệ bát phân (hệ 8) và sang hệ hexa (hệ 16) .
(Bài này giống ở phần mảng 1 chiều, nhưng lúc đó mình lại đi hiểu sai mất cái đề :vv)

#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
#include<conio.h>
#define Max 100
int STRLEN(char* s) {
	int dem = 0;
	while (s[dem] != '\0') {
		dem++;
	}
	return dem;
}
void HoanVi(char& x, char& y) {
	char temp = x;
	x = y;
	y = temp;
}
void STRREV(char* s) {	// đảo lại chuỗi
	int length = STRLEN(s);
	for (int i = 0; i < length/2; i++) {
		HoanVi(s[i], s[length - 1 - i]);
	}
}
void ChuyenDoiHe(int n, int cosocanchuyen, char*ketqua) {
	int idx = 0;
	while (n != 0) {
		int temp = n % cosocanchuyen;	// biến phụ lưu lại kết quả phép tính
		n /= cosocanchuyen; 	// cập nhật lại n để nếu còn thì đi tính tiếp

		if (temp < 10) {	// THÌ LÀ 1 SỐ NGUYÊN
			ketqua[idx++] = temp + 48; 	// ĐỔI SỐ NGUYÊN SANG KÝ TỰ TƯƠNG ỨNG
		}
		else if (temp == 10) {
			ketqua[idx++] = 'A';
		}
		else if (temp == 11) {
			ketqua[idx++] = 'B';
		}
		else if (temp == 12) {
			ketqua[idx++] = 'C';
		}
		else if (temp == 13) {
			ketqua[idx++] = 'D';
		}
		else if (temp == 14) {
			ketqua[idx++] = 'E';
		}
		else if (temp == 15) {
			ketqua[idx++] = 'F';
		}
	}
	ketqua[idx] = '\0'; 	// Phải nhớ kết thúc chuỗi
	STRREV(ketqua); 	// đảo ngược chuỗi lại
}
int main() {
	int n = 1992, heso = 16;
	char ketqua[Max];
	ChuyenDoiHe(n, heso, ketqua);
	printf("%s", ketqua);	// 1992 -> 7C8
	return 0;
}
