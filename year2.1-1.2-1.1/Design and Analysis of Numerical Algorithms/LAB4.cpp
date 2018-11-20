#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void randfilling(int *arr, int N);
void output (int *arr, int N, int i);

int main()
{
    int N;
    cout << "Enter size of array:" << endl;
    cin >> N;
    int *arr = new int [N];
    randfilling(arr, N);
    cout << "Decline" << endl;
    output(arr, N , 0);

    return 0;
}
void randfilling(int *arr, int N)
{
    int i;
    srand (time(0));
    for (i = 0; i < N; i++){
        arr[i] = rand () % 20 - 10;
    }
}

void output (int *arr, int N, int i)
{
    if (i < N)
    {
        if (*(arr+i) >= 0)
        {
            cout << *(arr+i) << "  ";
        }
        output(arr, N , i + 1);
    }
    else
    {
        cout << endl << endl << "Uplift" << endl;
    }
    i--;
    if (*(arr+i) < 0)
    {
        cout << *(arr+i) << "  ";
    }
}
