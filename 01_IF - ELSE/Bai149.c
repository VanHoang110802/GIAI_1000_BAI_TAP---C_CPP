Viết chương trình nhập vào 3 số thực. Hãy in 3 số thực ấy ra màn hình
theo thứ tự tăng dần mà chỉ dùng tối đa hai biến phụ.

#include<stdio.h>
#include<conio.h>
int main()
{
hoang:
/*
a  b  c
5  4  7

a so sánh với b và c
b so sánh với c
*/
    int a, b, c, temp;
    printf("Nhap a= ");
    scanf("%d", &a);

    printf("Nhap b= ");
    scanf("%d", &b);

    printf("Nhap c= ");
    scanf("%d", &c);
    
    if(a > b) 
    {
        temp = a; 
	a = b; 
	b = temp;
    }
    if(a > c)
    {
        temp = a; 
	a = c; 
	c = temp;
    }
    if(b > c)
    {
        temp = b;
	 b = c; 
	c = temp;
    }
    printf("Tang dan: %d %d %d ",a, b, c);
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
    return 0;
}
