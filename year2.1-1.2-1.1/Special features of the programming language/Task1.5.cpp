//Вычислить средние арифметические значения неотрицательных элементов каждой строки матрицы [N;M].
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int N,M;

using namespace std;
void inputm(int **matr);//Заполнение матрицы
void outputm (int **matr,double *sum);//Вывод результата
void sumofline(int **matr,double *sum);//Сумма ряда матрицы

int main()
{
    cout << "Enter matrix N x M" << endl;
    cin >> N;
    cin >> M;
    int **matr = new int *[N];
    for (int i = 0; i < N; i++)
    {
        matr[i] = new int [M];
    }
    double *sum = new double [N] {0};
    cout << "Matrix random filling" << endl ;
    inputm(matr);
    sumofline(matr,sum);
    outputm(matr,sum);
    return 0;
}

void inputm(int **matr)
{
    int i, j;
    srand (time(0));
    for (i = 0; i < N; i++){
        for(j = 0; j < M; j++){
            matr[i][j] = rand () % 19-9;
        }
    }
}

void outputm(int **matr,double *sum)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        cout << endl;
        for(j = 0; j < M; j++)
            printf("%2d  ",matr[i][j]);
    }
    cout << endl;
    for (i = 0; i < N; i++){
        cout << i << " line elements arithmetic average:" << sum[i] << endl;
    }
}

void sumofline(int **matr,double *sum)
{
    int i ,j ,k;
    for (i = 0; i < N; i++)
    {
        for(j = 0, k = 0; j < M; j++){
            if(matr[i][j] > 0) {
                sum[i] += matr[i][j];
                k++;
            }
        }
        sum[i] = sum[i] / k;
    }
}
