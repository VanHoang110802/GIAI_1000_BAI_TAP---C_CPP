Fiona tự tin mình là người học rất giỏi môn ngữ văn nên muốn đố chữ các bạn trong lớp. Cô sẽ chuẩn bị một xâu ký tự, thay thế dấu* vào một vài vị trí và cho các bạn
đoán xâu ban đầu. Nhưng vì bận làm việc nhà nên Fiona muốn các bạn giúp cô ấy chuẩn bị xâu đã mã hóa để cô ấy chỉ việc đi đố người khác thôi.
Các bạn hãy giúp Fiona mã hóa xâu theo quy tắc sau: đánh dấu*vào những vị trí số nguyên tố của xâu.
input: LapTrinhPTITLapTrinhTuTraiTim  -> output: La**r*n*PTI*L*pTr*n*TuT*aiTim
/*
Ta sẽ đi xác định độ dài của chuỗi nhập vào,sau đó duyệt chuỗi, nếu tại vị trí nào thuộc là số nguyên tố thì in dấu "*" ra .
Lưu ý: không xét dấu '\0' kết thúc chuỗi, nếu để ý kĩ thì vị trí cuối cùng là số nguyên tố thì cũng không xét luôn.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#define Max 10000
int KiemTraSoNT(int n) {
	int check = 1, temp = n;
	if (temp < 2) {
		check = 0;
	}
	else {
		if (temp > 2 && temp % 2 == 0) {
			check = 0;
		}
		else {
			for (int i = 2; i * i <= temp; i++) {
				if (temp % i == 0) {
					check = 0;
					break;
				}
			}
		}
	}
	if (check == 1) {
		return 1;
	}
	return 0;
}
int main() {
	char s1[] = "LapTrinhPTITLapTrinhTuTraiTim";// chuỗi điều kiện
	//char s1[Max];
	//fgets(s1, sizeof(s1), stdin);

	int m = strlen(s1);   // xác định độ dài chuỗi
	//printf("%d\n", m);
	for (int i = 0; i < m; i++) {
		// nếu tại vị trí cuối là 1 vị trí thuộc số nguyên tố thì không xét, hoặc là '\0' cũng không xét luôn
		if (KiemTraSoNT(i)== 1 && i != m - 1) {
			printf("*");
		}
		else printf("%c", s1[i]);
	}
	return 0;
}
