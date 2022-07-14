Giải phương trình 𝑎𝑥^4 + 𝑏𝑥^2 + 𝑐 = 0.(1)
/*
phương trình: 2x4 + 3x2 – 2 = 0
Đặt x2 = t, t ≥ 0.
(1) trở thành: 2t2 + 3t – 2 = 0 (2)

-> t1 = -2 < 0 nên loại.
-> t2 = 1/2.

-> x1 = 0.7071
-> x2 = -0.7071

- không được do-while ở chỗ nhập xuất các phần tử của phương trình vì phương trình sẽ có số âm.

*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
int main() {
hoang:
	float a, b, c;
	printf("Nhap a,b,c: ");
	scanf("%f%f%f", &a, &b, &c);
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
				printf("Phuong trinh co nghiem: x1= %.3f, x2= %.3f", x1, x2);
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
				printf("\nPhuong trinh co nghiem\nx1 = %.3f\nx2 = %.3f", x1, x2);
			}
			if (t2 >= 0)
			{
				float x1 = sqrt(t2);
				float x2 = -x1;
				printf("\nPhuong trinh co nghiem\nx1 = %.3f\nx2 = %.3f", x1, x2);
			}
		}
		else if (Denta == 0)
		{
			float t = -b / (2 * a);
			if (t >= 0)
			{
				float x1 = sqrt(t);
				float x2 = -x1;
				printf("\nPhuong trinh co nghiem\nx1 = %.3f\nx2 = %.3f", x1, x2);
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
	printf("\n\nBan co muon tiep tuc hay khong?\n(Bam phim c de tiep tuc, bam phim bat ki de thoat.)\n");
	char lc = getch();
	if(lc == 'c' || lc == 'C'){
		goto hoang;
	}
	return 0;
}
