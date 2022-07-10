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
	cout << "\n\n";
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
