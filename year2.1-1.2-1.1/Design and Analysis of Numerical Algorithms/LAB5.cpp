#include <iostream>
#include <algorithm>

using namespace std;

struct STUDENT
{
    char s_n_i[20];
    int numb;
    int progress[5];
};

void Sort(double * avg, STUDENT *group);

int main()
{
    int n;
    bool ind0(false);
    bool ind;
    cout << "Enter amount of students:  ";
    cin >> n;
    STUDENT *group = new STUDENT [n];
    for (int i(0); i < n; i++)
    {
        cout << "Enter surname and initials of student:  ";
        cin >> group[i].s_n_i;
        cout << "Enter number of group:  ";
        cin >> group[i].numb;
        cout << "Enter progress of student:  ";
        for (int j(0); j < 5; j++)
        {
            cin >> group[i].progress[j];
        }
    }
    double *avg = new double [5];
    for (int i(0); i < 5; i++)
    {
        *(avg + i) = 0;
        for (int j(0); j < 5; j++)
        {
            *(avg + i) += group[i].progress[j];
        }
        *(avg + i) = *(avg + i)/5;
    }
    Sort(avg, group);
    cout << "|----------|------------|" << endl;
    cout << "|   Name   |Group number|" << endl;
    cout << "|----------|------------|" << endl;
    for (int i(0); i < n; i++)
    {
        ind = false;
        for (int j(0); j < 5; j++)
        {
            if(group[i].progress[j] == 4  || group[i].progress[j] == 5)
            {
                ind = true;
                break;
            }
        }
        if(ind)
        {
            cout << "|";
            cout.width(10);
            cout << group[i].s_n_i;
            cout << "|";
            cout.width(12);
            cout << group[i].numb  << "|" << endl;
            ind0 = true;
        }
    }
    cout << "|----------|------------|" << endl;
    if (!ind0)
    {
        cout << "All has marks < 4" << endl;
    }
    return 0;
}

void Sort(double* arr, STUDENT *group)
{
	for(int i = 0; i < 5 - 1; i++)
    {
        for(int j = 0; j < 5 - 1; j++)
        {
            if (*(arr + j + 1) < *(arr + j))
            {
                swap(*(arr + j + 1),*(arr + j));
                STUDENT temp = group[j + 1];
                group[j + 1] = group[j];
                group[j] = temp;
            }
        }
    }
}

