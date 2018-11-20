#include<iostream>
#include<conio.h>
#include<ctime>
#include<stdlib.h>

using namespace std;

void insertionSort(int *mas, int n, int *index)
{
	int tmp, i,tmpi;
	for (int j = 1; j < n; j++)
	{
		tmp = mas[j];
		tmpi = index[j];
		for (i = j - 1; (i >= 0) && (mas[i] > tmp); i--)
		{
			mas[i + 1] = mas[i];
			index[i + 1] = index[i];
		}
		mas[i + 1] = tmp;
		index[i + 1] = tmpi;
	}
}

int main()
{
	int n;
	cout << "Enter size of matrix: ";
	cin >> n;
	int **arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}
	int *mas = new int [n] {0};
	int *index = new int [n];
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(arr + i) + j) = rand() % 10;
		}
		index[i] = i;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << *(*(arr + i) + j)<<" ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mas[i] += *(*(arr + i) + j);
		}
	}
	cout << endl;
	cout << "Sorted array: "<<endl;
	insertionSort(mas, n, index);
	for (int i = 0; i < n; i++)
    {
		cout << "mas[" << index[i] << "]"<< mas[i] <<endl;
    }
	return 0;

}
