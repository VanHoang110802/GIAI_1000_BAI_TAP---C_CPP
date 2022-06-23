Viết chương trình trò chơi oẳn tù tì giữa người và máy theo thể lệ người luôn đi trước.

Luật chơi như sau: Người nhập vào ký tự tương ứng:
'B' hay 'b' => Búa
'O' hay 'o' => Bao
'K' hay 'k' => kéo

Sau đó Máy sẽ random ra ký tự bất kỳ (có thể là búa hoặc bao hoặc kéo). Sau đó tính kết quả chung cuộc (người thắng hay máy thắng).

Gợi ý: Tham khảo cách Random số nguyên trong 1 đoạn nào đó, ta có thể quy ước vd: số 1 => búa, 2 => bao, 3 => kéo. Rồi tính thắng thua giữa người & máy theo nguyên tắc như ngoài đời:

- Búa thắng kéo nhưng thua bao
- Bao thắng búa nhưng thua kéo
- Kéo thắng bao nhưng thua búa.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
int main(){
	char luachon;
	printf("Tro choi oan tu ti!\n");
	printf("\nBan bam cac ki tu sau de choi: ");
	printf("\nB - b -> Bua");
	printf("\nO - o -> Bao");
	printf("\nK - k -> Keo");
	printf("\n\nLua chon cua ban: ");
	scanf("%c", &luachon);
	
	if (luachon == 'B' || luachon == 'b') {
		printf("Ban vua chon Bua!");
	}
	else if (luachon == 'O' || luachon == 'o') {
		printf("Ban vua chon Bao!");
	}
	else if (luachon == 'K' || luachon == 'k') {
		printf("Ban vua chon Keo!");
	}
	else {
		printf("Ban chon khong hop le, vui long chon lai!");
		return 0;
	}

	printf("\n\nLoading ");
	Sleep(1000);
	printf(".");
	Sleep(800);
	printf(".");
	Sleep(500);
	printf(".");
	printf("\n");

	srand(time(0));
	

	int may = 1 + rand() % 3;

	if (may == 1) {
		printf("\nMay ra Bua!");
	}
	else if (may == 2) {
		printf("\nMay ra Bao!");
	}
	else if (may == 3) {
		printf("\nMay ra Keo!");
	}
	
	if (luachon == 'B' || luachon == 'b') {
		if (may == 1) {
			printf("\nHoa nhau!");
		}
		else if (may == 2) {
			printf("\nMay thang!");
		}
		else if (may == 3) {
			printf("\nBan thang!");
		}
	}
	if (luachon == 'O' || luachon == 'o') {
		if (may == 1) {
			printf("\nBan thang!");
		}
		else if (may == 2) {
			printf("\nHoa nhau!");
		}
		else if (may == 3) {
			printf("\nMay thang!");
		}
	}
	if (luachon == 'K' || luachon == 'k') {
		if (may == 1) {
			printf("\nMay thang!");
		}
		else if (may == 2) {
			printf("\nBan thang!");
		}
		else if (may == 3) {
			printf("\nHoa nhau!");
		}
	}
	return 0;
}
