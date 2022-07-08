#include <iostream>
using namespace std;

class dathuc
{
    double* heso;
    int sobac;
public:
    dathuc(int _sobac = 0);
    dathuc(const dathuc&);
    dathuc(int k, double v);
    ~dathuc() 
    { 
        delete heso; 
    }
    dathuc& operator = (const dathuc&);

    friend int operator == (const dathuc&, const dathuc&);
    double value(double);
    double& operator [](int k)const 
    { 
        return heso[k];
    }
    dathuc operator * (const dathuc&)const;
    dathuc operator / (const dathuc&)const;
    dathuc operator % (const dathuc&)const;
    dathuc operator + (const dathuc&)const;
    dathuc operator - (const dathuc&)const;
    dathuc operator - ()const;

    dathuc operator * (double);
    dathuc operator / (double f) 
    {
        return (*this) * (1 / f);
    }
    dathuc operator + (double f) 
    { 
        return (*this) + dathuc(0, f);
    }
    dathuc operator - (double f) 
    { 
        return (*this) - dathuc(0, f);
    }

    friend dathuc operator * (double f, dathuc a) 
    { 
        return  a * f; 
    }
    friend dathuc operator + (double f, dathuc a) 
    { 
        return  a + f;
    }
    friend dathuc operator - (double f, dathuc a) 
    { 
        return -a + f;
    }

    friend ostream& operator << (ostream&, const dathuc&);
    friend istream& operator >> (istream&, dathuc&);
    void set(int m, double v[]);
};

void dathuc::set(int m, double v[])
{
    this->~dathuc();
    sobac = m;
    heso = new double[sobac + 1];
    for (int k = 0; k <= sobac; k++)
    {
        heso[k] = v[k];
    }
}

dathuc::dathuc(int _sobac)
{
    sobac = _sobac;
    if (sobac < 0) sobac = 0;
    heso = new double[sobac + 1];
    for (int k = 0; k <= sobac; k++)
    {
        heso[k] = 0;
    }
}

dathuc::dathuc(const dathuc& a)
{
    sobac = a.sobac;
    heso = new double[sobac + 1];
    for (int k = 0; k <= sobac; k++)
    {
        heso[k] = a[k];
    }
}

dathuc& dathuc:: operator = (const dathuc& b)
{
    if (this != &b)
    {
        this->~dathuc();
        sobac = b.sobac;
        heso = new double[sobac + 1];
        for (int k = 0; k <= sobac; k++)
        {
            heso[k] = b[k];
        }
    }
    return *this;
}

dathuc::dathuc(int k, double v)
{
    sobac = k;
    heso = new double[k + 1];
    for (int j = 0; j < sobac; j++)
    {
        heso[j] = 0;
    }
    heso[sobac] = v;
}


dathuc dathuc:: operator * (double f)
{
    dathuc c(*this);
    for (int k = 0; k <= sobac; k++)
    {
        c[k] *= f;
    }
    while (c.sobac && c[c.sobac] == 0)
    {
        c.sobac--;
    }
    return c;
}

dathuc dathuc::operator + (const dathuc& b)const
{
    if (sobac <= b.sobac)
    {
        dathuc c(b);
        for (int k = 0; k <= sobac; k++)
        {
            c[k] += heso[k];
        }
        while (c.sobac && c[c.sobac] == 0)
        {
            c.sobac--;
        }
        return c;
    }
    else return b + *this;
}

dathuc dathuc::operator - ()const
{
    dathuc c(*this);
    for (int k = 0; k <= sobac; k++)
    {
        c[k] = -c[k];
    }
    return c;
}

dathuc dathuc::operator - (const dathuc& b)const
{
    return *this + -b;
}

dathuc dathuc::operator * (const dathuc& b)const
{
    dathuc c(sobac + b.sobac);
    for (int k = 0; k <= sobac; k++)
    {
        for (int j = 0; j <= b.sobac; j++)
        {
            c[k + j] = c[k + j] + heso[k] * b[j];
        }
    }
    while (c.sobac && c[c.sobac] == 0)
    {
        c.sobac--;
    }
    return c;
}

dathuc dathuc::operator / (const dathuc& b)const
{
    if (sobac < b.sobac)
    {
        return dathuc(0, 0);
    }
    dathuc c(sobac - b.sobac), a(*this);
    int jc = c.sobac, ja = sobac;
    while (jc >= 0)
    {
        c[jc] = a[ja] / b[b.sobac];
        a = a - b * dathuc(jc, c[jc]);
        jc--; 
        ja--;
    }
    return c;
}

dathuc dathuc::operator % (const dathuc& b)const
{
    dathuc a(*this);
    if (sobac >= b.sobac)
    {
        a = a - (a / b) * b;
        while (a[a.sobac] == 0)
        {
            a.sobac--;
        }
    }
    return a;
}
int operator == (const dathuc& a, const dathuc& b)
{
    if (a.sobac != b.sobac)
    {
        return 0;
    }
    int k = 0;
    while (k <= a.sobac && a[k] == b[k])
    {
        k++;
    }
    return k > a.sobac;
}

double dathuc::value(double x)
{
    double val = heso[sobac];
    for (int k = sobac - 1; k >= 0; k--)
    {
        val = val * x + heso[k];
    }
    return val;
}
ostream& operator << (ostream& pout, const dathuc& p)
{
    int k = 0;
    while (k <= p.sobac && p[k] == 0)
    {
        k++;
    }
    if (k > p.sobac) 
    { 
        pout << 0;
        return pout; 
    }
    if (k == 0)
    {
        pout << p[k];
    }
    else
    {
        if (p[k] == 1)
        {
            pout << "x";
        }
        else if (p[k] == -1)
        {
            pout << "-x";
        }
        else pout << p[k] << "x";
        if (k > 1)
        {
            pout << "^" << k;
        }
    }

    while (++k <= p.sobac)
    {
        if (p[k] > 0)
        {
            pout << " + ";
            if (p[k] != 1)
            {
                pout << p[k];
            }
            pout << "x";
            if (k > 1)
            {
                pout << "^" << k;
            }
        }
        else if (p[k] < 0)
        {
            pout << " - ";
            if (p[k] != -1)
            {
                pout << -p[k];
            }
            pout << "x"; 
            if (k > 1) 
            {
                pout << "^" << k;
            }
        }
    }
    return pout;
}

istream& operator >> (istream& pin, dathuc& p)
{
    do
    {
        cout << "Bac cua da thuc: "; pin >> p.sobac;
    } while (p.sobac < 0);

    p.heso = new double[p.sobac + 1];
    cout << "Nhap lien tiep " << p.sobac + 1 << " he so tu bac 0 den bac " << p.sobac << ": ";
    for (int k = 0; k <= p.sobac; k++)
    {
        pin >> p[k];
    }
    while (p[p.sobac] == 0)
    {
        p.sobac--;
    }
    return pin;
}

int main()
{
    dathuc a, b;
    cout << "\nNhap da thuc thu nhat\n"; 
    cin >> a;
    cout << "\nNhap da thuc thu hai\n"; 
    cin >> b;
   
    cout << "\nKet qua cac phep toan:\n";
    cout << "\n(" << a << ") + (" << b << ") = " << a + b << endl;
    cout << "\n(" << a << ") - (" << b << ") = " << a - b << endl;
    cout << "\n(" << a << ") * (" << b << ") = " << a * b << endl;
    cout << "\n(" << a << ") / (" << b << ") = " << a / b << endl;
    cout << "\n(" << a << ") % (" << b << ") = " << a % b << endl;
    return 0;
}
