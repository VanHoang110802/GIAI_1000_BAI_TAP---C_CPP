Viết chương trình nhập mật khẩu và sau khi nhấn vào bàn phím 1 phím thì 1 chút sau nó sẽ biến thành *, quá trình nhập kết thúc khi nhấn phím enter

gợi ý:
while(true)
{
	char kytu;
	scanf("%c", &kytu);

	// tra tren bang ma ascii
	if(kytu == 'enter')
		break;
}

Dùng \b để "lùi lại 1 bước"


#include <stdio.h>
#include <conio.h>
#include <Windows.h>
int main() {
hoang:
	printf("pass: ");
	printf("\n");
	while (true)
	{
		
		char kytu;
		kytu = getch();
		printf("%c", kytu);
		Sleep(20);
		printf("\b");
		printf("*");
		if (kytu == 13) {
			printf("\nDang nhap thanh cong!");
			Sleep(2000);
			break;
		} 
		else if(kytu == 8){	
			printf(" \b");
		} 
	}
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
