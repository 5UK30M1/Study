#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>

#define M_PI		3.14159265358979323846

using namespace std;

class ELIPSE
{
    char *name;
    double a;
    double b;
    double x;
    double y;
    double S;
public:
    ELIPSE(char *name, double a, double b, double x, double y, int n);
    ELIPSE();
    ELIPSE(const ELIPSE&);
};

ELIPSE::ELIPSE(char *name, double a, double b, double x, double y, int n)
{
    ELIPSE::name = new char[n];
    ELIPSE::a = a;
    ELIPSE::b = b;
    ELIPSE::x = x;
    ELIPSE::y = y;
    strcpy(ELIPSE::name, name);
    ELIPSE::S = M_PI * a * b;
}

ELIPSE::ELIPSE()
{
    ELIPSE::name = "ABC";
    ELIPSE::a = 10;
    ELIPSE::b = 8;
    ELIPSE::x = 0;
    ELIPSE::y = 0;
    ELIPSE::S = M_PI * a * b;
}

ELIPSE::ELIPSE(const ELIPSE &TEMP)
{
    *this = TEMP;
}

ELIPSE initialize ()
{
        double a,b,x,y;
        string temp;
        cout << "Enter name of elipse: ";
        cin >> temp;

        int n = strlen(temp.c_str());
        char *name = new char [n];
        strcpy(name, temp.c_str());

        cout << endl;
        cout << "Enter radius 'a': ";
        scanf("%lf", &a);
        cout << endl;
        cout << "Enter radius 'b': ";
        scanf("%lf", &b);
        cout << endl;
        cout << "Enter coordinate 'x': ";
        scanf("%lf", &x);
        cout << endl;
        cout << "Enter coordinate 'y': ";
        scanf("%lf", &y);
        cout << endl;
        ELIPSE ABC2(name,a,b,x,y,n);
        return ABC2;
}

int main()
{
    int ind;
    ELIPSE ABC1();
    ELIPSE ABC2();
    ELIPSE ABC3(const ELIPSE ABC1);
    return 0;
  /*  printf("Choose type of initialization:\n1-Default;\n2-Entering characteristics of object;\n3-Copy another object.\n");
    scanf("%d",&ind);
    switch(ind)
    {
        case 1: ELIPSE ABC1();break;
        case 2: ELIPSE ABC2();ABC2 = initialize();break;
        case 3: ELIPSE ABC3(temp);break;
        default: return 0;
    }*/


}
