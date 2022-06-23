Cho một dãy n số nguyên a1, a2, ..., an. Hãy tìm hai chỉ số i, j sao cho i < j và hiệu aj - ai là lớn nhất.
Dữ liệu vào: gồm 2 dòng
-  Dòng 1: là số nguyên n (2 ≤ n ≤ 105)       
-  Dòng 2: gồm n số nguyên a1, a2, ..., an (0 ≤ ai ≤ 109)
Dữ liệu xuất:
- Là giá trị lớn nhất của hiệu aj - ai.
input		-> output: 2
3
1 2 3

input		-> output: 3
4
2 5 1 3

#include <stdio.h>
void NhapMang(long long a[], long long n)
{
	long long i;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);	
	}
}

int main()
{
	long long n, a[100000];
	scanf("%lld", &n);
	NhapMang(a,n);
	long long max = 0;
	long long i, j;
	for(i = 0 ; i < n; i++)
	{
		for( j = i + 1; j < n; j++)
		{
			if(a[j] - a[i] < 0 )
			{
				break;
			}
			if(a[j] - a[i] > max)
			{
				max = (a[j] - a[i]);
			}
		}
	}
	printf("%lld",max);
	return 0;
}
