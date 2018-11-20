#include <iostream>
#include <stdlib.h>
#include <time.h>

using std::cin;
using std::cout;
using std::endl;

void input(int **matr, int n);
void output (int **matr, int n);
void sortin13 (int **matr, int n);
void swap (int &a, int &b);
void sortin13_2 (int **matr, int n);
void quickSort(int l, int r, int jm, int **matr);

int main()
{
    int n,ind;
    cout << "Enter size of matrix:   ";
    cin >> n;
    int **matr = new int * [n];
    for (int i(0); i < n; i++)
    {
        matr[i] = new int [n];
    }
    input(matr, n);
    output(matr, n);
    CH:
    cout << "Choose sort type(1-bubble sort, 2- quick sort) :" << endl;
    cin >> ind;
    switch(ind)
    {
        case 1: sortin13(matr, n);break;
        case 2: sortin13_2(matr, n);break;
        default :goto CH;
    }
    output(matr, n);
    return 0;
}

void input(int **matr, int n)
{
    srand(time(0));
    for (int i(0); i < n; i++)
    {
        for (int j(0); j < n; j++)
        {
            *(*(matr + i)+j) = rand () % 10;
        }
    }
}

void output (int **matr, int n)
{
    cout << endl;
    for (int i(0); i < n; i++)
    {
        for (int j(0); j < n; j++)
        {
            cout << *(*(matr + i)+j) << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void swap (int &a, int &b)
{
    int buff;
    buff = a;
    a = b;
    b = buff;
}

void sortin13 (int **matr, int n)
{
    int i;
    int j;
    for (j = n - 1, i = 0, i < n; j >= 0; j--, i++)
    {
        for (int ir = n - 1; ir >= 0; ir--)
        {
            for (int jr = i; jr < ir; jr++)
            {
                if (matr[jr][j] > matr[jr + 1][j])
                {
                    swap(matr[jr][j],matr[jr + 1][j]);
                }
            }
        }
    }
}

void sortin13_2 (int **matr, int n)
{
    int i;
    int j;
    for (j = n - 1, i = 0, i < n; j >= 0; j--, i++)
    {
        quickSort(i, n - 1, j, matr);
    }
}

void quickSort(int l, int r, int jm, int **matr)
{
    int x = matr[l + (r - l) / 2][jm];
    int i = l;
    int j = r;
    while(i <= j)
    {
        while(matr[i][jm] < x)
        {
            i++;
        }
        while(matr[j][jm] > x)
        {
            j--;
        }
        if(i <= j)
        {
            swap(matr[i][jm], matr[j][jm]);
            i++;
            j--;
        }
    }
    if (i < r)
    {
        quickSort(i, r, jm, matr);
    }
    if (l < j)
    {
        quickSort(l, j, jm, matr);
    }
}
