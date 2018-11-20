#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void input(int **arr, int N); //ввод эл-ов матрицы
int sum (int **arr, int N);  //сумма непарных элементов непарных строк
void output (int **arr, int N); //вывод эл-ов матрицы и суммы непарных элементов непарных строк

int main()
{
    int N;
    cout << "Enter size of matrix:" << endl;
    cin >> N;
    int **arr = new int * [N];
    for (int i(0); i < N; i++)
    {
        arr[i] = new int [N];
    }
    input(arr, N);
    output (arr, N);
    return 0;
}
//ввод эл-ов матрицы
void input(int **arr, int N)
{
    srand(time(0));
    for (int i(0); i<N; i++)
    {
        for (int j(0); j < N; j++)
        {
            *(*(arr + i) + j) = rand () % 10;
        }
    }
}
//сумма непарных элементов непарных строк
int sum (int **arr, int N)
{
    int sum(0);
    for (int i(0); i < N; i += 2)
    {
        for (int j(0); j < N; j++)
        {
            if(*(*(arr + i) + j) % 2)
            {
                sum += **(arr + N * i + j);
            }
        }
    }
    return sum;
}
//вывод эл-ов матрицы и суммы непарных элементов непарных строк
void output (int **arr, int N)
{
    for (int i(0); i < N; i++)
    {
        for (int j(0); j < N; j++)
        {
            cout << *(*(arr + i) + j) << "    ";
        }
        cout << endl;
    }
    cout << endl << sum(arr, N);
}
