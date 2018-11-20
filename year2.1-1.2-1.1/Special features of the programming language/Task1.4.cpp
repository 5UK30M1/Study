//Дан массив целых чисел. Проверить, есть ли в нем одинаковые элементы
#include <iostream>
#include <time.h>
#include <stdlib.h>
#define N 100

using namespace std;
int n;
void randfilling(int *mas);//Заполнение масива
void output(int *mas);//Вывод результата
bool sameels(int *mas);//Поиск одинаковых элементов
int main()
{
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
        mas[i] = rand () % 20;
    }
}
void output(int *mas)
{
    int i;
    for (i = 0; i < n; i++)
        cout << mas[i] << "  ";
    if( sameels(mas) ) {
        cout << endl << "Array has same elements" <<endl;
    }
    else  {
        cout << endl << "Array has not same elements" <<endl;
    }
}
bool sameels(int *mas)
{
    int i , j;
    for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j++){
            if (mas[i] == mas[j]) {
                return true;
            }
        }
    }
    return false;
}
