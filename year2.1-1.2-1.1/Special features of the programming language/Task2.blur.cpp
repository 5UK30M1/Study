#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int N;
clock_t t0,t;
int ITER = 0;

using namespace std;

void inputm(int **inmatr,double **outmatr);
void blur(int **inmatr,double **outmatr);
void output(int **inmatr,double **outmatr);

int main()
{
    cout << "Enter matrix N x N" << endl;
    cin >> N;
    int **inmatr = new int *[N];
    for (int i = 0; i < N; i++)
    {
        inmatr[i] = new int [N];
    }
    double **outmatr = new double *[N];
    for (int i = 0; i < N; i++)
    {
        outmatr[i] = new double [N] {0};
    }
    inputm(inmatr,outmatr);
    blur(inmatr,outmatr);
    t = clock() - t;
//    output(inmatr,outmatr);
    printf ("\nAlgorithm took %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    cout << "\nITER=" << ITER;
    return 0;
}

void inputm(int **inmatr,double **outmatr)
{
    int i,j;
    srand (time(0));
    for (i = 0; i < N; i++)
        for(j = 0;j < N; j++)
            inmatr[i][j] = rand () % 10;
}

void blur(int **inmatr,double **outmatr)
{
    int i,j,R,n,m,k;
    int s = 0;
    do {
    cout << "Enter blur radius" << endl;
    cin >> R;
    }
    while (R < 1);
    if (R > N)
    {
        R = N;
    }
    t = clock();
    for (i = 0; i < N; i++)
        for(j = 0; j < N; j++)
        {
            k = 0;
            for (n = i - R; n <= i + R; n++)
                for (m = j - R; m <= j + R; m++)
                    if (n >= 0 && n < N && m < N && m >= 0)
                    {
                        outmatr[i][j] += inmatr[n][m];
                        k++;
                        ITER++;
                    }
            outmatr[i][j] = outmatr[i][j] / k;
        }
}

void output(int **inmatr,double **outmatr)
{
    int i,j;
    cout << endl << "Matrix before blur:" << endl;
    for(i = 0;i < N; i++)
    {
        for(j = 0; j < N; j++)
            printf("%3d",inmatr[i][j]);
        cout << endl;
    }
    cout << endl << "Matrix after blur:" << endl;
    for(i = 0; i < N; i++)
    {
        for(j = 0;j < N; j++)
            printf("%6.3lf",outmatr[i][j]);
        cout << endl;
    }
}
