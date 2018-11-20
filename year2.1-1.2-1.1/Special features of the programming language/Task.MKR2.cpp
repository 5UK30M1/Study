#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void funcright (int *arr, int n);
void funcleft (int *arr, int n);
void output (int *arr, int n);

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
    cout << "Choose direction(1-right,0-left)" << endl;
    bool ind;
    cin >> ind;
    if(ind)
    {
        funcright(arr,n);
    }
    else
    {
        funcleft(arr,n);
    }
    output (arr,n);
    return 0;
}

void funcleft (int *arr, int n)
{
    int k,j,temp;
    cout << "Enter pull range " << endl;
    cin >> k;
    for (int j = 0; j < k; j++)
    {
        temp=*arr;
        for (int i = 0; i < n; i++)
        {
            arr[i]=arr[i+1];
        }
        *(arr + n - 1)=temp;
    }
}

void funcright (int *arr, int n)
{
    int k,j,temp;
    cout << "Enter pull range " << endl;
    cin >> k;
    for (int j = 0; j < k; j++)
    {
        temp=*(arr + n - 1);
        for (int i = n-1; i >= 0; i--)
        {
            arr[i+1]=arr[i];
        }
        *arr=temp;
    }
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
