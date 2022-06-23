Dân gian Việt Nam có một câu đố:

    Vừa gà vừa chó
    Bó lại cho tròn
    Ba mươi sáu con
    Một trăm chân chẵn

Sau khi giải được bài tập trên với số gà là 22 và số chó là 14, bạn Nam thắc mắc không biết trong trường hợp tổng quát với n con (vừa gà vừa chó) và m chân thì sẽ giải như thế nào. Bạn hãy giúp bạn Nam nhé.
Dữ liệu nhập:
- Là hai số nguyên n, m cách nhau một khoảng trắng (0 ≤ n, m ≤ 10^6)
Dữ liệu xuất:
- Nếu có đáp án, in ra hai số nguyên g và c thể hiện số gà và số chó, hai số cách nhau một khoảng trắng.
- Nếu không có đáp án, in ra -1.
(Chú ý đáp án cho phép chỉ có gà hoặc chỉ có chó, không nhất thiết phải có cả hai con)
input: 36 100 -> output: 22 14
input: 10 10 -> output: -1

#include <stdio.h>
int main()
{
	float t,n;
	scanf("%f%f",&t,&n);
	float x = (4*t - n ) / 2;
	float y = t - x;
	if(x < 0 || y < 0 || x != (int)x || y != (int)y)
	{
		printf("-1");
	} 
	else 
	{
		printf("%.f %.f", x,y);
	}
	return 0;
}
