Viết chương trình nhập vào 2 ký tự (chữ cái) viết thường được lưu vào 2 biến kiểu char a và b. Liệt kê ra các chữ cái viết hoa trong đoạn [a, b].
input: a c -> output: A B C

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
void clean_stdin()  // xóa bộ nhớ đệm đi, hàm fflush phế rồi
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
int main()
{
    char a, b;
    printf("Nhap a= ");
    scanf("%c", &a);
    clean_stdin();
    printf("Nhap b = ");
    scanf("%c", &b);
    int x = a;	// đổi kí tự sang mã ascii
    int y = b;
    printf("\n");
    for (int i = x; i <= y; i++) {
        printf("%c ", (char)i - 32);	// ép kiểu cho nó về dạng kí tự hoa theo bảng mã ascii
    }
    return 0;
}
// cách 2:
/*
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

int main()
{
    char a, b;
    printf("Nhap a= ");
    scanf("%c", &a);
    //clean_stdin();
    getchar();
    printf("Nhap b = ");
    scanf("%c", &b);
    int x = a;	// đổi kí tự sang mã ascii
    int y = b;
    printf("\n");
    for (int i = x; i <= y; i++) {
        printf("%c ", (char)i - 32);	// ép kiểu cho nó về dạng kí tự hoa theo bảng mã ascii
    }
    return 0;
}
*/
