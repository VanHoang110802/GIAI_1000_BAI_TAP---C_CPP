#include <iostream>
#include <iterator>
#include <vector>
#include <string>
using namespace std;
typedef vector<float> Poly;

void XuatDaThuc(string name, const Poly& A)
{
	cout << name << " ";
	for (int i = 0; i < A.size() - 1; ++i)
	{
		cout << A[i] << "x^" << i << " + ";
	}
	cout << A[A.size() - 1] << "x^" << A.size()-1;
	cout << "\n";
}

int main() 
{
	Poly HeSoDaThuc1, HeSoDaThuc2, d, q, r;        // vectors - N / D == q && N % D == r
	int SoBacdathuc1, SoBacdathuc2, dd, dq, dr; 
	int i;
	
	cout << "Nhap he so bac cua da thuc 1: ";
	cin >> SoBacdathuc1;
	cout << "Nhap he so bac cua da thuc 2: ";
	cin >> SoBacdathuc2;
	dq = SoBacdathuc1 - SoBacdathuc2;	// dq = 3
	dr = SoBacdathuc1 - SoBacdathuc2;

	if (SoBacdathuc2 < 1 || SoBacdathuc1 < 1)
	{
		cerr << "He so bac cua da thuc khong duoc am, hay kiem tra lai!\n";
		return 1;
	}

	HeSoDaThuc1.resize(SoBacdathuc1 + 1);
	cout << "Nhap vao cac he so cho da thuc 1:" << endl;
	for (i = 0; i <= SoBacdathuc1; i++)
	{
		cout << "He so co bac " << i << " = ";
		cin >> HeSoDaThuc1[i];
	}

	HeSoDaThuc2.resize(SoBacdathuc1 + 1);
	cout << "Nhap vao cac he so cho da thuc 2:" << endl;
	for (i = 0; i <= SoBacdathuc2; i++)
	{
		cout << "He so co bac " << i << " = ";
		cin >> HeSoDaThuc2[i];
	}

	d.resize(SoBacdathuc1 + 1);
	q.resize(dq + 1);
	r.resize(dr + 1);

	if (SoBacdathuc1 >= SoBacdathuc2)
	{
		while (SoBacdathuc1 >= SoBacdathuc2)
		{
			// d = D, bắt đầu đi xét từ phải sang
			d.assign(d.size(), 0);

			for (i = 0; i <= SoBacdathuc2; i++)
			{
				d[i + SoBacdathuc1 - SoBacdathuc2] = HeSoDaThuc2[i];
			}
				
			dd = SoBacdathuc1;
			

			// tính toán 1 phần tử của q
			q[SoBacdathuc1 - SoBacdathuc2] = HeSoDaThuc1[SoBacdathuc1] / d[dd];


			// d = d * q[dN-dD]
			for (i = 0; i < dq + 1; i++)
			{
				d[i] = d[i] * q[SoBacdathuc1 - SoBacdathuc2];
			}
				
			// N = N - d
			for (i = 0; i < SoBacdathuc1 + 1; i++)
			{
				HeSoDaThuc1[i] = HeSoDaThuc1[i] - d[i];
			}
				
			SoBacdathuc1--;

		}
	}

	// r = N 
	for (i = 0; i <= SoBacdathuc1; i++)
	{
		r[i] = HeSoDaThuc1[i];
	}

	cout << "=========================" << endl << endl;
	
	XuatDaThuc("Thuong da thuc: ", q);
	XuatDaThuc("Du cua da thuc: ", r);
	return 0;
}
