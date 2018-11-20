#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct funcpar
{
    double a;
    double b;
    double x1;
    double x2;
    double dx;
    double fx;
};

struct func
{
    double x;
    double y;
};

void ReadPar(funcpar *PARs);
void FuncVal(funcpar *PARs, func *Fs, int n);
void Tab(func *Fs, int k);
void Tab(double *rnd, int k);
void Norm (int *intf, int i, func *Fs, int A);
void Norm (int *intf, int i, double *rnd, int A);
void Print (int *intf, int i);
void s1s2 (func *Fs, int k, double &S1, double &S2);
void RandArr (double *rnd, int k, double S1, double S2);

int main()
{
    funcpar *PARs = new funcpar;
    ReadPar(PARs);
    int k;
    k = ceil((PARs->x2 - PARs->x1)/PARs->dx) + 1;
    func *Fs = new func [k];
    FuncVal(PARs, Fs, k);
    Tab(Fs, k);
    int i = 0;
    int A;
    cout << endl << "Enter parameter 'A' ";
    cin >> A;
    for (int j(0); j < k; j++)
    {
        if((Fs + j)->y >= 0 && (Fs + j)->y <= A)
        {
            i++;
        }
    }
    if (i == 0)
    {
        cout << "ERROR!!!" << endl;
        return 0;
    }
    int *intf = new int[i];
    Norm (intf, i, Fs, A);
    cout << endl;
    Print(intf, i);
    double S1(0);
    double S2(0);
    s1s2 (Fs, k, S1, S2);
    delete[] intf;
    double *rnd = new double [k];
    RandArr (rnd, k, S1, S2);
    Tab(rnd, k);
    i = k;
    int *intf2 = new int[i];
    Norm (intf2, i, Fs, A);
    cout << endl;
    Print(intf2, i);
    cout << endl << "Value of pointer :" << rnd;
    cout << endl << "Address of pointer :" << &rnd;
    return 0;
}

void ReadPar(funcpar *PARs)
{
    cout << "Enter parameter 'a' ";
    cin >> PARs->a;
    cout << endl << "Enter parameter 'b' ";
    cin >> PARs->b;
    cout << endl << "Enter parameter 'x1' ";
    cin >> PARs->x1;
    do
    {
        cout << endl << "Enter parameter 'x2'(x2 > x1) ";
        cin >> PARs->x2;
    }
    while (PARs->x2 <= PARs->x1);
    do
    {
        cout << endl << "Enter parameter 'dx'(dx > 0) ";
        cin >> PARs->dx;
    }
    while (PARs->dx <= 0);
}

void FuncVal(funcpar *PARs, func *Fs, int n)
{
    int i(0);
    int buff;
    double temp;
    double counter;
    if(PARs->dx - (int)PARs->dx == 0)
    {
        counter = 1;
    }
    else
    {
        counter = pow(10,ceil(-log10(PARs->dx - (int)PARs->dx)));
    }
    (Fs + i)->x = PARs->x1;
    while (i < n)
        //(buff <= (int)(PARs->x2 * counter))
    {
        if((Fs + i)->x <= 1)
        {
            (Fs + i)->y = PARs->a * (Fs + i)->x * (Fs + i)->x - PARs->b;
        }
        else
        {
            (Fs + i)->y = PARs->a / ((Fs + i)->x + PARs->b);
        }
        temp = (Fs + i)->x;
        i++;
        (Fs + i)->x = temp + PARs->dx;
       // buff = (Fs + i)->x * counter;
    }
}

void Tab(func *Fs, int k)
{
    cout << "ษอออัออออออออป" << endl;
    cout << "บx  ณf(x)    บ" << endl;
    for (int i(0); i < k; i++)
    {
        cout << "ฬอออุออออออออน" << endl;
        cout << "บ";
        cout.width(3);
        cout << setw(3) << (Fs + i)->x;
        cout << "ณ";
       // cout.width(2);
        //cout << setw(2) << (Fs + i)->y;
        printf("%8.4lf",(Fs + i)->y);
        cout << "บ" << endl;
    }
    cout << "ศอออฯออออออออผ" << endl;
}


void Tab(double *rnd, int k)
{
    cout << "ษอออัออออออออป" << endl;
    cout << "บi  ณrnd[i]  บ" << endl;
    for (int i(0); i < k; i++)
    {
        cout << "ฬอออุออออออออน" << endl;
        cout << "บ";
        cout.width(3);
        cout << setw(3) << i;
        cout << "ณ";
       // cout.width(2);
        //cout << setw(2) << (Fs + i)->y;
        printf("%8.4lf",*(rnd + i));
        cout << "บ" << endl;
    }
    cout << "ศอออฯออออออออผ" << endl;
}

void Norm (int *intf, int n, func *Fs, int A)
{
	double min = Fs->y, max = Fs->y;


	for (int i = 1; i < n; i++)
	{
		if (min > (Fs + i)->y) min = (Fs + i)->y;
		if (max < (Fs + i)->y) max = (Fs + i)->y;
	}

	double gem = A / (max -= min);
	double temp = 0;

	for (int i = 0; i < n; i++)
	{
		temp = gem * (((Fs+i)->y) - min);
		*(intf + i) = temp + 0.5;
	}
}

void Norm (int *intf, int n, double *mas, int A)
{
	double min = *(mas), max = *(mas);


	for (int i = 1; i < n; i++)
	{
		if (min > *(mas + i)) min = *(mas + i);
		if (max < *(mas + i)) max = *(mas + i);
	}

	double gem = A / (max -= min);
	double temp = 0;

	for (int i = 0; i < n; i++)
	{
		temp = gem * ((*(mas + i)) - min);
		*(intf + i) = temp + 0.5;
	}
}

void Print (int *intf, int i)
{
    cout << "Diagram:" << endl;
    for (int j(0); j < i; j++)
    {
        for(int k(0); k < intf[j]; k++)
        {
            cout << "";
        }
        cout << endl;
    }
}

void s1s2 (func *Fs, int k, double &S1, double &S2)
{
    int n(0);
    for (int i(0); i < k; i++)
    {
        if((Fs + i)->y < 0)
        {
            S1 += (Fs + i)->y;
            n++;
            if(i % 2)
            {
                S2 += (Fs + i)->y;
            }
        }
    }
    S1 /= n;
}

void RandArr (double *rnd, int k, double S1, double S2)
{

    float d;
    double Smin;
    double Smax;
    if (S1 > S2)
    {
        Smin = S2;
        Smax = S1;
    }
    else
    {
        Smax = S2;
        Smin = S1;
    }
    cout << " 1 " << &d << endl;
    int n;
    do
    {
        cout << endl << "Enter step of random values( > 0 ) :";
        cin >> d;
    }
    while (d <= 0);

    cout << " 2 " << d << endl;
    d *= Smax;

    cout << " 3 " << d << endl;
    d = fabs(d);
    cout << " 4 " << d << endl;
    srand(time(0));
    n = ((Smax - Smin) / d) + 1;
    cout << "\n kk" << n << "     " << d << "\n\n";
    for (int i =0; i < k; i++)
    {

    cout << "  " << *(rnd + i);
        if(n != 0)
        {
            *(rnd + i) = Smin + (rand() % n) * d;
        }
        else
        {
            *(rnd + i) = Smin;
        }
    }
}
