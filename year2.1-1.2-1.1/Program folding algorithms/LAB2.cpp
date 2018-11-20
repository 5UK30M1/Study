#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void randomarr(int *arr, int n);
int indarrmin (int *arr, int n);
int indarrmax (int *arr, int n);
void middleelsloot (int *arr, int ind1, int ind2);
void middleelsrecursion (int *arr, int ind1, int ind2);

int main()
{
    int n, ind1 ,ind2;
    clock_t c;
    cout << "Input size of array:";
    cin >> n;
    int *arr = new int [n];
    randomarr(arr, n);
    int amin = indarrmin (arr, n);
    int amax = indarrmax (arr, n);
    if (amin < indarrmax (arr, n))
    {
        ind1 = amin;
        ind2 = amax;
    }
    else
    {
        ind2 = amin;
        ind1 = amax;
    }
    cout << endl << endl << "LOOT:       ";
    c = clock();
    middleelsloot(arr, ind1 + 1 ,ind2);
    cout << endl << "Clocks(ms): " << clock() - c << endl;
    cout << endl << endl << "RECURSION:  ";
    c = clock();
    middleelsrecursion(arr, ind1 + 1 ,ind2);
    cout << endl << "Clocks(ms): " << clock() - c << endl;
    cout << endl;
    return 0;
}

void randomarr(int *arr, int n)
{
    srand (time (0));
    for (int i(0); i < n; i++)
    {
        *(arr + i) = rand() % 101;
        cout << *(arr + i) << "  ";
    }
    cout << endl;
}

 int indarrmin (int *arr, int n)
{
    int indarrmin = 0;
    for (int i(1); i < n; i++)
    {
        if (*(arr + indarrmin) > *(arr + i))
        {
            indarrmin = i;
        }
    }
    cout << "indexmin: " << indarrmin << endl;
    return indarrmin;
}

 int indarrmax (int *arr, int n)
{
    int indarrmax = 0;
    for (int i(1); i < n; i++)
    {
        if (*(arr + indarrmax) < *(arr + i))
        {
            indarrmax = i;
        }
    }
    cout << "indexmax: " << indarrmax << endl;
    return indarrmax;
}

void middleelsloot (int *arr, int ind1, int ind2)
{
    for (; ind1 < ind2; ind1++)
    {
        cout << *(arr + ind1) << "   ";
    }
}

void middleelsrecursion (int *arr, int ind1, int ind2)
{
    if (ind1 < ind2)
    {
        cout << *(arr + ind1) << "   ";
        middleelsrecursion (arr, ind1 + 1, ind2);
    }
}
