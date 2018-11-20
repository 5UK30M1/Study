#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


void output (int *arr, int n);
void outsertel (int *newarr, int *arr, int &n);

int main()
{
    int n;
    cout << "Enter size of array" << endl;
    cin >> n;
    int *arr = new int [n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        *(arr + i) = rand() % 10;
    }
    output (arr,n);
    int *newarr = new int [n-1];
    outsertel(newarr,arr,n);
    output (newarr,n);
    return 0;
}

void output (int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout.width(4);
        cout << arr[i];
    }
    cout << endl;
}

void outsertel (int *newarr, int *arr, int &n)
{
    int k;
    cout << "Choose element to delete(index):" << endl;
    cin >> k;
    for (int i = 0; i < k-1; i++)
    {
        newarr[i] = arr[i];
    }
    for (int i = k; i < n-1; i++)
    {
        newarr[i] = arr[i+1];
    }
    delete[] arr;
    n--;
}
