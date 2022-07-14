Giải phương trình bậc 4 có dạng: ax^4 + bx^2 + c = 0.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main() {
	double a, b, c;
	printf("Nhap a,b,c: ");
	scanf("%lf%lf%lf", &a, &b, &c);
	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				printf("Phuong trinh co vo so nghiem");
			}
			else {
				printf("Phuong trinh vo nghiem");
			}
		}
		else {
			float t = -c / b;
			if (t < 0) {
				printf("phuong trinh vo nghiem");
			}
			else {
				float x1 = sqrt(t);
				float x2 = -x1;
				printf("Phuong trinh co nghiem: x1= %f, x2= %f", x1, x2);
			}
		}
	}
	else
	{
		float Denta = b * b - 4 * a * c;

		if (Denta > 0)
		{
			float t1 = (-b + sqrt(Denta)) / (2 * a);
			float t2 = (-b - sqrt(Denta)) / (2 * a);

			if (t1 < 0 && t2 < 0)
			{
				printf("\nPhuong trinh vo nghiem");
			}

			if (t1 >= 0)
			{
				float x1 = sqrt(t1);
				float x2 = -x1;
				printf("\nPhuong trinh co nghiem\nx1 = %f\nx2 = %f", x1, x2);
			}
			if (t2 >= 0)
			{
				float x1 = sqrt(t2);
				float x2 = -x1;
				printf("\nPhuong trinh co nghiem\nx1 = %f\nx2 = %f", x1, x2);
			}
		}
		else if (Denta == 0)
		{
			float t = -b / (2 * a);
			if (t >= 0)
			{
				float x1 = sqrt(t);
				float x2 = -x1;
				printf("\nPhuong trinh co nghiem\nx1 = %f\nx2 = %f", x1, x2);
			}
			else
			{
				printf("\nPhuong trinh vo nghiem");
			}
		}
		else 
		{
			printf("\nPhuong trinh vo nghiem");
		}
	}
	return 0;
}
