Viết hàm tìm từ có chiều dài lớn nhất và xuất ra màn hình từ đó và độ dài tương ứng.

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
	int DoDaiMax = 0, start_max, end_max;
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
			if(end - start + 1 > DoDaiMax ){
				DoDaiMax = end - start +1;
				start_max = start;
				end_max = end;
			}
			start = -1; // cập nhật lại start tránh error		
		}
	}
	printf("\nChuoi max la: ");
	for (int k = start_max; k <= end_max; k++){
		printf("%c", s[k]);
	}
	printf("\nDo dai max = %d",DoDaiMax);
}
int main() {
	char s[] = "Hoang  dep   trai   ";
	printf("\n%s", s);
	XuatTuTrenDong(s);
	return 0;
}
