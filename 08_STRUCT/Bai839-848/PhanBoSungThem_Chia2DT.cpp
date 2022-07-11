/*

ACCEPTED: 5/6 Test.	TIMERUN: 0.96ms
-----------------------------------------------------------------------
Test: (2x4 – 3x3 – 3x2 – 2 + 6x) : (x2 – 2) = 2x2 – 3x + 1

KET QUA DAU RA: Thuong da thuc: [ 2 -3 1 ]
--> THANH CONG
-----------------------------------------------------------------------
Test: (-2x5 + 3x2 – 4x3) : 2x2 = -1x^3 + 3/2 – 2x^1. 

KET QUA DAU RA: Thuong da thuc: [ 1.5 -2 -1]
--> THANH CONG
-----------------------------------------------------------------------
Test: (x3 – 7x + 3 – x2) : (x – 3) = x2  + 2x  – 1

KET QUA DAU RA: Thuong da thuc: [ 1 2 -1 ]
--> THANH CONG
-----------------------------------------------------------------------
Test: (-1 + x3) : (1 + x + x2) = -1 + x

KET QUA DAU RA: Thuong da thuc: [ -1 1 ]
--> THANH CONG
-----------------------------------------------------------------------
Test: (7x3 - 7x + 42 ):(x2 - 2x + 3) = 7x + 14

KET QUA DAU RA: sai
--> THAT BAI
-----------------------------------------------------------------------
Test: (10x2 – 7x - 12): (2x – 3) = 5x + 4

KET QUA DAU RA: Thuong da thuc: [ 4 5 ]
--> THANH CONG
-----------------------------------------------------------------------

*/
/* -------------------- SỬ DỤNG "vector" -------------------- */
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

/* -------------------- SỬ DỤNG "pointer" -------------------- */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct DaThuc
{
	float* heso;
	int sobac;
};
typedef struct DaThuc DATHUC;
typedef float* Poly;

void NhapDaThuc(DATHUC* dt)
{
	do
	{
		cout << "Nhap bac cua da thuc: ";
		cin >> dt->sobac;
		if (dt->sobac < 1)
		{
			cout << "\nSo bac cua da thuc phai lon hon 1, xin hay kiem tra lai!\n";
		}
	} while (dt->sobac < 1);
	dt->heso = new float[dt->sobac + 1];

	for (int i = 0; i <= dt->sobac; ++i)
	{
		cout << "Nhap he so co bac " << i << ": ";
		cin >> dt->heso[i];
	}
}


void XuatDaThuc(string name, Poly A, int qd)
{
	cout << name << " ";
	for (int i = 0; i < qd - 1; ++i)
	{
		cout << A[i] << "x^" << i << " + ";
	}
	cout << A[qd - 1] << "x^" << qd - 1;
	cout << "\n";
}

int main()
{
	
	Poly HeSoDaThuc1, HeSoDaThuc2, d, q, r;        // vectors - N / D == q && N % D == r
	int SoBacdathuc1, SoBacdathuc2, dd, dq, dr; // degrees of vectors
	int i;                  // loop counter
	DATHUC* dt1 = new DATHUC;
	DATHUC* dt2 = new DATHUC;

	NhapDaThuc(dt1);
	NhapDaThuc(dt2);

	SoBacdathuc1 = dt1->sobac;
	SoBacdathuc2 = dt2->sobac;

	dq = SoBacdathuc1 - SoBacdathuc2;	// dq = 3
	dr = SoBacdathuc1 - SoBacdathuc2;

	if (SoBacdathuc2 < 1 || SoBacdathuc1 < 1)
	{
		cerr << "He so bac cua da thuc khong duoc am, hay kiem tra lai!\n";
		return 1;
	}

	HeSoDaThuc1 = new float [SoBacdathuc1 + 1];
	
	for (i = 0; i <= SoBacdathuc1; i++)
	{
		HeSoDaThuc1[i] = dt1->heso[i];
	}
	
	HeSoDaThuc2 = new float [SoBacdathuc1 + 1];
	
	for (i = 0; i <= SoBacdathuc2; i++)
	{
		HeSoDaThuc2[i] = dt2->heso[i];
	}

	d = new float[SoBacdathuc1 + 1];
	q = new float[dq + 1];
	r = new float[dr + 1];
	cout << "\n\n";
	// khởi tạo cho các phần tử trong mảng = 0 hết
	fill(d, d + SoBacdathuc1 + 1, 0);	
	fill(q, q + dq + 1, 0);
	fill(r, r + dr + 1, 0);
	if (SoBacdathuc1 >= SoBacdathuc2)
	{
		while (SoBacdathuc1 >= SoBacdathuc2)
		{
			// khởi tạo lại 1 lần nữa để tránh lỗi tràn số
			fill(d, d + 1, 0);
			fill(q, q + 1, 0);

			for (i = 0; i <= SoBacdathuc2; i++)
			{
				d[i + (SoBacdathuc1 - SoBacdathuc2)] = HeSoDaThuc2[i];
			}
			XuatDaThuc("d", d, SoBacdathuc1 + 1);
			dd = SoBacdathuc1;

			
			q[SoBacdathuc1 - SoBacdathuc2] = HeSoDaThuc1[SoBacdathuc1] / d[dd];

			XuatDaThuc("q", q, dq + 1);
			// d = d * q[dN-dD]
			for (i = 0; i < dq + 1; i++)
			{
				d[i] = d[i] * q[SoBacdathuc1 - SoBacdathuc2];
			}
			XuatDaThuc("d", d, SoBacdathuc1 + 1);
			// N = N - d
			for (i = 0; i < SoBacdathuc1 + 1; i++)
			{
				HeSoDaThuc1[i] = HeSoDaThuc1[i] - d[i];
			}

			SoBacdathuc1--;
			XuatDaThuc("N", HeSoDaThuc1, SoBacdathuc2 +1);
		}
	}

	// r = N 
	for (i = 0; i <= SoBacdathuc1; i++)
	{
		r[i] = HeSoDaThuc1[i];
	}

	cout << "=========================" << endl << endl;

	XuatDaThuc("Thuong da thuc: ", q, dq + 1);
	XuatDaThuc("Du cua da thuc: ", r, dr + 1);
	delete dt1;
	delete dt2;
	delete[] HeSoDaThuc1;
	delete[] HeSoDaThuc2;
	delete[] d;
	delete[] q;
	delete[] r;
	return 0;
}

/*--------------------------------------------------------------------------------------------------*/

