/*
1. Xây dựng chương trình nhập vào 1 chuỗi dùng hàm scanf (nhập cả dấu cách) 1.0 điểm

2. Xây dựng chương trình nhập vào 1 chuỗi giống như câu lệnh copy con trong Dos
(nhập cả dấu cách, cả xuống dòng và khi ấn f6 rồi enter thì thoát ) (toàn bộ dữ liệu nhập vào nằm trong 1 chuỗi) 3.0 điểm


3. Xây dựng chương trình nhập vào 1 chuỗi ko có kí tự số
ví dụ :
nhập vào abc123 thì : abc vào trong chuỗi , 123 nằm trong stdin nhập vào abvsadsad*&^%%123 thì abvsadsad*&\n^%% vào trong chuỗi, 123 còn trong stdin nhập vào ab3abc thì ab vào chuỗi 3abc nằm trong stdin
3.0 điểm


4.
a. Xây dựng chương trình nhập vào 1 chuỗi chỉ có chữ cái thường và số 8, dấu cách và dấu * và dấu ^
b. Xây dựng chương trình nhập vào 1 chuỗi , việc nhập kết thúc khi ấn ^ rồi ấn enter 2.0 điểm

5. Xây dựng chương trình nhập vào 1 chuỗi ko có điểm ngừng (dùng scanf) . Nhập mãi mãi ko dừng  1.0 điểm

_xong cái này chắc mọi người sẽ tìm ra câu trả lời tại sao lại dạy học sinh dùng gets để nhập chuỗi chứ ko dạy học sinh dùng scanf để nhập chuỗi.

Yêu cầu :
_ dùng chỉ scanf() để input
_ cho phép dùng getch() để dừng chương trình
_ nếu dùng các cấu trúc lặp hoặc đệ quy trong câu trên thì chỉ được 1/2 số điểm
_ xong bài này mọi người sẽ hiểu tại sao mà ở các trường toàn chỉ học sinh dùng gets thay cho scanf......

#include <stdio.h>
#include <conio.h>
int main()
{
    char xau[100];
    //cau 1
    scanf("%[^\n]",xau);	// đọc tất cả kí tự trừ dấu ^ và \n
 
    //cau 2
    scanf("%[^\0]",xau);	// đọc tất cả kí tự trừ dấu ^ và \0
 
    //cau 3
    scanf("%[^0-9]",xau);	// đọc tất cả kí tự trừ dấu ^ và các số từ 0-9
 
    //cau 4
    scanf("%[a-z8*^ ]",xau);	// đọc tất cả kí tự trừ dấu ^, các số từ 0-8, và các kí tự từ a-z
    scanf("%[^^]",xau);
 
    //cau 5
    scanf("%[]",xau);
    return 0;
}

Hàm gets() rất ít được sử dụng. Bất kì lập trình viên nào cũng tránh dùng hàm này. Vì nó gây lỗi memory overflow, vì hàm này không nhận vào 
đối số chỉ kích thước của vùng nhớ, nó chỉ nhận vào con trỏ trỏ đến vùng nhớ. Dữ liệu nhập sẽ được ghi vào vùng nhớ đó. Nếu dữ liệu nhập lớn 
hơn kích thước đã cấp phát cho bộ nhớ thì chuyện gì sẽ xảy ra? Xem vd sau:
#include <stdio.h>
int main()
{
    char szBuffer[10];
 
    gets(szBuffer);
 
    printf("Input string: %s", szBuffer);    
 
    return 0;
}
Sẽ không có chuyện gì xảy ra nếu như bạn chỉ nhập một chuỗi có số kí tự ít hơn 10. Nếu nhập nhiều hơn, các kí tự thừa sẽ bị ghi vào vùng nhớ
không được quản lý. Nếu chạy trên bằng VS bạn sẽ nhận được cảnh báo như sau:

Đây là lỗi rất nghiêm trọng, là kẽ hở của các kiểu tấn công bảo mật.
*/
