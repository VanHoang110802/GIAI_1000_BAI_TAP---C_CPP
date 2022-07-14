Viết lại hàm cắt chuỗi (strtok): 
chúng ta cần hàm tìm kiếm 1 cái chuỗi trong 1 chuỗi cho trước, xem vị trí đầu tiên nó nằm ở vị trí nào. Rồi cần 1 hàm cắt chuỗi đem chuỗi vừa tìm được vừa cắt được đó 
đem ra ngoài.
(19/02/2022 - Đã hoàn thành ^^ - Bài này khó vcc, tốn kha khá time @@ ).

/*
Đê làm được hàm này, trước hết ta sẽ có hàm cắt chuỗi con trong đoạn từ [a,b] trong chuỗi s đã cho trước, nhưng bên C này ta không có hàm này, chỉ có bên C++ mới có
(substr) vì vậy ta sẽ phải tự đi xây dựng hàm đó thôi.
Rồi ta sẽ dùng hàm strstr để xác định vị trí bắt đầu của chuỗi con hoặc nếu tự viết lại thì ta có 1 biến x, biến x này tượng trưng cho vị trí bắt đầu của cái chuỗi s
ban đầu, rồi sau đó duyệt từ vị trí x đến độ dài cuối cùng của chuỗi, nếu mà phần tử đầu của chuỗi tìm kiếm mà giống với 1 phần tử đầu của 1 chuỗi đã cho trước 
(chuỗi s) thì lập tức ta có 1 biến phụ lưu lại vị trí đó (vì vị trí sẽ có thay đổi nên ta phải có biến phụ lưu trữ lại), cập nhật cho check = 1, rồi đi duyệt lại cái
chuỗi cần tìm kiếm, nếu trong lúc duyệt phần tử cần tìm kiếm đó mà có 1 vị trí nào đó trong chuỗi mà khác với vị trí chứa phần tử của chuỗi s ban đầu, thì lập tức cho
check = 0 rồi thoát khỏi vòng lặp luôn, 1 vị trí nào đó mà khác nhau rồi thì ta không cần đi xét tiếp nữa làm gì, chỉ cần đi xét tiếp nếu chúng giống nhau mà thôi. Nếu
đi hết tất cả các vị trí trong vòng lặp rồi mà thỏa hết các vị trí với nhau thì check = 1 và return lại biến phụ đã lưu lại vị trí đó.
Tiếp theo, ta sẽ cho biến x = 0, vị trí = -1 (thực chất chuỗi chính là 1 mảng 1 chiều các kí tự, mà mảng thì vị trí bắt đầu từ 0, làm gì có vị trí nào bắt đầu từ -1 
đâu). Có vòng lặp vô tận, lúc này x = vị trí + 1 (như đã nói ở trên, mảng bắt đầu vị trí 0), rồi ta cập nhật lại vị trí của chuỗi chính là vị trí bắt đầu của chuỗi con
đã tìm được ở bên trên kia, nếu vị trí = -1 thì ta sẽ đi duyệt chuỗi s rồi in hết các kí tự có trong chuỗi này. Nếu ngược lại, vị trí tìm thấy mà khác -1 thì lúc này 
ta chỉ việc cắt chuỗi tại vị trí đã tìm được ra rồi đi in ra thôi.
*/
 /*
 #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#define Max 100
int STRLEN(char* s) {	// xác định độ dài chuỗi
	int dem = 0;
	while (s[dem] != '\0') {
		dem++;
	}
	return dem;
}
void STRCPY(char* s1, char* s2) {	// strcpy: gán chuỗi này sang cho chuỗi kia
	int lengths2 = STRLEN(s2);
	for (int i = 0; i < lengths2; i++) {
		s1[i] = s2[i];
	}
	s1[lengths2] = '\0';   // phải có cái này để nó còn biết s1 nó ngừng ở đâu để mà gán cho chuỗi qua.? Nếu không xuất hiện những kí tự la.
}
// hàm cắt chuỗi con trong đoạn [a,b] của 1 chuỗi s cho trước:
char* SUBSTR(char* s, int x, int y) {
	char *ketqua = new char;
	int idx = 0;
	for (int i = x; i < y; i++) {
		ketqua[idx++] = s[i];
	}
	ketqua[idx] = '\0';
	return ketqua;
}
// hàm đi tìm vị trí bắt đầu cho lần cắt chuỗi tiếp theo:
int TimViTriDauTien(char* s, char* find, int x) {	// strstr: tìm vị trí của chuỗi
	int length_s = STRLEN(s);
	int length_find = STRLEN(find);
	int start, check = 0;	// bắt đầu tìm thấy chuỗi
	// duyệt cái chuỗi đang chứa chuỗi cần tìm
	for (int i = x; i < length_s; i++) {
		if (s[i] == find[0]) {	// phần tử đi tìm bằng với kí tự trong chuỗi nào đó
			start = i;
			check = 1;
			int temp = start;	// khởi tạo biến phụ lưu lại vị trí tìm được
			for (int j = 1; j < length_find; j++) {
				if (find[j] != s[temp++]) {
					check = 0;
					break;
				}
			}
			if (check == 1) return start;
		}
	}
	return -1;
}
void STRTOK(char* s, char* cut) {
	// nếu gặp khoảng trắng thì lấy chuỗi trước đó, còn nếu có null thì lấy chuỗi kế tiếp
	//char s1[Max];
	char* s1 = new char;
	int x = 0;
	int vitri = -1;	//khởi tạo vị trí ban đầu là chưa có.
	while (true) {
		x = vitri + 1;
		//printf("\n\n%d", x);
		vitri = TimViTriDauTien(s, cut, x);
		//printf("\n%d\n", vitri);
		if (vitri == -1) {
			int length = STRLEN(s);
			for (int i = x; i < length; i++) {
				printf("%c", s[i]);
			}
			break;
		}
		else {
			//printf("\n%d", vitri);
			STRCPY(s1, SUBSTR(s, x, vitri)); // - là vị trí bắt đầu
			printf("%s\n", s1);
		}
	}
}
int main() {
	char s[] = " Truong Van Hoang ";
	char cut[] = " ";	// cắt
	STRTOK(s, cut);
	/*char s[] = " Truong     Van Hoang   ";
	char* p = strtok(s, " ");
	while (p != NULL)
	{
		printf("%s\n", p);
		p = strtok(NULL, " ");
	}*/
	return 0;
}
*/
  
// ======================================== FIX LẠI ========================================
#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
using namespace std;

int STRLEN(const char *s)
{
	int cnt = -1;
	while(s[++cnt] != '\0');
	return cnt;
}

char* STRTOK(char *s, const char* delim)
{
	static char* start = s;
	static char* finish = s;
	static int length = STRLEN(s);
	static int cnt = 0;

	if(s == NULL)
	{
		start = finish + 1;
		finish = start;
	}

	if(cnt == length)
	{
		return NULL;
	}
	
	while(*finish != '\0')
	{
		cnt++;
		const char* temp = delim;
		while(*temp != '\0')
		{
			if(*temp == *finish)
			{
				*finish = '\0';
				break;
			}
			temp++;
		}
		if(*finish != '\0')
		{
			finish++;
		}
	}
	if(start == finish)
	{
		return STRTOK(s, delim);
	}
	return start;
}

int main()
{
	char s[] = "Truong Van Hoang";
	char *p = strtok(s, "an");
	while(p != NULL)
	{
		cout << p << endl;
		p = strtok(NULL, "an");
	}
	cout << "===================\n";
	char s1[] = "Truong Van Hoang";
	char *p1 = STRTOK(s1, "an");
	while(p1 != NULL)
	{
		cout << p1 << endl;
		p1 = STRTOK(NULL, "an");
	}
	return 0;
}
