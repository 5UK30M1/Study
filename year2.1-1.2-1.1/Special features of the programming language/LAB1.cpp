//Посчитать сумму ряда и сравнить его с функцией.
#include <iostream>
#include <math.h>
#define eps 1e-16

int n;
using namespace std;
double powfunc(int n,double x);// Возведение в степень
double sum(int ITER,double x);// Сумма ряда
void output(double x,int ITER);//Вывод результата (таблица)

int main()
{
    double x = 0;
    float t0, t;
    int ITER;
    do
    {
        cout << "Enter number of iteration" << endl;
        cin >> ITER;
    }
    while (ITER <= 0);
    output (x, ITER);
    return 0;
}

double powfunc(int n,double x)
{
    int i;
    double p = 1;
    if (n >=0 ) {
        for(i = 0; i < n; i++) {
            p *= x;
        }
    }
    else {
        for(i = 0; i > n; i--) {
            p *= 1 / x;
        }
    }
    return p;
}

double sum(int ITER,double x)
{
    double s = 0;
    double f0 = 0;
    double f;
    for (n = 1; n <= ITER; n++) {
        f = powfunc(n - 1, -1) * powfunc(n, x - 1) / n;
        s += f;
        if (fabs(f - f0) > eps) {
            f0 = f;
        }
        else {
            break;
        }
    }
    return s;
}

void output(double x,int ITER)
{
    double h = 0.05;
    double x2 = 2;
    int i = 0;
    cout << "|-------------------------------------|" << endl;
    cout << "|  x   |  Sum   |Function| Iterations |" << endl;
    cout << "|------|--------|--------|------------|" << endl;
    cout.setf(ios::fixed);
    while (x <= x2 + 1e-6){
        if (x > 0) {
            cout << "|" ;
            cout.width(6);
            cout.precision(2);
            cout << x << "|";
            cout.width(8);
            cout.precision(5);
            cout << sum(ITER,x) << "|";
            cout.width(8);
            cout.precision(5);
            cout << log(x) << "|";
            cout.width(12);
            cout << n-1 << "|" << endl;
        }
        else {
            cout << "|" ;
            cout.width(6);
            cout.precision(2);
            cout << x << "|";
            cout << "    INVALID VARIABLE VALUE    |" << endl;
        }
            x += h;
            i++;
        }
        cout << "|-------------------------------------|" << endl;
}
