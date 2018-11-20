//Найти произведение минимального элемента матрицы вещественных чисел на сумму ее положительных элементов.
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;
int n;
void randfilling(int *mas);//Заполнение массива
int minel(int *mas);//Поиск минимального элемента
int poselsum(int *mas);
void output(int *mas);//Вывод результата

int main()
{
    int elnum,mmin;
    cout << "Enter number of array's elements:" << endl;
    cin >> n;
    int *mas = new int [n];
    cout << endl << "Array random filling" << endl;
    randfilling(mas);
    output(mas);
    return 0;
}

void randfilling(int *mas)
{
    int i;
    srand (time(0));
    for (i = 0; i < n; i++){
        mas[i] = rand () % 41-20;
    }
}
int minel(int *mas)
{
    int mmin, i;
    mmin = mas[0];
    for (i = 1; i < n; i++){
        if(mmin > mas[i]){
            mmin = mas[i];
        }
    }
    return mmin;
}
int poselsum(int *mas)
{
    int i;
    int s=0;
    for (i = 0; i < n; i++)
        if(mas[i] > 0){
            s += mas[i];
        }
    return s;
}
void output(int *mas)
{
    int i;
    for (i = 0; i < n; i++){
        cout << mas[i] << "  ";
    }
    cout << endl << "Minimal element of array:  " << minel(mas) << endl << "Multiplication result:  " << poselsum(mas)*minel(mas);
}
