#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int in, jn;
int k = 0;

void output (int **matr, int N, int M);
void moving (int **matr, int N, int M, int i, int j);
void task(int **matr, int N, int M);

int main()
{
    char temp[10],tmatr[70][100];
    ifstream file("input.txt");
    file.getline(tmatr[0], 100);
    int N, M;
    int p = 0;
    int p1 = 0;
    while(isdigit(tmatr[0][p]))
    {
        temp[p] = tmatr[0][p];
        p++;
    }
    N = atoi(temp);
    p++;
    strcpy(temp,"       ");
    while(isdigit(tmatr[0][p]))
    {
        temp[p1] = tmatr[0][p];
        p++;
        p1++;
    }
    M = atoi(temp);
    int **matr = new int * [N];
    for (int i = 0; i < N; i++)
    {
        matr[i] = new int [M] ;
    }
    for (int i = 0; i < N; i++)
    {
        p = 0;
        file.getline(tmatr[i + 1], 100);
        for(int j = 0, p = 0; j < M; j++)
        {
            p1 = 0;
            strcpy(temp,"       ");
            while(isdigit(tmatr[i + 1][p]))
            {
                temp[p1] = tmatr[i + 1][p];
                p++;
                p1++;
            }
            matr[i][j] = atoi(temp);
            p++;
        }
    }
    file.close();
    output(matr, N, M);
    task(matr, N, M);
    cout << "Number of ways:  " << k << endl;
    ofstream fileout("output.txt", ios_base::out | ios_base::trunc);
    fileout << k;
    fileout.close();
    return 0;
}

void output (int **matr, int N, int M)
{
    cout << endl;
    for (int i(0); i < N; i++)
    {
        for (int j(0); j < M; j++)
        {
            cout.width(5);
            cout << *(*(matr + i)+j);
        }
        cout << endl;
    }
    cout << endl;
}

void task(int **matr, int N, int M)
{
    int i, j;
    cout << "Enter start coordinates:" << endl;
    cin >> i;
    cin >> j;
    cout << "Enter finish coordinates:" << endl;
    cin >> in;
    cin >> jn;
    moving(matr, N, M, i, j);
}

void moving (int **matr, int N, int M, int i, int j)
{
    if(i != in || j != jn)
    {
        if (i + matr[i][j] <= N - 1)
        {
            moving(matr, N, M, i + matr[i][j], j);
        }
        if (j + matr[i][j] <= M - 1)
        {
            moving(matr, N, M, i, j + matr[i][j]);
        }
    }
    else
    {
        k++;
    }
}
