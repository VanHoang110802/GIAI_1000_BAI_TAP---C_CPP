Nam là người thích chat với bạn bè trên Internet. Cậu ấy đã lập ra một phòng chat với điều kiện rằng trước khi vào phòng chat, mọi người phải chào hỏi trước.
Một câu chào được định nghĩa rằng, câu chào đó phải là một xâu kí tự, chỉ gồm các chữ cái, không chứa kí tự trắng, sao cho khi xóa đi một số chữ cái, nó sẽ trở thành từ "hello", tất nhiên là sẽ không được phép tráo đổi vị trí các chữ cái, mà chỉ được xóa bớt một số chữ cái.
Ví dụ khi Bình muốn vào phòng chat, Bình gõ "ahhellllloou" thì hệ thống sẽ xem xét xâu này và sẽ tự động loại bỏ các chữ cái để trở thành từ "hello". Như vậy Bình được vào phòng chat.
Nhưng khi Bình gõ "hlelo", hệ thống không thể làm cách nào xóa bớt chữ cái để trở thành từ "hello" được. Như vậy, Bình không được vào phòng chat.
Xác định xem, khi Bình gõ một xâu, xâu đó có được chấp nhận để Bình vào phòng chat hay không?
input: ahhellllloou	-> output: hello -> Yes
	hlelo			   hlelo -> No
/*
Ta sẽ đi xác định độ dài của chuỗi điều kiện và chuỗi vừa nhập,rồi có 1 biến đếm, duyệt hết các phần tử vừa nhập và các phần tử của chuỗi điều kiện, nếu mà phần tử của cả 2 chuỗi mà bằng nhau thì tăng biến  đếm lên, nếu biến đếm bằng với độ dài của chuỗi điều kiện thì in ra kq rồi kết thúc luôn.
*/
#include <stdio.h>
#include<conio.h>
#include<string.h>
#define Max 100
int main(){
	char s[Max];
	scanf("%s",s);	// không cần thiết dùng fgets, vì nhập nhập xâu để đi kiểm tra không cần có khỏang trắng.
	char s1[]= "hello";   // chuỗi điều kiện
	int dem = 0;
	int n = strlen(s);
	int m = strlen(s1);
	for(int i=0;i<n;i++){
		if(s[i] == s1[dem]){
			dem++;
			if(dem == m){
				printf("Yes");
				return 0;
			}
		}
	}
	printf("No");
	return 0;
}
