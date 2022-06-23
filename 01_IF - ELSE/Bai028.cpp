Iroha yêu Haiku. Haiku là một dạng thơ ngắn của Nhật Bản. Một bài Haiku bao gồm ba câu với số ký tự lần lượt là 5, 7 và 5.
Để tạo ra một bài thơ Haiku. Iroha đã nghĩ ra ba câu khác nhau. Mỗi câu có độ dài tương ứng là A, B và C. Xác định xem cô ấy có thể tạo một bài Haiku bằng cách sử dụng 3 câu trên mỗi câu 1 lần hay không? (1 <= A,B,C <= 10)
input: 5 5 7	->output: YES
input: 7 7 5	->output: NO

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	if (A == 5 && B == 5 && C == 7 || A == 5 && B == 7 && C == 5 || A == 7 && B == 5 && C == 5) {
		printf("YES");
	}
	else {
		printf("NO");
	}
	return 0;
}
