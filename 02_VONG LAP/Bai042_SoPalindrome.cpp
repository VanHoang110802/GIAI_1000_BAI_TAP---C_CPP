Một số nguyên dạng Palindrome là số mà đọc từ trái qua phải hay từ phải qua trái đều giống nhau, ví dụ các số Palindrome: 101, 22, 123321.
Nhập vào một mảng n số nguyên a1, a2, ... an. Hãy in ra các số Palindrome theo đúng thứ tự nhập.(0<= an<= 109)
Yêu cầu :không dùng các thao tác chuỗi để xử lý.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[100];
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < n; i++){
        int kq = 0;
        int donvi;
        int tg = a[i];
        while(tg > 0){
            donvi = tg % 10;
            kq = kq*10 + donvi;
            tg = tg/10;
        }
        if(a[i] - kq == 0){
            printf("%d ",a[i]);
        }
    }
    return 0;
}
