#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sorts.h"

using namespace std;

void randfilling (int *arr ,int n);
void output(int *arr, int n);

int main()
{
    int n,ind;
    clock_t c;
    cout << "Enter size of array:" << endl;
    cin >> n;
    cout << "Creating dynamic array..." << endl;
    int *arr = new int [n];
    cout << "Completed!" << endl;
    cout << "Randomly filling array..." << endl;
    randfilling(arr, n);
    cout << "Completed!" << endl;
    cout << "Array elements:" << endl;
    output(arr, n);
    cout << endl;
    cout << "Choose sort type:(1-SelectSort;2-BubbleSort;3-InsertSort;4-ShakerSort;5-QuickSort;6-ShellSort;7-GnomeSort;)" << endl;
    cin >> ind;
    cout << "Sorting..." << endl;
    c = clock();
    switch(ind)
    {
        case 1: selectSort(arr, n);break;
        case 2: bubbleSort(arr, n);break;
        case 3: insertSort(arr, n);break;
        case 4: shakerSort(arr, n);break;
        case 5: quickSort(arr, 0, n - 1);break;
        case 6: shellSort(arr, n);break;
        case 7: gnomeSort(arr, n);break;
    }
    cout << "Completed!" << endl;
    cout << "Clocks " << clock()- c << "  ms" << endl;
    cout << "Array elements:" << endl;
    output(arr, n);
    cout << endl;
    return 0;
}

void randfilling (int *arr ,int n)
{
    srand (time(0));
    for (int i = 0; i < n; i++)
    {
        *(arr + i) = rand() % 101 - 50;
    }
}

void output(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout.width(5);
        cout << arr[i];
    }
}
