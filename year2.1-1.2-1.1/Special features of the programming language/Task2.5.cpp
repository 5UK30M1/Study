#include <iostream>
#include <stdio.h>
#define eps 1e-16

using namespace std;

int main()
{
    double x = -5;
    double h = 0.5;
    double x2 = 5;
    int i = 0;
    printf("|----------------|\n");
    printf("|   x   |Function|\n");
    printf("|-------|--------|\n");
    while (x <= x2 + 1e-6 ){
        printf("| %5.2lf |%8.5lf", x, 5 - ( x * x ) / 2);
        x += h;
        i++;
        cout << "|" << endl;
    }
    printf("|----------------|\n");
}

