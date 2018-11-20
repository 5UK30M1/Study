#include <iostream>
#include <math.h>
#include <time.h>
#define eps 1e-7

using namespace std;

int ITER;

double sumloot (double x);
double sumrecursion(int n, double func);
double realsum (double x);
int factorial(int f);
double sumloot2 (double x);
double sumrecursion2(int n, double func);
double realsum2 (double x);

int main()
{
    double x;
    clock_t c, cr;
    cout << "SUM:(((-1)^n)*x)/n!" << endl;
    cout << "Enter x:" << endl;
    cin >> x;
    c = clock();
    cout << "Sum by loot(standard(" << ITER << " iterations)): "  << realsum(x) << "  clicks(ms):" << clock() - c << endl;
    c = clock();
    cout << "Sum by loot(recurrent(" << ITER << " iterations)): " << sumloot(x) << "  clicks(ms):" << clock() - c  << endl;
    cr = clock();
    double sumr1 = sumrecursion(1,x);
    cr = clock() - cr;
    cout << "Sum by recursion ("  << ITER << " iterations): " << sumr1  << "  clicks(ms):" << cr << endl << endl;
    cout << "SUM:(((-1)^n)*x)/(n!*3^(n+1))" << endl;
    cout << "Enter x:" << endl;
    cin >> x;
    c = clock();
    cout << "Sum by loot(standard(" << ITER << " iterations)): "  << realsum2(x) << "  clicks(ms):" << clock() - c  << endl;
    c = clock();
    cout << "Sum by loot(recurrent(" << ITER << " iterations)): "  << sumloot2(x) << "  clicks(ms):" << clock() - c  << endl;
    cr = clock();
    double sumr2 = sumrecursion2(1, x/3);
    cr = clock() - cr;
    cout << "Sum by recursion ("  << ITER << " iterations): " << sumr2  << "  clicks(ms):" << cr << endl << endl;
    cout << "Clock of program's end\nClicks:  " << clock() << "  Seconds:  " << (double)clock()/CLOCKS_PER_SEC << endl;
    return 0;
}

double sumloot (double x)
{
    double s = x;
    double f = x;
    int n;
    for (n = 1; fabs(f) > eps; n++) {
        f *= (-1.) / n;
        s += f;
    }
    ITER = n;
    return s;
}

double sumrecursion(int n, double func)
{
    double s = func;
    func *= (-1.) / n;
    n++;
    if (fabs(func) > eps)
    {
        s += sumrecursion(n,func);
    }
    else
    {
        ITER = n;
    }
    return s;
}

int factorial(int f)
{
    int fact;
    if(f <= 1){
        return 1;
    }
    fact = factorial(f-1)*f;
    return fact;
}

double realsum (double x)
{
    double s = 0;
    double f0 = 0;
    double f;
    for (int n = 0; n < 15 ; n++) {
        f = pow(-1, n) * x / factorial(n);
        s += f;
        ITER = n + 1;
        if (fabs(f - f0) > eps) {
            f0 = f;
        }
        else
        {
            break;
        }
    }
    return s;
}

double sumloot2 (double x)
{
    double s = x / 3;
    double f = x / 3;
    int n;
    for (n = 1; fabs(f) > eps; n++) {
        f *= (-1.) / (3 * n);
        s += f;
    }
    ITER = n;
    return s;
}

double sumrecursion2(int n, double func)
{
    double s = func;
    func *= (-1.) / (3 * n);
    n++;
    if (fabs(func) > eps)
    {
        s += sumrecursion2(n,func);
    }
    else
    {
        ITER = n;
    }
    return s;
}

double realsum2 (double x)
{
    double s = 0;
    double f0 = 0;
    double f;
    for (int n = 0; ; n++) {
        f = pow(-1, n) * x / (factorial(n) * pow (3, n + 1));
        s += f;
        ITER = n + 1;
        if (fabs(f - f0) > eps) {
            f0 = f;
        }
        else
        {
            break;
        }
    }
    return s;
}
