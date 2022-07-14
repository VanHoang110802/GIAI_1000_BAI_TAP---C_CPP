Dạng của hệ phương trình bậc nhất 2 ẩn như sau:
ax + by = c
dx + ey = f
Trong đó:
+ a, b, c, d, e, f là các hệ số do người dung nhập vào
+ x & y là nghiệm cần tính
- Yêu cầu: Giải hệ phương trình trên.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
int main() {
	// xét qua đề bài, ta sẽ dùng phương pháp cramer để giải thay cho phép thế.
	/*
	  - Vì phép thế sẽ rất dài và dễ rối nên ta sẽ dùng định thức cramer cho ngắn gọn, dễ hiểu:
		(công thức đã được chững minh rồi nên ta không cần phải đi chứng minh lại)
	  - Giải thuật: 
	  - Định thức cramer:
			ax + by = c
			dx + ey = f

		 D = |a   b| = a.e - d.b
		     |d   e|

		Dx = |c   b| = c.b - f.e
		     |f   e|

		Dy = |a   c| = a.f - d.c
		     |d   f|

		x = Dx / D
		y = Dy / D

	Nếu định thức D = 0 thì phương trình hoặc vô nghiệm hoặc vô số nghiệm. 
	Nếu Dx + Dy = 0 thì phương trình có vô số nghiệm. 
	Ngược lại thì phương trình trên vô nghiệm.
	Nếu định thức D ≠ 0 thì hệ phương trình trên luôn có nghiệm duy nhất với x = Dx/D và y = Dy/D.

	*/
	int a, b, c, d, e, f;
	printf("nhap a,b,c,d,e,f: ");
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	double D, Dx, Dy, x, y;
	D = (a*e) - (d*b);
	Dx = (c * e) - (f * b);
	Dy = (a * f) - (d * c);
	if (D == 0) {
		if (Dx + Dy == 0) {
			printf("Phuong trinh co vo so nghiem");
		}
		else {
			printf("Phuong trinh vo nghiem");
		}
		
		return 0;
	} else{
		x = Dx / D;
		y = Dy / D;
		printf("Phuong trinh co nghiem: \nx= %lf\ny=%lf",x,y);
	}
	return 0;
}
