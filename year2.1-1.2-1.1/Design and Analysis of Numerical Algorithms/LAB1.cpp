#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#define N 10

using namespace std;
void zapovn(int *a);
int maxel(int *a);
void vivid(int *a,int amax);
void matr_zapovn(int matr[N][N]);
int matr_maxel(int matr[N][N],int *mi,int *mj);
void matr_obnullsect(int matr[N][N]);
void matr_sortdagonal(int matr[N][N]);
void matr_maxeldiagonal(int matr[N][N],int mi,int mj);
void vivid(int matr[N][N],int mmax);
int main()
{
    int a[N];
    int matr[N][N];
    int i, mi, mj, amax, mmax, ind;
    system("chcp 1251 & cls");
    zapovn(a);
    amax = maxel(a);
    vivid(a, amax);
    cout << "Ініціалізація двомірного масиву" << endl;
    matr_zapovn(matr);
    mmax = matr_maxel(matr, &mi, &mj);
    vivid(matr, mmax);
    cout << endl << "Виберіть дію(введіть її номер):";
    cout << endl << "0-Вихід з програми";
    cout << endl << "1-Обнулення сектору";
    cout << endl << "2-Сортування діагоналі(по спаданню)";
    cout << endl << "3-Обнулення діагоналей які проходять через максимальний елемет матриці" << endl;
    cin >> ind;
    switch(ind)
    {
        case 1: cout << endl << "Обнулення сектору" << endl;
                matr_obnullsect(matr);
                break;
        case 2: cout << endl << "Сортування діагоналі(по спаданню)" << endl;
                matr_sortdagonal(matr);
                break;
        case 3: cout << endl << "Обнулення діагоналей які проходять через максимальний елемет матриці" << endl;
                cout << "Його координати:  " << mi << " " << mj << endl;
                matr_maxeldiagonal(matr, mi, mj);
                break;
        default : return 0;
    }
    vivid(matr, mmax);
    return 0;
}
void zapovn(int *a)
{
    int i;
    cout << "Масив заповнюється випадково" << endl;
    srand (time(0));
    for (i = 0; i < N; i++){
        a[i] = rand () % 1000;
    }
}
int maxel(int *a)
{
    int amax,i;
    amax = a[0];
    for (i = 1; i < N; i++){
        if(amax < a[i]){
            amax = a[i];
        }
    }
    return amax;
}
void vivid(int *a,int amax)
{
    int i;
    cout << "Вигляд масиву" << endl;
    for (i = 0; i < N; i++){
        cout << a[i] << "  ";
    }
    cout << endl << "Максимальний елемент масиву:" << amax << endl;
}
void matr_zapovn(int matr[N][N])
{
    int i, j;
    cout << "Матриця заповнюється випадково" << endl ;
    srand (time(0));
    for (i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            matr[i][j] = rand () % 9 + 1;
        }
    }
}
int matr_maxel(int matr[N][N],int *mi,int *mj)
{
    int i, j, mmax;
    mmax = matr[0][0];
    *mi = 0;
    *mj = 0;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            if (mmax < matr[i][j]){
                mmax = matr[i][j];
                *mi = i;
                *mj = j;
            }
        }
    }
    return mmax;
}
void matr_obnullsect(int matr[N][N])
{
    int i, j;
    for (i = 0; i < N / 2; i++){
        for (j = 0; j < N; j++){
            if(i - j < 0 && i + j < N - 1){
                matr[i][j] = 0;
            }
        }
    }
}
void vivid(int matr[N][N],int mmax)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        cout << endl;
        for(j = 0; j < N; j++){
            cout << matr[i][j] << "  ";
        }
    }
    cout << endl << "Максимальний елемент матриці:" << mmax;
}
void matr_sortdagonal(int matr[N][N])
{
    int i, j, l, r;
    r = N - 1;
    l = 1;
        while (l < r)
        {
            for (i = l, j = l; i <= r ,j <= r; i++, j++){
                if (matr[i-1][i-1] < matr[i][i]){
                    swap(matr[i-1][i-1], matr[i][i]);
                }
            }
            r--;
            for (i = r, j = r; i >= l, j >= l; i--, j--){
              if (matr[i-1][i-1] < matr[i][i]) {
                    swap(matr[i-1][i-1], matr[i][i]);
              }
            }
            l++;
      }
}
void matr_maxeldiagonal(int matr[N][N],int mi,int mj)
{
    int i = mi;
    int j = mj;
    for (;i < N && j < N; i++, j++)
    {
            matr[i][j] = 0;
    }
    i = mi;
    j = mj;
    for (;i >= 0 && j >= 0; i--, j--)
    {
            matr[i][j] = 0;
    }
    for (i = 0; i <= mi + mj; i++)
    {
        for (j = 0; j <= mi + mj; j++)
        {
            if (i + j == mi + mj)
            {
                matr[i][j] = 0;
            }
        }
    }
}
