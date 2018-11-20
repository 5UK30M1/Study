//Определить количество элементов в заданном массиве, отличающихся от минимального на 5.
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;
int n;
void randfilling(int *mas);//Заполнение масива
int minel(int *mas);//Поиск минимального элемента
int numb(int *mas,int mmin);//Поиск числа оличающего от минимальго элемента на 5
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
    for (i = 0; i < n; i++)
        mas[i] = rand () % 20;
}

int minel(int *mas)
{
    int mmin,i;
    mmin = mas[0];
    for (i = 1; i < n; i++)
        if(mmin > mas[i]){
            mmin = mas[i];
        }
    return mmin;
}

int numb(int *mas)
{
    int i;
    int k = 0;
    for (i = 0; i < n; i++)
        if(mas[i] == minel(mas) + 5) {
            k++;
        }
    return k;
}

void output(int *mas)
{
    int i;
    for (i = 0; i < n; i++)
        cout << mas[i] << "  ";
    cout << endl << "Minimal element of array:  " << minel(mas) << endl << "Number of task elements:  " << numb(mas);
}
