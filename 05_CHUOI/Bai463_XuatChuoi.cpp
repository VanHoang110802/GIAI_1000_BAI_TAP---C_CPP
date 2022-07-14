Viết hàm nhận vào một chuỗi s và xuất các từ trên các dòng liên tiếp.
/*
Tìm 1 điểm bắt đầu 1 từ và điểm kết thúc của nó, thì đó là 1 từ rồi xuất ra, từ 1 vị trí bắt đầu, cho 1 vòng lặp chạy để tìm cái điểm kết thúc của từ, khi có kết thúc
thì cập nhật lại vị trí để lần sau nó sẽ lặp lại vị trí vừa cập nhật lại, còn nếu không nó sẽ lặp chỗ khác là hơi mệt đấy.
Lưu ý: mình nên làm cái cách nào tránh việc thêm xóa phần tử, nếu thêm xóa phần tử thì sau này đi xử lý sẽ vất vả lắm 
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
void XuatTuTrenDong(char* s){
	int start = -1, end;

	int length = strlen(s);

	if (s[0] != ' '){
		start = 0;
	}

	for (int i = 0; i < length - 1; i++){
		// tìm bắt đầu
		if ((s[i] == ' ' && s[i + 1] != ' ') || start == 0){
			start = i + 1;
			// chơi chiêu nè
			if (start == 1){
				start = 0;
			}

			// đã có vị trí bắt đầu, từ vị trí bắt đầu để duyệt tiếp tục để tìm ra vị trí end
			for (int j = start + 1; j < length - 1; j++){
				if (s[j] != ' ' && s[j + 1] == ' '){
					end = j;
					i = j; // cập nhật lại vị trí duyệt, nếu không sẽ bắt đầu duyệt lại vị trí khác
					break; // thoát ra
				}
			}

			// in ra các kí tự vừa duyệt được trong đoạn start -> end.
			for (int k = start; k <= end; k++){
				printf("%c", s[k]);
			}
			start = -1; // cập nhật lại start tránh error
			printf("\n");			
		}
	}
}
int main() {
	char s[] = "Hoang  dep   trai   ";
	XuatTuTrenDong(s);
	printf("\n%s", s);
	return 0;
}
