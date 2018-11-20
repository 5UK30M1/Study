#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;
void recursion(int n,int *mas);
int factorial(int f);
void randfilling (int *mas ,int n);

int main()
{
    int f;
    int n;
    cout << "Enter size of array:";
    cin >> n;
    int *mas = new int [n];
    int t = time(0);
    int c = clock();
    randfilling (mas, n);
    cout << "Recursion check:" << endl << endl;
    recursion(n - 1, mas);
    cout << "Factorial:" << endl;
    cout << "f!  Enter f:";
    cin >> f;
    f = factorial(f);
    cout << endl << endl << "f!=" << f << endl;
    t = time(0) - t;
    c = clock() - c;
    cout << "time=" << t << "s" << endl;
    cout << "clock=" << c << "ms" << endl;
    return 0;
}

void recursion(int n, int *mas)
{
    cout << "Decline - " << n << endl;
    cout << "Arr el[Decline]" << *(mas + n) << endl;
    if (n > 0){
        recursion(n - 1, mas);
    }
    else
    {
        cout << "___________" << endl;
    }
    cout << "Uplift - " << n << endl;
    cout << "Arr el[Uplift]" << *(mas + n) << endl;
}

int factorial(int f)
{
    int fact;
    if(f == 1){
        return 1;
    }
    fact = factorial(f-1)*f;
    return fact;
}

void randfilling (int *mas ,int n)
{
    srand (time(0));
    for (int i = 0; i < n; i++)
    {
        *(mas + i) = rand() % 23 - 13;
    }
}
