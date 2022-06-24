/*	BÀI TẬP THỰC HÀNH MÔN KỸ THUẬT LẬP TRÌNH	*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>

// ========================================== Bài 1 =========================================== 
void NhapDuLieuBai1(int &a,int &b)
{
	do
	{
		printf("Nhap chieu dai: ");
		scanf("%d",&a);
		if(a<0)
		{
			printf("\nSo lieu nhap khong duoc am! Xin hay kiem trai lai!\n");
		}
	}while(a<0);
	do
	{
		printf("\nNhap chieu rong: ");
		scanf("%d",&b);
		if(b<0)
		{
			printf("\nSo lieu nhap khong duoc am! Xin hay kiem trai lai!\n");
		}
	}while(b<0);
}

void YeuCauBai1(int a, int b)
{
	int dientich,chuvi;
	dientich=a*b;
	chuvi=(a+b)*2;
	printf("\nChu vi hinh chu nhat: %d",chuvi);
	printf("\nDdien tich hinh chu nhat: %d",dientich);
}

void ThucHienBai1()
{
	int a,b;
	printf("\n==================== Bai 1 ====================\n");
	NhapDuLieuBai1(a,b);
	YeuCauBai1(a,b);
}

// ========================================== Bài 2 =========================================== 
void NhapDuLieuBai2(int &a)
{
	do
	{
		printf("Nhap canh: ");
		scanf("%d",&a);
		if(a<0)
		{
			printf("\nCanh khong duoc am! Xin hay kiem tra lai!\n");
		}
	}while(a<0);
}

void YeuCauBai2(float a)
{
	float duongcheo,chuvi,dientich;
	chuvi=4*a;
	dientich=a*a;
	duongcheo=sqrt(2* sqrt(a) * sqrt(a));
	printf("\nChu vi hinh vuong: %.2f",chuvi);
	printf("\nDien tich hinh vuong: %.2f",dientich);
	printf("\nDuong cheo: %.f",duongcheo);
}

void ThucHienBai2()
{
	int a;
	printf("\n==================== Bai 2 ====================\n");
	NhapDuLieuBai2(a);
	YeuCauBai2(a);
}

// ========================================== Bài 3 =========================================== 
void NhapDuLieuBai3(int &a,int &b)
{
	do
	{
		printf("Nhap so A: ");
		scanf("%d",&a);
		if(a<0)
		{
			printf("\nSo nhap khong hop le! Xin hay kiem tra lai!\n");
		}
	}while(a<0);
	do
	{
		printf("Nhap so B: ");
		scanf("%d",&b);
		if(b<0)
		{
			printf("\nSo nhap khong hop le! Xin hay kiem tra lai!\n");
		}
	}while(b<0);
}

void YeuCauBai3(int a,int b)
{
	int UCLN;
	int BCNN;
	int tich;
	tich=a*b;
	if(a==0&&b!=0)
	{
		UCLN=b;
	}
	if(b==0&&a!=0)
	{
		UCLN=a;
	}
	if(a!=0&&b!=0)
	{
		while(a!=b)
		{
			if(a>b)
			{
				a=a-b;
			}
			else
			{
				b=b-a;
			}
		}
		UCLN=a;
	}
	printf("\nUCLN: %d",UCLN);
	BCNN=tich/UCLN;
	printf("\nBCNN: %d",BCNN);
}

void ThucHienBai3()
{
	int a,b;
	printf("\n==================== Bai 3 ==================== \n");
	NhapDuLieuBai3(a,b);
	YeuCauBai3(a,b);
}

// ========================================== Bài 4 =========================================== 
void NhapDuLieuBai4(float a[])
{
	for(int i=0;i<3;i++)
	{
		printf("NHAP a[%d]: ",i);
		scanf("%f",&a[i]);
	}
}


void SapTangDan(float a[])
{
	int i,j;
	printf("\n>>>>>>>>>>>>>>> Sap Tang Dan <<<<<<<<<<<<<<<<<<\n");
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<3;j++)
		{
			if(a[i]>a[j])
			{
				float temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		printf("%.2f ",a[i],a[j]);
	}
}

void SapGiamDan(float a[])
{
	int i,j;
	printf("\n>>>>>>>>>>>>>>> Sap Giam Dan <<<<<<<<<<<<<<<<<<\n");
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<3;j++)
		{
			if(a[i]<a[j])
			{
				float temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		printf("%.2f",a[i],a[j]);
	}
}

void ThucHienBai4()
{
	float a[3];
	printf("\n==================== Bai 4 ====================\n");
	NhapDuLieuBai4(a);
	SapTangDan(a);
	SapGiamDan(a);
}

// ========================================== Bài 5 =========================================== 
void NhapDuLieuBai5(int &a,int &b,int &c)
{
	do
	{
		printf("Nhap canh A: ");
		scanf("%d",&a);
		if(a<1)
		{
			printf("\nCanh A nhap khong hop le! Xin hay kiem tra lai!\n");
		}
	}while(a<1);
	do
	{
		printf("Nhap canh B: ");
		scanf("%d",&b);
		if(b<1)
		{
			printf("\nCanh B nhap khong hop le! Xin hay kiem tra lai!\n");
		}
	}while(b<1);
	do
	{
		printf("\nCanh C nhap khong hop le! Xin hay kiem tra lai!\n");
		scanf("%d",&c);
		if(c<1)
		{
			printf("\nCanh C nhap khong hop le! Xin hay kiem tra lai!\n");
		}
	}while(c<1);
}

void YeuCauBai5(int a,int b,int c)
{
	if(a==b)
	{
		if(b==c)
		{
			printf("tam giac deu");
		}
		else
		{
			printf("TAM GIAC CAN");
		}
	}
	if(a==c)
	{
		if(b==c)
		{
			printf("tam giac deu");
		}
		else
		{
			printf("TAM GIAC CAN");
		}
	}
	if(b==c)
	{
		if(a==c)
		{
			printf("tam giac deu");
		}
		else
		{
			printf("TAM GIAC CAN");
		}
	}
	if((a*a+b*b>c*c)||(a*a+c*c>b*b)||(b*b+c*c>a*a))
	{
		if((a*a+b*b==c*c)||(a*a+c*c==b*b)||(b*b+c*c==a*a))
		{
			if((a==b)||(a==c)||(b==c))
			{
				printf("tam giac vuong can");
			}
			else
			{
				printf("TAM GIAC VUONG");
			}
		}
		if(!((a*a+b*b==c*c)||(a*a+c*c==b*b)||(b*b+c*c==a*a)||(a==b)||(a==c)||(b==c)))
		{
			printf("TAM GIAC THUONG");
		}
	}
}

void ThucHienBai5()
{
	int a,b,c;
	printf("\n==================== Bai 5 ====================\n");
	NhapDuLieuBai5(a,b,c);
	YeuCauBai5(a,b,c);
}

// ========================================== Bài 6 =========================================== 
void NhapDuLieuBai6(int &a,int &b,int &c,int &d,int &e)
{
	printf("NHAP A:");
	scanf("%d",&a);
	printf("NHAP B:");
	scanf("%d",&b);
	printf("NHAP C:");
	scanf("%d",&c);
	printf("NHAP D:");
	scanf("%d",&d);
	printf("NHAP E:");
	scanf("%d",&e);
}

void YeuCauBai6(int a,int b,int c,int d,int e)
{
	float TBC;
	TBC=float(a+b+c+d+e)/5;
	printf("Trung Binh Cong: %.2f",TBC);
}

void ThucHienBai6()
{
	int a,b,c,d,e;
	printf("\n==================== Bai 6 ====================\n");
	NhapDuLieuBai6(a,b,c,d,e);
	YeuCauBai6(a,b,c,d,e);
}

// ========================================== Bài 7 =========================================== 
void NhapDuLieuBai7(float &n)
{
	do
	{
		printf("NHAP N: ");
		scanf("%f",&n);
		if(n<1)
		{
			printf("nhap lai");
		}
	}while(n<1);
}

// Hàm tính S1 .
void S1(float n)
{
	float S1=0;
	for(int i=0;i<=n;i++)
	{
		S1=S1+i;
	}
	printf("\nS1= %.2f\n",S1);
}

// Hàm tính S2 .
void S2(float n)
{
	float S2=1;
	for(int i=1;i<=n;i++)
	{
		S2=S2*i;
	}
	printf("\nS2= %.2f\n",S2);
}

// Hàm tính S3 .
void S3(float n)
{
	float S3=0;
	for(int i=1;i<=n;i++)
	{
		S3=S3+float (1)/i;
	}
	printf("\nS3= %.2f\n",S3);
}

// Hàm tính S4 .
void S4(float n)
{
	float S4=0;
	//float pow(float x,float y);
	for(int i=1;i<=n;i++)
	{
		S4=S4+pow(i,2);
	}
	printf("\nS4= %.2f\n",S4);
}

void ThucHienBai7()
{
	float n;
	printf("\n==================== Bai 7 ====================\n");
	NhapDuLieuBai7(n);
	S1(n);
	S2(n);
	S3(n);
	S4(n);
}

// ========================================== Bài 8 =========================================== 
void NhapDuLieuBai8(int &n)
{
	printf("NHAP N: ");
	scanf("%d",&n);
}

void KiemTraNT(int n)
{
	int f;
	f=1;
	if(n<2)
	{
		f=0;
	}
	for(int j=2;j<=n/2;j++)
	{
		if(n%j==0)
		{
			f=0;
		}
	}
	printf("\nSo %d co phai la so nguyen to ? ",n);
	if(f==1)
		printf("YES");	
	else
		printf("NO");
}

void KiemTraHT(int n)
{
	int tong=0;
	for(int i=1;i<n;i++)
	{
		if(n%i==0)
		{
			tong+=i;
		}
	}
	printf("\nSo %d co phai la so hoan thien ? ",n);
	if(tong==n)
		printf("YES");
	else
		printf("NO");
}

void KiemTraCP(int n)
{
	float ketqua=sqrt(n);
	printf("\nSo %d co phai la so chinh phuong ? ",n);
	if(ketqua==(int)ketqua)
		printf("YES");
	else
		printf("NO");
}

void ThucHienBai8()
{
	int n;
	printf("\n==================== Bai 8 ====================\n");
	NhapDuLieuBai8(n);
	KiemTraNT(n);
	KiemTraHT(n);
	KiemTraCP(n);
}


// ========================================== Bài 9 =========================================== 
void NhapDuLieuBai9(int &n)
{
	do
	{
		printf("Nhap so: ");
		scanf("%d",&n);
		if(n<0||n>10000)
		{
			printf("\nSo phai nam trong [0,10000]! Xin hay kiem tra lai!\n");
		}
	}while(n<0||n>10000);
}

void LietKeNT(int n)
{
	int dem=0;
	printf("\n>>>>>>>>>> Cac so nguyen to nam trong tu 0 -> %d: <<<<<<<<<<<<<<<\n",n);
	for(int i=2;i<=n;i++)
	{
		int f=1;
		for(int j=2;j<=i/2;j++)
		{
			if(i%j==0)
			{
				f=0;
			}
		}
		if(f==1)
		{
			dem++;
			if(dem<=n)
			{
				printf("%d  ",i);
			}
		}
	}
}

void LietKeCP(int n)
{
	int dem=0;
	//float sqrt(float x);
	printf("\n\n");
	printf("\n>>>>>>>>>> Cac so chinh phuong nam trong 0 -> %d: <<<<<<<<<<<<<<<\n",n);
	for(int i=0;i<=n;i++)
	{
		float kq=sqrt(i);
		if(kq==(int)kq)
		{
			dem++;
			if(dem<=n)
			{
				printf("%d  ",i);
			}
		}
	}

}

void LietKeChan(int n)
{
	int dem=0;
	printf("\n\n");
	printf("\n>>>>>>>>>> Cac so chan nam trong tu 0 -> %d: <<<<<<<<<<<<<<<\n",n);
	for(int i=0;i<=n;i++)
	{
		if(i%2==0)
		{
			dem++;
			if(dem<=n)
			{
				printf("%d  ",i);
			}
		}
	}
}

void ThucHienBai9()
{
	int n;
	printf("\n==================== Bai 9 ====================\n");
	NhapDuLieuBai9(n);
	LietKeNT(n);
	LietKeCP(n);
	LietKeChan(n);
}


// ========================================== Bài 10 =========================================== 
void LietKeTongChan(int &i)
{
	printf("\n>>>>>>>>>>>>>>>>>>> Cac So Thoa Yeu Cau La <<<<<<<<<<<<<<<<<<<<\n");
	for(i=100;i<=999;i++)
	{
		int temp=i;
		int tong=0;
		while(temp!=0)
		{
			tong+=temp%10;
			temp=temp/10;
		}
		if(tong%2==0)
		{
			printf("%d  ",i);
		}
	}
}

void ThucHienBai10()
{
	int i;
	printf("\n==================== Bai 10 ====================\n");
	LietKeTongChan(i);
}


// ========================================== Bài 11 =========================================== 
void XuLyDuLieu(int &n)
{
	printf("\n>>>>>>> Cac So Nho Hon 10 000 Va Co Tong Cac Chu So = Tich Cac Chu So <<<<<<<<<\n");
	printf("\n");
	for(n=0;n<10000;n++)
	{
		int temp=n;
		int tong=0;
		int tich=1;
		while(temp!=0)
		{
			tong+=temp%10;
			tich*=temp%10;
			temp/=10;
		}
		if(tong==tich)
		{
			printf("%d ",n);
		}		
	}
	printf("\n");
}

void ThucHienBai11()
{
	int n;
	printf("\n==================== Bai 11 ====================\n");
	XuLyDuLieu(n);
}


// ========================================== Bài 12 =========================================== 
void NhapDuLieuBai12(unsigned long &n)
{
	do{
		printf("\nNhap vao so nguyen N=");
		scanf("%lu",&n);
		if(n<100000)
		{
			printf("\nGia tri N khong hop le!Xin vui long nhap lai!\n");
		}
	}while(n<100000);
}

void PhuongAn(unsigned long n)
{
	unsigned long dem=0;
	unsigned long a,b,c;
	printf("-------------------------------------------------------------------------------------------\n");
	printf("\n------------------------");
	printf(" Cach Thu \t");
	printf("So To 10 000 \t");
	printf("So To 20 000 \t");
	printf("So To 50 000 \t");
	printf("\n------------------------ ");
	for(a=0;a<=n/10000;a++)
	{
		for(b=0;b<=n/20000;b++)
		{
			for(c=0;c<=n/50000;c++)
			{
				if(a*10000+b*20000+c*50000==n)
				{
					dem++;
					printf("%lu\t\t\t",dem);
					printf("%lu\t\t",a);
					printf("%lu\t\t",b);
					printf("%lu\t",c);
					printf("\n------------------------ ");
				}
			}
		}
	}
	printf("-------------------------------------------------------------------\n");
	printf("\nTong cong ta co %lu cach de tra %lu dong",dem,n);
}

void ThucHienBai12()
{
	unsigned long n;
	printf("\n==================== Bai 12 ====================\n");
	NhapDuLieuBai12(n);
	PhuongAn(n);
}


// ========================================== Bài 13 =========================================== 
void NhapDuLieuBai13(int &n)
{
	do
	{
		printf("\nNhap vao so giay:");
		scanf("%d",&n);
		if(n<0)
		{
			printf("\nSo giay khong hop le!Xin vui long nhap lai!\n");
		}
	}while(n<0);
}

void ChuyenDoi(int n)
{
	int gio,phut,giay;
	gio=n/3600;
	phut=(n-(gio*3600))/60;
	giay=n-(gio*3600+phut*60);
	printf("\nChuyen doi ra thanh: %d:%d:%d",gio,phut,giay);
}

void ThucHienBai13()
{
	int n;
	printf("\n==================== Bai 13 ====================\n");
	NhapDuLieuBai13(n);
	ChuyenDoi(n);
}

// ========================================== Bài 14 =========================================== 
void NhapDuLieuBai14(int &ngay,int & thang,int &nam)
{
	do
	{
		printf("\nNhap vao nam:");
		scanf("%d",&nam);
		if(nam<1)
		{
			printf("\nNam khong hop le!Xin vui long nhap lai!\n");
		}
	} while (nam<1);
	
	do
	{
		printf("\nNhap vao thang:");
		scanf("%d",&thang);
		if(thang<1||thang>12)
		{
			printf("\nThang khong hop le!Xin vui long nhap lai!\n");
			
		}
	} while (thang<1||thang>12);

hoang:
	printf("\nNhap vao ngay:");
	scanf("%d", &ngay);

	if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
	{
		if (ngay < 1 || ngay > 31)
		{
			printf("\nNgay khong hop le!Xin vui long nhap lai!\n");
			goto hoang;
		}
	}
	else if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
	{
		if (ngay < 1 || ngay > 30)
		{
			printf("\nNgay khong hop le!Xin vui long nhap lai!\n");
			goto hoang;
		}
	}
	// Năm nhuận => tháng 2 có 29 ngày .
	else if (nam % 400 == 0)
	{
		if (thang == 2)
		{
			if (ngay < 1 || ngay > 29)
			{
				printf("\nNgay khong hop le!Xin vui long nhap lai!\n");
				goto hoang;
			}
		}
	}
	// Năm không nhuận => tháng 2 có 28 ngày .
	else if (nam % 4 == 0 && nam % 100 != 0)
	{
		if (thang == 2)
		{
			if (ngay < 1 || ngay > 28)
			{
				printf("\nNgay khong hop le!Xin vui long nhap lai!\n");
				goto hoang;
			}
		}
	}
	
}

// Hàm xuất dữ liệu ngày-tháng-năm vừa nhập .
void XuatDuLieuBai14(int ngay,int thang,int nam)
{
	printf("\n-------------------- Du Lieu Ngay,Thang,Nam Vua Nhap --------------------\n");
	printf("\n");
	printf("\nNgay \t\t");
	printf("Thang \t\t");
	printf("Nam \t\t");
	printf("\n");
	printf("\n%d \t\t",ngay);
	printf("%d \t\t",thang);
	printf("%d \t\t",nam);
	printf("\n-------------------------------------------------------------------\n");
}

// Hàm xuất ra dữ liệu ngày-tháng-năm kế tiếp .
void KeTiep(int ngay,int thang,int nam)
{
	int ngayketiep,thangketiep,namketiep;
	if(thang==1||thang==3||thang==5||thang==7||thang==8||thang==10)
	{
		if(ngay>=1&&ngay<=30)
		{
			ngayketiep=ngay+1;
			thangketiep=thang;
			namketiep=nam;
		}
		else if(ngay==31)
		{
			ngayketiep=1;
			thangketiep=thang+1;
			namketiep=nam;
		}
	}
	else if(thang==12)
	{
		if(ngay>=1&&ngay<=30)
		{
			ngayketiep=ngay+1;
			thangketiep=thang;
			namketiep=nam;
		}
		else if(ngay==31)
		{
			ngayketiep=1;
			thangketiep=1;
			namketiep=nam+1;
		}
	}
	else if(thang==4||thang==6||thang==9||thang==11)
	{
		if(ngay>=1&&ngay<=29)
		{
			ngayketiep=ngay+1;
			thangketiep=thang;
			namketiep=nam;
		}
		else if(ngay==30)
		{
			ngayketiep=1;
			thangketiep=thang+1;
			namketiep=nam;
		}
	}
	else if(thang==2)
	{
		// Năm nhuận => tháng 2 có 29 ngày .
		if(nam%400==0)
		{
			if(ngay>=1&&ngay<=28)
			{
				ngayketiep=ngay+1;
				thangketiep=thang;
				namketiep=nam;
			}
			else if(ngay==29)
			{
				ngayketiep=1;
				thangketiep=thang+1;
				namketiep=nam;
			}
		}
		// Năm không nhuận => tháng 2 có 28 ngày .
		else if(nam%4!=0)
		{
			if(ngay>=1&&ngay<=27)
			{
				ngayketiep=ngay+1;
				thangketiep=thang;
				namketiep=nam;
			}
			else if(ngay==28)
			{
				ngayketiep=1;
				thangketiep=thang+1;
				namketiep=nam;
			}
		}
	}
	printf("\n==================== Du Lieu Ngay,Thang,Nam Ke Tiep ====================\n");
	printf("\n");
	printf("\nNgay \t\t");
	printf("Thang \t\t");
	printf("Nam \t\t");
	printf("\n");
	printf("\n%d \t\t",ngayketiep);
	printf("%d \t\t",thangketiep);
	printf("%d \t\t",namketiep);
	printf("\n-------------------------------------------------------------------\n");
}

// Hàm xuất ra dữ liệu ngày-tháng-năm trước đó .
void TruocDo(int ngay,int thang,int nam)
{
	int ngaytruocdo,thangtruocdo,namtruocdo;
	if(thang==2||thang==4||thang==6||thang==8||thang==9||thang==11)
	{
		if(ngay>=2)
		{
			ngaytruocdo=ngay-1;
			thangtruocdo=thang;
			namtruocdo=nam;
		}
		else if(ngay==1)
		{
			ngaytruocdo=31;
			thangtruocdo=thang-1;
			namtruocdo=nam;
		}
	}
	else if(thang==1)
	{
		if(ngay>=2)
		{
			ngaytruocdo=ngay-1;
			thangtruocdo=thang;
			namtruocdo=nam;
		}
		else if(ngay==1)
		{
			ngaytruocdo=31;
			thangtruocdo=12;
			namtruocdo=nam-1;
		}
	}
	else if(thang==5||thang==7||thang==10||thang==12)
	{
		if(ngay>=2)
		{
			ngaytruocdo=ngay-1;
			thangtruocdo=thang;
			namtruocdo=nam;
		}
		else if(ngay==1)
		{
			ngaytruocdo=30;
			thangtruocdo=thang-1;
			namtruocdo=nam;
		}
	}
	else if(thang==3)
	{
		if(ngay>=2)
		{
			ngaytruocdo=ngay-1;
			thangtruocdo=thang;
			namtruocdo=nam;
		}
		else if(ngay==1)
		{
			// Năm nhuận => tháng 2 có 29 ngày .
			if(nam%400==0)
			{
				ngaytruocdo=29;
				thangtruocdo=thang-1;
				namtruocdo=nam;
			}
			// Năm không nhuận => tháng 2 có 28 ngày .
			else if(nam%4!=0)
			{
				ngaytruocdo=28;
				thangtruocdo=thang-1;
				namtruocdo=nam;
			}
		}
	}
	printf("\n------------------> Du Lieu Ngay,Thang,Nam Truoc Do <------------------\n");
	printf("\n");
	printf("\nNgay \t\t");
	printf("Thang \t\t");
	printf("Nam \t\t");
	printf("\n");
	printf("\n%d \t\t",ngaytruocdo);
	printf("%d \t\t",thangtruocdo);
	printf("%d \t\t",namtruocdo);
	printf("\n-------------------------------------------------------------------\n");
}

void ThucHienBai14()
{
	int ngay,thang,nam;
	printf("\n==================== Bai 14 ====================\n");
	NhapDuLieuBai14(ngay,thang,nam);
	XuatDuLieuBai14(ngay,thang,nam);
	KeTiep(ngay,thang,nam);
	TruocDo(ngay,thang,nam);
}


// ========================================== Bài 15 =========================================== 
void NhapDuLieuBai15(int &n)
{
	do{
		printf("\nNhap vao thang:");
		scanf("%d",&n);
		if(n<1||n>12)
		{
			printf("\nThang ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		}
	}while(n<1||n>12);
}

void XuLyDuLieuBai15(int n)
{
	if(n==1||n==3||n==5||n==7||n==8||n==10||n==12)
	{
		printf("\nThang %d co 31 ngay",n);
	}
	else if(n==4||n==6||n==9||n==11)
	{
		printf("\nThang %d co 30 ngay",n);
	}
	else if(n==2)
	{
		printf("\nThang %d co 28 hoac 29 ngay",n);
	}
}

void ThucHienBai15()
{
	int n;
	printf("\n==================== Bai 15 ====================\n");
	NhapDuLieuBai15(n);
	XuLyDuLieuBai15(n);
}


// // ========================================== MENU =========================================== 
void MeNu()
{
	int luachon;
	while (1)
	{
		printf("\n------------------------- MeNu --------------------------\n");
		printf("\n01. Bai 1: Tinh dien tich, chu vi hinh chu nhat.");
		printf("\n02. Bai 2: Tinh dien tich, chu vi, duong cheo hinh vuong.");
		printf("\n03. Bai 3: Tim UCLN, BCNN 2 so.");
		printf("\n04. Bai 4: Sap xep day so tang/giam dan.");
		printf("\n05. Bai 5: Kiem tra ba canh co la tam giac?");
		printf("\n06. Bai 6: Tinh trung binh cong.");
		printf("\n07. Bai 7: Tinh tong.");
		printf("\n08. Bai 8: Kiem tra so.");
		printf("\n09. Bai 9: Liet ke cac so nam trong [0,n].");
		printf("\n10. Bai 10: Tinh tong chan.");
		printf("\n11. Bai 11: Cac so < 10000 va co tong chu so = tich cac chu so.");
		printf("\n12. Bai 12: Liet ke cac phuong an doi tien.");
		printf("\n13. Bai 13: Chuyen doi tu giay sang gio, phut.");
		printf("\n14. Bai 14: Tim ngay, thang, nam truoc do/ke tiep.");
		printf("\n15. Bai 15: Kiem tra thang co bao nhieu ngay.");
		printf("\n0.  Thoat Chuong Trinh ");
		printf("\n---------------------------------------------------------\n");
		printf("\n");
		printf("\nNhap Vao Lua Chon Cua Ban:");
		scanf("%d", &luachon);
		if (luachon == 1)
		{
			system("cls");
			ThucHienBai1();
			getch();
			system("cls");
		}
		else if (luachon == 2)
		{
			system("cls");
			ThucHienBai2();
			getch();
			system("cls");
		}
		else if (luachon == 3)
		{
			system("cls");
			ThucHienBai3();
			getch();
			system("cls");
		}
		else if (luachon == 4)
		{
			system("cls");
			ThucHienBai4();
			getch();
			system("cls");
		}
		else if (luachon == 5)
		{
			system("cls");
			ThucHienBai5();
			getch();
			system("cls");
		}
		else if (luachon == 6)
		{
			system("cls");
			ThucHienBai6();
			getch();
			system("cls");
		}
		else if (luachon == 7)
		{
			system("cls");
			ThucHienBai7();
			getch();
			system("cls");
		}
		else if (luachon == 8)
		{
			system("cls");
			ThucHienBai8();
			getch();
			system("cls");
		}
		else if (luachon == 9)
		{
			system("cls");
			ThucHienBai9();
			getch();
			system("cls");
		}
		else if (luachon == 10)
		{
			system("cls");
			ThucHienBai10();
			getch();
			system("cls");
		}
		else if (luachon == 11)
		{
			system("cls");
			ThucHienBai11();
			getch();
			system("cls");
		}
		else if (luachon == 12)
		{
			system("cls");
			ThucHienBai12();
			getch();
			system("cls");
		}
		else if (luachon == 13)
		{
			system("cls");
			ThucHienBai13();
			getch();
			system("cls");
		}
		else if (luachon == 14)
		{
			system("cls");
			ThucHienBai14();
			getch();
			system("cls");
		}
		else if (luachon == 15)
		{
			system("cls");
			ThucHienBai15();
			getch();
			system("cls");
		}
		else if (luachon == 0)
		{
			system("cls");
			printf("\nThanks You For Using The Program! Goodbye And See You Later !\n");
			Sleep(1000);
			break;
		}
	}
}

int main()
{
	MeNu();
	return 0;
}
