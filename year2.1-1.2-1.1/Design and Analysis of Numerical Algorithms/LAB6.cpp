#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

void input (char *str, int &i);
void output (char *str, int n, int i);

int main()
{
    char str[50];
    int i = 0;
    int j = 0;
    cout << "Enter string" << endl;
    input(str,i);
    cout << endl << endl;
    while (!isspace(str[j]))
    {
        j++;
    }
    output(str,i,j + 1);
    return 0;
}

void input (char *str, int &i)
{
    char symb;
    while ((symb = getchar()) != '\n')
    {
          str[i] = symb;
          i++;
    }
}

void output (char *str, int n, int i)
{
    putchar(str[i]);
    if (i < n && !isspace(str[i+1]))
    {
        output(str,n,i + 1);
    }
    else
    {
        cout << endl << "-----------------------------------------------" << endl;
    }
    i--;
    putchar(str[i+1]);
}
