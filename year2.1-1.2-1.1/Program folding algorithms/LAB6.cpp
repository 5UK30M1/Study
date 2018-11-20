#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct mem
{
    int i;
    int j;
    int val;
};

void inputm(int **matr, int N);
void outputm(int **matr, int N);
void task (int **matr, int N, int *j1);
void output_new_matr(int **matr, int N, int *j1);
void size_of_matr (int **matr, int N, int *j1);
void input_new_matr (int **matr, int **matr1, int N, int *j1);
void task_old_matr (int **matr, mem *memset, int N);

int main()
{
    int N;
    cout << "Input size of matrix" << endl;
    cin >> N;
    int *j1 = new int [N] {0};
    int **matr1 = new int * [N];
    for (int i = 0; i < N; i++)
    {
        matr1[i] = new int [N];
    }
    inputm(matr1, N);
    cout << "Start matrix:" << endl;
    outputm(matr1, N);
    size_of_matr(matr1, N, j1);
    int **matr = new int * [N];
    for (int i = 0; i < N; i++)
    {
        matr[i] = new int [j1[i]] ;
    }
    input_new_matr(matr, matr1, N, j1);
    cout << endl << endl;
    cout << "Pulled matrix:" << endl;
    output_new_matr(matr, N, j1);
    cout << endl << endl;
    cout << "Pulled sorted matrix:" << endl;
    int s = 0;
    for(int i = 0; i < N; i++)
    {
        s += j1[i];
    }
    mem *memset = new mem [s];
    task(matr, N, j1);
    output_new_matr(matr, N, j1);
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(matr1[i][j] != 0)
            {
                memset[k].i = i;
                memset[k].j = j;
                k++;
            }
        }
    }
    k = 0;
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < j1[i]; j++)
        {
            memset[k].val = matr[i][j];
            k++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        matr[i] = new int [N] {0};
    }
    task_old_matr(matr, memset, s);
    cout << endl << endl;
    cout << "Default sorted matrix:" << endl;
    outputm(matr, N);
    return 0;
}


void inputm(int **matr, int N)
{
    srand (time(0));
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            matr[i][j] = rand () % 99-49;
            if (matr[i][j] > 9  ||  matr[i][j] < -9)
            {
                matr[i][j] = 0;
            }
        }
    }
}

void outputm(int **matr, int N)
{
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout.width(4);
            cout << matr[i][j];
        }
    cout << endl;
    }
}

void output_new_matr(int **matr, int N, int *j1)
{
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < j1[i]; j++)
        {
            cout.width(4);
            cout << matr[i][j];
        }
    cout << endl;
    }
}

void task (int **matr, int N, int *j1)
{
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < j1[i]; j += 5)
        {
            if ((j+4) >= j1[i])
            {
                break;
            }
            swap (matr[i][j],matr[i][j+4]);
            swap (matr[i][j+1],matr[i][j+3]);
        }
    }
}

void size_of_matr (int **matr, int N, int *j1)
{
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if (matr[i][j] != 0)
            {
                j1[i]++;
            }
        }
    }
}

void input_new_matr (int **matr, int **matr1, int N, int *j1)
{
    for (int i = 0; i < N; i++)
    {
        for(int j = 0, k = 0; k < N && j < j1[i]; j++,k++)
        {
            while (matr1[i][k] == 0)
            {
                k++;
            }
            matr[i][j] = matr1[i][k];
        }
    }
}

void task_old_matr (int **matr, mem *memset, int N)
{
    for (int i = 0; i < N; i++)
    {
        matr[memset[i].i][memset[i].j] = memset[i].val;
    }
}
