#include "DaThuc.h"

void NhapDaThuc(DATHUC *dt)
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
void XuatDaThuc(DATHUC* dt)
{
	if (dt->sobac == 1)
	{
		cout << dt->heso[1] << "*x" << " + ";
		cout << dt->heso[0];
	}
	else
	{
		for (int i = dt->sobac; i >= 1 ; --i)
		{
			cout << dt->heso[i] << "*x^" << i << " + ";
		}
		cout << dt->heso[0];
	}
}
void Xuat(string name, Poly A, int qd)
{
	cout << name << " ";
	for (int i = 0; i < qd - 1; ++i)
	{
		cout << A[i] << "x^" << i << " + ";
	}
	cout << A[qd - 1] << "x^" << qd - 1;
	cout << "\n";
}
void* TinhTong2DT(DATHUC *X, DATHUC *Y)
{
	int Max = X->sobac > Y->sobac ? X->sobac : Y->sobac;
	int Min = X->sobac < Y->sobac ? X->sobac : Y->sobac;
	DATHUC* Kq = new DATHUC;
	Kq->sobac = Max;
	Kq->heso = new float[Kq->sobac + 1];
	for (int i = 0; i <= Min; ++i)
	{
		Kq->heso[i] = X->heso[i] + Y->heso[i];
	}
	if (Max == X->sobac)
	{
		for (int i = Min + 1; i <= Max; ++i)
		{
			Kq->heso[i] = X->heso[i];
		}
	}
	else
	{
		for (int i = Min + 1; i <= Max; ++i)
		{
			Kq->heso[i] = Y->heso[i];
		}
	}
	XuatDaThuc(Kq);
	delete Kq;
	return NULL;
}
void* TinhHieu2DT(DATHUC* G, DATHUC* H)
{
	int Max = G->sobac > H->sobac ? G->sobac : H->sobac;
	int Min = G->sobac < H->sobac ? G->sobac : H->sobac;
	DATHUC* Kq = new DATHUC;
	Kq->sobac = Max;
	Kq->heso = new float[Kq->sobac + 1];
	for (int i = 0; i <= Min; ++i)
	{
		Kq->heso[i] = G->heso[i] - H->heso[i];
	}
	if (Max == G->sobac)
	{
		for (int i = Min + 1; i <= Max; ++i)
		{
			Kq->heso[i] = G->heso[i];
		}
	}
	else
	{
		for (int i = Min + 1; i <= Max; ++i)
		{
			Kq->heso[i] = H->heso[i];
		}
	}
	XuatDaThuc(Kq);
	delete Kq;
	return NULL;
}

void* TinhTich2DT(DATHUC* A, DATHUC* B)
{
	DATHUC* Kq = new DATHUC;
	Kq->sobac = A->sobac + B->sobac;
	Kq->heso = new float[Kq->sobac + 1];
	/*
	fill chức năng trong này là gán tất cả heso=0. Khi nhân 2 đa thức aixi * bjxj = ai*bjxi+j . 
	
	Kết quả của phép nhân là tổng của biểu thức trên nên kết quả kq->heso[i+j] = sum(x->heso[i]*y->heso[j])
	*/
	fill(Kq->heso, Kq->heso + Kq->sobac + 1, 0.0);
	for (int i = 0; i <= A->sobac; i++)
	{
		for (int j = 0; j <= B->sobac; j++)
		{
			Kq->heso[i + j] += A->heso[i] * B->heso[j];
		}
	}
	XuatDaThuc(Kq);
	delete Kq;
	return NULL;
}
void* TinhThuong2DT(DATHUC* dt1, DATHUC* dt2)
{
	Poly HeSoDaThuc1, HeSoDaThuc2, d, q, r;        // vectors - N / D == q && N % D == r
	int SoBacdathuc1, SoBacdathuc2, dd, dq, dr; // degrees of vectors
	int i;                  // loop counter
	
	SoBacdathuc1 = dt1->sobac;
	SoBacdathuc2 = dt2->sobac;

	dq = SoBacdathuc1 - SoBacdathuc2;	// dq = 3
	dr = SoBacdathuc1 - SoBacdathuc2;

	if (SoBacdathuc2 < 1 || SoBacdathuc1 < 1)
	{
		cerr << "He so bac cua da thuc khong duoc am, hay kiem tra lai!\n";
		return 0;
	}

	HeSoDaThuc1 = new float[SoBacdathuc1 + 1];

	for (i = 0; i <= SoBacdathuc1; i++)
	{
		HeSoDaThuc1[i] = dt1->heso[i];
	}

	HeSoDaThuc2 = new float[SoBacdathuc1 + 1];

	for (i = 0; i <= SoBacdathuc2; i++)
	{
		HeSoDaThuc2[i] = dt2->heso[i];
	}

	d = new float[SoBacdathuc1 + 1];
	q = new float[dq + 1];
	r = new float[dr + 1];
	cout << "\n";
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
			
			dd = SoBacdathuc1;


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

	Xuat("Thuong cua 2 da thuc: ", q, dq + 1);
	Xuat("Du cua 2 da thuc: ", r, dr + 1);

	delete[] HeSoDaThuc1;
	delete[] HeSoDaThuc2;
	delete[] d;
	delete[] q;
	delete[] r;
}
/*
Nếu mà muốn tính đạo hàm cấp 1 cho đa thức, thì đổi DATHUC* -> void* nhé 

*/
DATHUC* TinhDaoHamCap1(DATHUC *dt)
{
	DATHUC* ketqua = new DATHUC;

	// bậc của đa thức kết quả
	ketqua->sobac = dt->sobac - 1;
	ketqua->heso = new float[ketqua->sobac + 1];
	// hệ số của đa thức kết quả
	for (int i = dt->sobac; i >= 1; i--)
	{
		ketqua->heso[i - 1] = dt->heso[i] * i;
	}
	//XuatDaThuc(ketqua);
	//delete ketqua;
	return ketqua;
}
void* TinhDaoHamCapk(DATHUC *dt, int k)
{
	DATHUC* ketqua = dt;
	//ketqua->sobac = dt->sobac;
	//ketqua->heso = new float[ketqua->sobac + 1];
	for (int i = 0; i < k; i++)
	{
		ketqua = TinhDaoHamCap1(ketqua);
	}
	XuatDaThuc(ketqua);
	delete ketqua;
	return NULL;
}
float TinhGiaTriX(DATHUC *dt, float x0)
{
	float kq = 0;

	for (int i = dt->sobac; i >= 0; i--)
	{
		kq = kq + dt->heso[i] * pow(x0, i);
	}
	return kq;
}
