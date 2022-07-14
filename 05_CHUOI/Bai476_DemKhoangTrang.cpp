Cho một chuỗi ký tự chỉ gồm các ký tự chữ cái latinh, chữ số và dấu cách. Một khoảng trống là một đoạn liên tiếp các ký tự trống (dấu cách) trong chuỗi. Hãy đếm số
lượng khoảng trống trong chuỗi.
Dòng đầu chứa số nguyên dương T là số chuỗi; dòng tiếp theo, mỗi dòng chứa một chuỗi có độ dài không quá 1000 ký tự.
input: 2		-> output: 
abc   xyz ab			 2
 abc def ghi 			3	  
/*
Ta sẽ đi xác định độ dài của chuỗi, rồi sau đó đi duyệt từ cuối về đầu chuỗi, dùng hàm isspace (kiểm tra xem ký tự được truyền vào có phải là khoảng trắng hay không)
trong thư viện #include<ctype.h> hỗ trợ để kiểm tra phần tử nào là khoảng trắng, nếu là khoảng trắng thì đếm tăng lên. Hoặc đi kiểm tra phần tử hiện tại là khoảng 
trắng và trước đó là 1 ký tự khác khoảng trắng thì đếm cũng được tăng lên, cứ thế cho đến hết chuỗi thì ngừng.

Lưu ý: NHẤN ENTER, VẪN BỊ COI LÀ 1 KHOẢNG TRẮNG, vậy nên tránh lỗi này, ta dùng thêm strtok cắt "\n" này đi là ổn.
(Nội dung tham khảo thư viện #include<ctype.h> ở bên dưới nè).
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define Max 1000
int DemKhoangTrang(char *a)  // đếm số lượng khoảng trắng có trong chuỗi
{
    int n = strlen(a);
    int dem = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == 0) // nếu chuỗi chỉ có 1 khoảng trắng (hoặc không có kí tự nào khác khoảng trắng)
        {
            if (isspace(a[i]))  // kiểm tra xem ký tự được truyền vào có phải là khoảng trắng hay không
            {
                dem++;
            }
        }
        else // ngược lại
        {
            if (isspace(a[i]) && !isspace(a[i - 1]))    // nếu phần tử này là khoảng trắng và trước đó là 1 ký tự khác khoảng trắng
            {
                dem++;
            }
        }
    }
    return dem;
}
int main(){
    char s[Max][Max];   //  tạo mảng 2 chiều: 1 cái lưu số lượng chuỗi nhập vào, 1 cái lưu lại kích thước thật sự của chuỗi
    int n;
    scanf("%d", &n);
    getchar();  
    for (int i = 0; i < n; i++)
    {
        fgets(s[i], Max, stdin);
        strtok(s[i], "\n"); // cắt khoảng trắng xuống dòng
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", DemKhoangTrang(s[i]));
    }
    return 0;
}
