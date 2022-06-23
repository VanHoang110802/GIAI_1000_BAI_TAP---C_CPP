Bạn lại được ra 1 nhiệm vụ dễ dàng : Cho số nguyên n phân tích n thành thừa số nguyên tố.

Lưu ý: Kết quả gồm nhiều dòng mỗi dòng gồm 2 số nguyên dương. Số đầu tiên là thừa số nguyên tố p, số thứ hai là số mũ của p trong phân tích thừa số nguyên tố của n.
Chú ý cần sắp xếp các thừa số nguyên tố tăng dần theo thứ tự từ trên xuống.

input: 12	-> output: 2 2	
			   3 1

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<time.h>
int main() {
    clock_t start = clock(); //ghi lại thời gian lúc sau
    long long n;
    scanf("%lld", &n);
    for (long long i = 2; i <= n; i++) {
        int dem = 0;
        while (n % i == 0) {
            ++dem;
            n /= i;
        }
        if (dem != 0) {
            printf("%lld %d\n", i, dem);
        }
    }
    clock_t end = clock();
    double timerun = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n%lf", timerun);
	return 0;
}
