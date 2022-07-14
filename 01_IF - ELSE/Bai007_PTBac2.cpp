Giải phương trình bậc 2 có dạng: a𝑥2 + bx + c = 0

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
int main() {
	long long a, b, c;
	float x1, x2;
	
	scanf("%lld%lld%lld", &a, &b, &c);
	
	if (a == 0) {		// ---- phương trình có dạng bx+c=0
		if (b == 0) {
			if (c == 0) {
				printf("INF");
			}
			else {
				printf("NO");
			}
		}
		else if (b > 0)
		{
			printf("%.2lf", (double)(-c) / b);
		}
		else if (b < 0)
		{
			if (c == 0)
			{
				b = fabs(b);
				printf("%.2lf", (double)(-c) / b);
			}
			else if (c != 0)
			{
				printf("%.2lf", (double)(-c) / b);
			}
		}
	}
	else if(a!=0) {
		long long denta = b * b - 4 * a * c;
		if (denta < 0) {
			printf("NO");
		}
		else if (denta == 0) {
			printf("%.2lf", (double)-b / (2 * a));
		}
		else {
			x1 = (-b + sqrt(denta)) / (2 * a);
			x2 = (-b - sqrt(denta)) / (2 * a);
			if (x1 == -0 ) {
				x1 = 0;
			}
			if (x1 < x2) {
				printf("%.2lf %.2lf", x1, x2);
			}
			else printf("%.2lf %.2lf", x2, x1);
		}
	}
	return 0;
}
