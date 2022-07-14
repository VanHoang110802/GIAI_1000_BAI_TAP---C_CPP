Hàm tìm chuỗi trong chuỗi: strstr(s1, s2) -
Tìm vị trí xuất hiện đầu tiên của s2 trong s1, kiểm tra xem có nằm trong chuỗi kia hay không

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define Max 110
void textcolor(int x){
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
int STRLEN(char *s){
	int dem =0;
	while(s[dem]!='\0'){
		dem++;
	}
	return dem;
}
int STRSTR(char *s1, char *key){
	int length_s1 = STRLEN(s1);
	int length_key = STRLEN(key);	
// duyệt cái chuỗi đang chứa chuỗi cần tìm
	for(int i=0;i<length_s1;i++){
		if(s1[i] == key[0]){
			int temp = i + 1, check = 1;
			for(int j =1;j<length_key;j++){
				if(s1[temp] != key[j]){
					check = 0;
					break;
				}
			}
			if(check == 1) return i;
			//else i--;
		}
	}
	return -1;
}
// nâng cấp bài này qua level mới : gặp tìm được chữ nào đó, thì tô màu cho chữ mà nó tìm thấy 
/*
void STRSTR(char *s, char *key){
	int arr[100];
	int idx = 0;
	int length_s = STRLEN(s);
	int length_key = STRLEN(key);

	// duyệt cái chuỗi đang chứa chuỗi cần tìm
	for(int i = 0; i < length_s; i++){
		if(s[i] == key[0]){
			//printf("\nTest1: Tim thay tai vi tri: %d", i);
			//int k = 1;
			int Check = true;
			int temp = i + 1;
			for(int j = 1; j < length_key; j++){
				if(s[temp++] != key[j]){
					Check = false;
					break;
				}
			}
			if(Check == true){
				arr[idx++] = i;
			}
		}
	}
	idx = 0;
	// duyệt lại chuỗi ban đầu.
	for(int i = 0; i < length_s; i++){
		// bắt đầu
		if(i == arr[idx]){
			textcolor(11); // bật sang màu xanh
		}
		// kết thúc
		if(i == arr[idx] + length_key){
			textcolor(7); // bật lại màu trắng
			idx++; // chuyển sang vị trí tiếp theo được tìm thấy
		}
		printf("%c", s[i]);
	}
}
*/
int main() {
	char s1[Max] = "hoang8d";
	char key[Max] = "8d ";
	// STRSTR(s1,key);
	int vitri = STRSTR(s1, key);
	if(vitri == -1) printf("\nKhong tim thay");	// -> Khong tim thay
	else printf("\nTim thay tai vi tri %d", vitri + 1);
	return 0;
}
